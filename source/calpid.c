/* 
MIT License

Copyright (c) 2017 Tim Slator

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


/*---------------------------------------------------------------------------------------------------
   Description: This module provides the implementation for calibrating the PID.
 *-------------------------------------------------------------------------------------------------*/    

/*---------------------------------------------------------------------------------------------------
 * Includes
 *-------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "config.h"
#include "calpid.h"
#include "cal.h"
#include "serial.h"
#include "nvstore.h"
#include "pid.h"
#include "leftpid.h"
#include "rightpid.h"
#include "utils.h"
#include "encoder.h"
#include "time.h"
#include "motor.h"
#include "debug.h"
#include "control.h"
#include "odom.h"

/*---------------------------------------------------------------------------------------------------
 * Includes
 *-------------------------------------------------------------------------------------------------*/
#define STEP_VELOCITY_PERCENT  (0.8)    // 80% of maximum velocity
#define MAX_NUM_VELOCITIES     (7)

/*---------------------------------------------------------------------------------------------------
 * Variables
 *-------------------------------------------------------------------------------------------------*/
static uint32 start_time;

static CAL_PID_PARAMS left_pid_params = {"left", PID_TYPE_LEFT, DIR_FORWARD, 3000};
static CAL_PID_PARAMS right_pid_params = {"right", PID_TYPE_RIGHT, DIR_FORWARD, 3000};

static uint8 Init(CAL_STAGE_TYPE stage, void *params);
static uint8 Start(CAL_STAGE_TYPE stage, void *params);
static uint8 Update(CAL_STAGE_TYPE stage, void *params);
static uint8 Stop(CAL_STAGE_TYPE stage, void *params);
static uint8 Results(CAL_STAGE_TYPE stage, void *params);

static CALIBRATION_TYPE left_pid_calibration = {CAL_INIT_STATE,
                                                CAL_CALIBRATE_STAGE,
                                                &left_pid_params,
                                                Init,
                                                Start,
                                                Update,
                                                Stop,
                                                Results};

static CALIBRATION_TYPE right_pid_calibration = {CAL_INIT_STATE,
                                                 CAL_CALIBRATE_STAGE,
                                                 &right_pid_params,
                                                 Init,
                                                 Start,
                                                 Update,
                                                 Stop,
                                                 Results};

static CALIBRATION_TYPE left_pid_validation = {CAL_INIT_STATE,
                                               CAL_VALIDATE_STAGE,
                                                &left_pid_params,
                                                Init,
                                                Start,
                                                Update,
                                                Stop,
                                                Results};

static CALIBRATION_TYPE right_pid_validation = {CAL_INIT_STATE,
                                                 CAL_VALIDATE_STAGE,
                                                 &right_pid_params,
                                                 Init,
                                                 Start,
                                                 Update,
                                                 Stop,
                                                 Results};

static float val_fwd_cps[MAX_NUM_VELOCITIES] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
static float val_bwd_cps[MAX_NUM_VELOCITIES] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
static uint8 vel_index = 0;


static float max_cps;

/*---------------------------------------------------------------------------------------------------
 * Functions
 *-------------------------------------------------------------------------------------------------*/

static void Val_CalcTriangularProfile(CAL_PID_PARAMS *params, float low_percent, float high_percent, float *val_fwd_cps)
{
    float start;
    float stop;
    int ii;
    
    start = 0;
    stop = 0;

    if (params->direction == DIR_FORWARD)
    {
        start = (float) min(p_cal_eeprom->left_motor_fwd.cps_min, p_cal_eeprom->right_motor_fwd.cps_min);
        stop = (float) min(p_cal_eeprom->left_motor_fwd.cps_max, p_cal_eeprom->right_motor_fwd.cps_max);
    }
    else if (params->direction == DIR_BACKWARD)
    {
        start = (float) min(p_cal_eeprom->left_motor_bwd.cps_min, p_cal_eeprom->right_motor_bwd.cps_min);
        stop = (float) min(p_cal_eeprom->left_motor_bwd.cps_max, p_cal_eeprom->right_motor_bwd.cps_max);
    }

    stop = min(stop, (float) min(LEFTPID_MAX, RIGHTPID_MAX));
    start = low_percent * stop;
    stop = high_percent * stop;
    
    CalcTriangularProfile(MAX_NUM_VELOCITIES, start, stop, val_fwd_cps);
    for (ii = 0; ii < MAX_NUM_VELOCITIES; ++ii)
    {
        Ser_PutStringFormat("%f, ", val_fwd_cps[ii]);
    }
    Ser_PutString("\r\n");
}

