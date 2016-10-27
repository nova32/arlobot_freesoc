#include <math.h>
#include "calang.h"
#include "odom.h"
#include "motor.h"
#include "encoder.h"
#include "pid.h"
#include "time.h"
#include "utils.h"
#include "serial.h"
#include "nvstore.h"
#include "debug.h"
#include "pwm.h"

/*---------------------------------------------------------------------------------------------------
 * Constants
 *-------------------------------------------------------------------------------------------------*/
#define ANGULAR_BIAS_ANGLE (2*PI)   // rad
#define ANGULAR_BIAS_VELOCITY (0.3) // rad/s
#define ANGULAR_MAX_TIME (10000)

/*---------------------------------------------------------------------------------------------------
 * Variables
 *-------------------------------------------------------------------------------------------------*/
static uint32 start_time;
static uint32 end_time;
static uint16 old_debug_control_enabled;

static CAL_ANG_PARAMS angular_params = {DIR_CW, 
                                        ANGULAR_MAX_TIME, 
                                        ANGULAR_BIAS_ANGLE,
                                        0.0,    // There is no linear velocity because we are rotating in place
                                        ANGULAR_BIAS_VELOCITY};

static uint8 Init(CAL_STAGE_TYPE stage, void *params);
static uint8 Start(CAL_STAGE_TYPE stage, void *params);
static uint8 Update(CAL_STAGE_TYPE stage, void *params);
static uint8 Stop(CAL_STAGE_TYPE stage, void *params);
static uint8 Results(CAL_STAGE_TYPE stage, void *params);

static CALIBRATION_TYPE angular_calibration = {CAL_INIT_STATE,
                                               CAL_CALIBRATE_STAGE,
                                               &angular_params,
                                               Init,
                                               Start,
                                               Update,
                                               Stop,
                                               Results};