/*---------------------------------------------------------------------------------------------------
 * Name: StoreLeftGains/StoreRightGains
 * Description: Stores the specified gain values into the EEPROM for the left PID. 
 * Parameters: gains - array of float values corresponding to Kp, Ki, Kd.
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
static void StoreLeftGains(float *gains)
{
    Nvstore_WriteFloat(gains[0], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->left_gains.kp));
    Nvstore_WriteFloat(gains[1], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->left_gains.ki));
    Nvstore_WriteFloat(gains[2], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->left_gains.kd));
    Nvstore_WriteFloat(gains[3], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->left_gains.kf));
}

static void StoreRightGains(float *gains)
{
    Nvstore_WriteFloat(gains[0], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->right_gains.kp));
    Nvstore_WriteFloat(gains[1], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->right_gains.ki));
    Nvstore_WriteFloat(gains[2], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->right_gains.kd));
    Nvstore_WriteFloat(gains[3], (uint16) NVSTORE_CAL_EEPROM_ADDR_TO_OFFSET(&p_cal_eeprom->right_gains.kf));
}

/*---------------------------------------------------------------------------------------------------
 * Name: GetStepVelocity
 * Description: Calculates a step velocity at the percent based on the calibration motor values. 
 * Parameters: None
 * Return: float - velocity (meter/second)
 * 
 *-------------------------------------------------------------------------------------------------*/
static void CalcMaxCps()
/* The step input velocity is 80% of maximum wheel velocity.
   Maximum wheel velocity is determined considering two factors:
        1. the maximum left/right PID value (derived from the theoretical maximum)
        2. the maximum calibrated velocity of each wheel
   The minimum value of the above is the basis for determining the step input velocity.
 */
{
    int16 left_fwd_max;
    int16 left_bwd_max;
    int16 right_fwd_max;
    int16 right_bwd_max;
    int16 left_max;
    int16 right_max;
    int16 max_leftright_cps;
    int16 max_leftright_pid;

    left_fwd_max = abs(p_cal_eeprom->left_motor_fwd.cps_max);
    left_bwd_max = abs(p_cal_eeprom->left_motor_bwd.cps_min);
    right_fwd_max = abs(p_cal_eeprom->right_motor_fwd.cps_max);
    right_bwd_max = abs(p_cal_eeprom->right_motor_bwd.cps_min);
    
    left_max = min(left_fwd_max, left_bwd_max);
    right_max = min(right_fwd_max, right_bwd_max);
    
    max_leftright_cps = min(left_max, right_max);
    max_leftright_pid = min(LEFTPID_MAX, RIGHTPID_MAX);
    
    max_cps = min(max_leftright_cps, max_leftright_pid);

}

/*---------------------------------------------------------------------------------------------------
 * Name: ResetPidValidationVelocity
 * Description: Resets the index for the validation velocities. 
 * Parameters: None
 * Return: float - velocity (meter/second)
 * 
 *-------------------------------------------------------------------------------------------------*/
static void ResetPidValidationVelocity()
{
    vel_index = 0;
}

/*---------------------------------------------------------------------------------------------------
 * Name: GetNextValidationVelocity
 * Description: Returns the next validation velocity from the array. 
 * Parameters: dir - specifies whether the validation is in the forward or backward direction
 * Return: float - velocity (meter/second)
 * 
 *-------------------------------------------------------------------------------------------------*/
static float GetNextValidationVelocity(DIR_TYPE dir)
{
    float value;

    switch( dir )
    {
        case DIR_FORWARD:
            value = val_fwd_cps[vel_index];
            break;
    
        case DIR_BACKWARD:
            value = val_bwd_cps[vel_index];
            break;

        default:
            value = 0;
            break;
    }

    vel_index++;

    /* Note: Convert CPS to MPS */
    return value;// * WHEEL_METER_PER_COUNT;
}

/*---------------------------------------------------------------------------------------------------
 * Name: SetNextValidationVelocity
 * Description: Gets and sets the next validation velocity.
 * Parameters: p_pid_params - pointer to PID params
 * Return: 0 if all the velocities have been used; otherwise 1.
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 SetNextValidationVelocity(CAL_PID_PARAMS *p_pid_params)
{
    float velocity = GetNextValidationVelocity(p_pid_params->direction);
    switch (p_pid_params->pid_type)
    {
        case PID_TYPE_LEFT:
            Cal_SetLeftRightVelocity(velocity, 0);
            break;

        case PID_TYPE_RIGHT:
            Cal_SetLeftRightVelocity(0, velocity);
            break;
    }
    
    Ser_PutStringFormat("Speed: %.2f\r\n", velocity);
    
    return vel_index <= MAX_NUM_VELOCITIES ? 1 : 0;
}

/*----------------------------------------------------------------------------------------------------------------------
 * Calibration Interface Routines
 *---------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
 * Name: Init
 * Description: Calibration/Validation interface Init function.  Performs initialization for Linear 
 *              Validation.
 * Parameters: stage - the calibration/validation stage 
 *             params - PID calibration/validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Init(CAL_STAGE_TYPE stage, void *params)
{
    CAL_PID_PARAMS *p_pid_params = (CAL_PID_PARAMS *)params;
    
    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:

            if (!Cal_GetCalibrationStatusBit(CAL_MOTOR_BIT))
            {
                Ser_PutStringFormat("Motor calibration not performed (%02x)\r\n", p_cal_eeprom->status);
                return CAL_COMPLETE;
            }

            Ser_PutStringFormat("\r\n%s PID calibration\r\n", p_pid_params->name);

            Cal_ClearCalibrationStatusBit(CAL_PID_BIT);
            Cal_SetLeftRightVelocity(0, 0);
            Pid_SetLeftRightTarget(Cal_LeftTarget, Cal_RightTarget);

            Debug_Store();

            switch (p_pid_params->pid_type)
            {
                case PID_TYPE_LEFT:
                    Debug_Enable(DEBUG_LEFT_PID_ENABLE_BIT);
                    break;
                    
                case PID_TYPE_RIGHT:
                    Debug_Enable(DEBUG_RIGHT_PID_ENABLE_BIT);
                    break;
            }        
            break;
            
        case CAL_VALIDATE_STAGE:
            Ser_PutStringFormat("\r\n%s PID validation\r\n", p_pid_params->name);
            
            Debug_Store();

            Val_CalcTriangularProfile(p_pid_params, 0.2, 0.8, &val_fwd_cps[0]);
            
            Cal_SetLeftRightVelocity(0, 0);
            Pid_SetLeftRightTarget(Cal_LeftTarget, Cal_RightTarget);
            ResetPidValidationVelocity();

            switch (p_pid_params->pid_type)
            {
                case PID_TYPE_LEFT:
                    Debug_Enable(DEBUG_LEFT_PID_ENABLE_BIT);
                    break;
                
                case PID_TYPE_RIGHT:
                    Debug_Enable(DEBUG_RIGHT_PID_ENABLE_BIT);
                    break;
            }
            
            break;
    }

    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Start
 * Description: Calibration/Validation interface Start function.  Starts PID Calibration/Validation.
 * Parameters: stage - the calibration/validation stage 
 *             params - PID validation parameters. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Start(CAL_STAGE_TYPE stage, void *params)
{
    float gains[4];
    CAL_PID_PARAMS *p_pid_params = (CAL_PID_PARAMS *) params;
    
    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:
            Ser_PutString("\r\nEnter proportional gain: ");
            gains[0] = Cal_ReadResponse();
            Ser_PutString("\r\nEnter integral gain: ");
            gains[1] = Cal_ReadResponse();
            Ser_PutString("\r\nEnter derivative gain: ");
            gains[2] = Cal_ReadResponse();
            Ser_PutString("\r\nEnter feedforward gain: ");
            gains[3] = Cal_ReadResponse();
            Ser_PutString("\r\n");
            
            Pid_Enable(TRUE, TRUE, FALSE);
            Encoder_Reset();
            Pid_Reset();
            Odom_Reset();
            
            float step_velocity = max_cps * STEP_VELOCITY_PERCENT;

            switch (p_pid_params->pid_type)
            {
                case PID_TYPE_LEFT:
                    LeftPid_SetGains(gains[0], gains[1], gains[2], gains[3]);
                    Cal_SetLeftRightVelocity(step_velocity, 0);
                    break;
                    
                case PID_TYPE_RIGHT:
                    RightPid_SetGains(gains[0], gains[1], gains[2], gains[3]);
                    Cal_SetLeftRightVelocity(0, step_velocity);
                    break;                    
            }
                    
            Ser_PutString("\r\nCalibrating\r\n");
            start_time = millis();
            
            break;

            
        case CAL_VALIDATE_STAGE:
            Pid_Enable(TRUE, TRUE, FALSE);            
            Encoder_Reset();
            Pid_Reset();
            Odom_Reset();

            Ser_PutString("\r\nValidating\r\n");
            start_time = millis();
            
            SetNextValidationVelocity(p_pid_params);

            break;
    }

    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Update
 * Description: Calibration/Validation interface Update function.  Called periodically to evaluate 
 *              the termination condition.
 * Parameters: stage - the calibration/validation stage 
 *             params - PID calibration/validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK, CAL_COMPLETE
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Update(CAL_STAGE_TYPE stage, void *params)
{
    CAL_PID_PARAMS * p_pid_params = (CAL_PID_PARAMS *) params;
        
    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:
            if (millis() - start_time < p_pid_params->run_time)
            {
                return CAL_OK;
            }
            break;

        case CAL_VALIDATE_STAGE:
            /* Assume an array of validation velocities that we want to run through.
               We use update to measure the time and advance through the array
             */
            if (millis() - start_time < p_pid_params->run_time)
            {
                return CAL_OK;    
            }
            start_time = millis();
            uint8 result = SetNextValidationVelocity(p_pid_params);
            if (!result)
            {
                return CAL_COMPLETE;
            }
            
            return CAL_OK;
            break;
    }

    return CAL_COMPLETE;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Stop
 * Description: Calibration/Validation interface Stop function.  Called to stop validation.
 * Parameters: stage - the calibration/validation stage 
 *             params - PID calibration/validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Stop(CAL_STAGE_TYPE stage, void *params)
{
    CAL_PID_PARAMS *p_pid_params = (CAL_PID_PARAMS *)params;
    float gains[4];

    Cal_SetLeftRightVelocity(0, 0);

    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:

            switch (p_pid_params->pid_type)
            {
                case PID_TYPE_LEFT:
                    LeftPid_GetGains(&gains[0], &gains[1], &gains[2], &gains[3]);
                    StoreLeftGains(gains);
                    break;
                    
                case PID_TYPE_RIGHT:
                    RightPid_GetGains(&gains[0], &gains[1], &gains[2], &gains[3]);
                    StoreRightGains(gains);
                    break;
            }
            Cal_SetCalibrationStatusBit(CAL_PID_BIT);

            Pid_RestoreLeftRightTarget();
            Ser_PutStringFormat("\r\n%s PID calibration complete\r\n", p_pid_params->name);
            Debug_Restore();    
            break;
            
        case CAL_VALIDATE_STAGE:
            Ser_PutStringFormat("\r\n%s PID validation complete\r\n", p_pid_params->name);
            Debug_Restore();    
            break;
    }
            
    return CAL_OK;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Results
 * Description: Calibration/Validation interface Results function.  Called to display calibration/ 
 *              validation results. 
 * Parameters: stage - the calibration/validation stage 
 *             params - PID calibration/validation parameters, e.g. direction, run time, etc. 
 * Return: uint8 - CAL_OK
 * 
 *-------------------------------------------------------------------------------------------------*/