/*---------------------------------------------------------------------------------------------------
 * Functions
 *-------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
 * Name: Init
 * Description: Calibration/Validation interface Init function.  Performs initialization for Angular 
 *              Calibration/Validation.
 * Parameters: stage - the calibration/validation stage 
 *             params - angular validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Init(CAL_STAGE_TYPE stage, void *params)
{
    CAL_ANG_PARAMS *p_ang_params = (CAL_ANG_PARAMS *)params;
    char banner[64];

    Cal_SetLeftRightVelocity(0, 0);
    Pid_SetLeftRightTarget(Cal_LeftTarget, Cal_RightTarget);

    old_debug_control_enabled = debug_control_enabled;

    debug_control_enabled = DEBUG_ODOM_ENABLE_BIT;

    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:
            /* Note: Do we want to support both clockwise and counter clockwise calibration?  How would the
               bias be different?  How would it be applied?
             */

            sprintf(banner, "\r\nAngular Calibration\r\n");
            Ser_PutString(banner);
            sprintf(banner, "\r\nPlace a mark on the floor corresponding to the center of one of the wheels\r\n");
            Ser_PutString(banner);

            Cal_ClearCalibrationStatusBit(CAL_ANGULAR_BIT);
            break;

        case CAL_VALIDATE_STAGE:
            /* We should support validating clockwise and counter clockwise */

            sprintf(banner, "\r\n%s Angular validation\r\n", p_ang_params->direction == DIR_CW ? "Clockwise" : "Counter Clockwise");
            Ser_PutString(banner);
            break;

        default:
            break;
    }
    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Start
 * Description: Calibration/Validation interface Start function.  Start Agnular Calibration/Validation.
 * Parameters: stage - the calibration/validation stage 
 *             params - angular validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Start(CAL_STAGE_TYPE stage, void *params)
{
    CAL_ANG_PARAMS *p_ang_params = (CAL_ANG_PARAMS *) params;
    float left;
    float right;

    Pid_Enable(TRUE);            
    Encoder_Reset();
    Pid_Reset();
    Odom_Reset();
    
    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:
            Ser_PutString("Angular Calibration Start\r\n");
            
            Ser_PutString("\r\nCalibrating ");
            Ser_PutString("\r\n");

            UniToDiff(p_ang_params->mps, p_ang_params->rps, &left, &right);
            
            Cal_SetLeftRightVelocity(left, right);
            start_time = millis();
            break;

        case CAL_VALIDATE_STAGE:
            Ser_PutString("Agnular Validation Start\r\n");
            
            Ser_PutString("\r\nValidating ");
            Ser_PutString("\r\n");
            
            UniToDiff(p_ang_params->mps, p_ang_params->rps, &left, &right);
            Cal_SetLeftRightVelocity(left, right);            
            start_time = millis();

            break;

        default:
            break;
    }
    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Update
 * Description: Calibration/Validation interface Update function.  Called periodically to evaluate 
 *              the termination condition.
 * Parameters: stage - the calibration/validation stage 
 *             params - angular validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK, CAL_COMPLETE
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Update(CAL_STAGE_TYPE stage, void *params)
{
    float heading;
    CAL_ANG_PARAMS * p_ang_params = (CAL_ANG_PARAMS *) params;

    switch (stage)
    {
        case CAL_VALIDATE_STAGE:
        case CAL_CALIBRATE_STAGE:
            if (millis() - start_time < p_ang_params->run_time)
            {
                heading = Odom_GetHeading();

                if ( abs(heading) < abs(p_ang_params->distance) )
                {
                    return CAL_OK;
                }
                end_time = millis();
                return CAL_COMPLETE;
            }
            end_time = millis();
            Ser_PutString("\r\nRun time expired\r\n");
            break;

        default:
            break;
        
    }

    return CAL_COMPLETE;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Stop
 * Description: Calibration/Validation interface Stop function.  Called to stop calibration/validation.
 * Parameters: stage - the calibration/validation stage 
 *             params - angular validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Stop(CAL_STAGE_TYPE stage, void *params)
{
    float left_dist;
    float right_dist;
    float heading;

    char left_dist_str[10];
    char right_dist_str[10];
    char heading_str[10];

    char output[64];

    CAL_ANG_PARAMS *p_ang_params = (CAL_ANG_PARAMS *)params;

    Cal_SetLeftRightVelocity(0, 0);

    left_dist = Encoder_LeftGetDist();
    right_dist = Encoder_RightGetDist();
    heading = Odom_GetHeading();

    ftoa(left_dist, left_dist_str, 3);    
    ftoa(right_dist, right_dist_str, 3);
    ftoa(heading, heading_str, 6);
    
    switch (stage)
    {
        case CAL_VALIDATE_STAGE:
            sprintf(output, "\r\n%s Angular Validation complete\r\n", p_ang_params->direction == DIR_CW ? "clockwise" : "counter clockwise");
            Ser_PutString(output);
            break;
            
        case CAL_CALIBRATE_STAGE:
            sprintf(output, "\r\nAngular Calibration complete\r\n");
            Ser_PutString(output);
            break;
            
        default:
            break;
    }

    sprintf(output, "Left Wheel Distance: %s\r\nRight Wheel Distance: %s\r\n", left_dist_str, right_dist_str);
    Ser_PutString(output);
    sprintf(output, "Heading: %s\r\n", heading_str);
    Ser_PutString(output);
    sprintf(output, "Elapsed Time: %ld\r\n", end_time - start_time);
    Ser_PutString(output);
    
    debug_control_enabled = old_debug_control_enabled;    

    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Results
 * Description: Calibration/Validation interface Results function.  Called to display calibration/validation 
 *              results. 
 * Parameters: stage - the calibration/validation stage (validation only) 
 *             params - angular validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Results(CAL_STAGE_TYPE stage, void *params)
{
    switch (stage)
    {
        case CAL_VALIDATE_STAGE:
            Ser_PutString("\r\nPrinting Angular validation results\r\n");
            /* Get the left, right and average distance traveled
                Need to capture the left, right delta distance at the start (probably 0 because odometry is reset)
                We want to see how far each wheel went and compute the error
               */
            break;

        case CAL_CALIBRATE_STAGE:
            Ser_PutString("\r\nMeasure the rotate traveled by the robot.");
            Ser_PutString("\r\nEnter the rotation (in degrees): ");
            float rot_in_degrees = Cal_ReadResponse();
            
            /* If the actual rotation is less than 360.0 then each delta is too small, i.e., lengthen delta by 360/rotation
               If the actual rotation is greater than 360.0 then each delta is too small, i.e., shorten delta by rotation/360
             */
            float bias = rot_in_degrees >= 360.0 ? bias = 360.0 / rot_in_degrees : rot_in_degrees / 360.0;

            Nvstore_WriteFloat(bias, (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->angular_bias));
            Cal_SetCalibrationStatusBit(CAL_ANGULAR_BIT);
            
        default:
            break;    
    }

    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: CalLin_Init
 * Description: Initializes the Angular calibration module 
 * Parameters: None 
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void CalAng_Init()
{
    CalAng_Calibration = &angular_calibration;
    CalAng_Validation = &angular_calibration;
}

/*-------------------------------------------------------------------------------*/
/* [] END OF FILE */