static uint8 Results(CAL_STAGE_TYPE stage, void *params)
{
    float gains[4];
    CAL_PID_PARAMS *p_pid_params = (CAL_PID_PARAMS *)params;
    
    switch (stage)
    {
        case CAL_CALIBRATE_STAGE:

            Ser_PutString("\r\nPrinting PID calibration results\r\n");
    
            switch (p_pid_params->pid_type)
            {
                case PID_TYPE_LEFT:
                    LeftPid_GetGains(&gains[0], &gains[1], &gains[2], &gains[3]);
                    Cal_PrintGains("Left PID", gains);
                    break;
                
                case PID_TYPE_RIGHT:
                    RightPid_GetGains(&gains[0], &gains[1], &gains[2], &gains[3]);
                    Cal_PrintGains("Right PID", gains);
                    break;
            }
            break;
            
        case CAL_VALIDATE_STAGE:
            Ser_PutString("\r\nPrinting PID validation results\r\n");
            break;
            
        default:
            Ser_PutStringFormat("\r\nInvalid stage: %d", stage);
            break;
    }
        
    return CAL_OK;
}

/*----------------------------------------------------------------------------------------------------------------------
 * Module Interface Routines
 *---------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
 * Name: CalPid_Init
 * Description: Initializes the PID calibration module 
 * Parameters: None 
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void CalPid_Init()
{
    CalPid_LeftCalibration = &left_pid_calibration;
    CalPid_RightCalibration = &right_pid_calibration;
    CalPid_LeftValidation = &left_pid_validation;
    CalPid_RightValidation = &right_pid_validation;

    max_cps = 0.0;
}

void CalPid_Start()
{
    CalcMaxCps();    
}

/*-------------------------------------------------------------------------------*/
/* [] END OF FILE */