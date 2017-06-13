/* ========================================
 *
 * Copyright Earl Software, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/*---------------------------------------------------------------------------------------------------
 * Description
 *-------------------------------------------------------------------------------------------------*/
// Add a description of the module

/* The purpose of this module is to handle changes in control of the system.
 */



/*---------------------------------------------------------------------------------------------------
 * Includes
 *-------------------------------------------------------------------------------------------------*/
#include "control.h"
#include "motor.h"
#include "cal.h"
#include "time.h"
#include "utils.h"
#include "odom.h"
#include "debug.h"
#include "config.h"
#include "ccif.h"


/*---------------------------------------------------------------------------------------------------
 * Constants
 *-------------------------------------------------------------------------------------------------*/
#define MAX_CMD_VELOCITY_TIMEOUT (2000)


/*---------------------------------------------------------------------------------------------------
 * Types
 *-------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
 * Variables
 *-------------------------------------------------------------------------------------------------*/
static COMMAND_FUNC_TYPE control_cmd_velocity;
static float left_cmd_velocity;
static float right_cmd_velocity;
static uint8 debug_override;

    
/*---------------------------------------------------------------------------------------------------
 * Name: Control_Init
 * Description: Performs initialization of module variables.
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/ 
void Control_Init()
{
    control_cmd_velocity = ReadCmdVelocity;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_Start
 * Description: Performs actions to activate objects that operate independently of this module.
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/ 
void Control_Start()
{   
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_Update
 * Description: Reads and evaluates the current control state as received from the I2C module.
 *              Operations include stopping the motors, reseting odometry, clearing calibration,
 *              enabling/disabling debug and monitoring safety timer.
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/ 
void Control_Update()
{
    uint32 timeout;
    uint16 device_control;
    uint16 debug_control;
    
    device_control = ReadDeviceControl();
    if (device_control & CONTROL_DISABLE_MOTOR_BIT)
    {
        Motor_Stop();
    }
    
    debug_control = ReadDebugControl();
    Debug_Update(debug_control);
    
    if (device_control & CONTROL_CLEAR_ODOMETRY_BIT)
    {
        Odom_Reset();
    }
    
    if (device_control & CONTROL_CLEAR_CALIBRATION)
    {
        Cal_Clear();
    }

    /* What is the purpose of this? */
    if (!debug_override)
    {
        ReadDebugControl();
    }
    
    control_cmd_velocity(&left_cmd_velocity, &right_cmd_velocity, &timeout);
    
    // Used to override I2C commands (debug)
    //left_cmd_velocity = 0;
    //right_cmd_velocity = 0;
    //UniToDiff(0.150, 0, &left_cmd_velocity, &right_cmd_velocity);
        
    if (timeout > MAX_CMD_VELOCITY_TIMEOUT)
    {
        left_cmd_velocity = 0;
        right_cmd_velocity = 0;
    }
    else
    {
        left_cmd_velocity = max(MIN_LEFT_VELOCITY, min(left_cmd_velocity, MAX_LEFT_VELOCITY));
        right_cmd_velocity = max(MIN_RIGHT_VELOCITY, min(right_cmd_velocity, MAX_RIGHT_VELOCITY));
    }
    left_cmd_velocity = max(MIN_LEFT_VELOCITY, min(left_cmd_velocity, MAX_LEFT_VELOCITY));
    right_cmd_velocity = max(MIN_RIGHT_VELOCITY, min(right_cmd_velocity, MAX_RIGHT_VELOCITY));
    
    
    
    /* Here seems like a reasonable place to evaluate safety, e.g., can we execute the requested speed change safely
       without running into something or falling into a hole (or down stairs).
    
       The only thing in consideration at the moment is cliff sensors which are IR sensors which point at a 45 degree
       angle downward.  These will be connected to a voltage comparator and will issue an interrupt if there is a trigger.
    
       The main loop typically runs no longer than about 40ms, so if that is sufficient to detect and stop the robot
       then checking safety here seems like a good solution.  Something like:
    
       if (IsSafe())
       {
           UpdateSpeed(); 
       }

       Safety should also be proactive and stop the robot when an unsafe condition occurs.  The motors will stop after
       2 seconds but it might be better to immediately zero out the robot velocity (in the i2c module)
    
       Along these lines, hardware may be good way to handle safety concerns.  Hardware can be used to monitor actual
       inputs and generate an interrupt that can then make software calls, e.g., stop the motor and update i2c interface.
    
       It was suggested that a voltage comparator could be used to monitor voltage on a cliff sensor and directly 
       disable the PWM if the distance (voltage) exceeds a threshold - no software required.
    
    */    
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_SetCommandVelocityFunc
 * Description: Method for setting the function from which left/right velocity values are obtained.
 *              The purpose of this function is to allow calibration to override the setting so that
 *              left/right velocity can be injected from the calibration modules.  The default method 
 *              is I2c_ReadCmdVelocity.  
 * Parameters: cmd - a pointer to a command function type
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/ 
void Control_SetCommandVelocityFunc(COMMAND_FUNC_TYPE cmd)
{
    control_cmd_velocity = cmd;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_RestoreCommandVelocityFunc
 * Description: Method for restoring the default function for obtaining left/right velocity values  
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/ 
void Control_RestoreCommandVelocityFunc()
{
    control_cmd_velocity = ReadCmdVelocity;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_LeftGetCmdVelocity
 * Description: Accessor function used to return the left commanded velocity.  
 * Parameters: None
 * Return: float
 * 
 *-------------------------------------------------------------------------------------------------*/ 
float Control_LeftGetCmdVelocity()
{
    return left_cmd_velocity;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_RightGetCmdVelocity
 * Description: Accessor function used to return the right commanded velocity.  
 * Parameters: None
 * Return: float
 * 
 *-------------------------------------------------------------------------------------------------*/ 
float Control_RightGetCmdVelocity()
{
    return right_cmd_velocity;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Control_OverrideDebug
 * Description: Function used to override the debug mask.  Used primarily during calibration.
 * Parameters: override : boolean - used to disable the debug mask settings specified via I2C.
 * Return: float
 * 
 *-------------------------------------------------------------------------------------------------*/ 
void Control_OverrideDebug(uint8 override)
{
    debug_override = override;
}

void Control_SetDeviceStatusBit(uint16 bit)
{
    SetDeviceStatusBit(bit);
}

void Control_ClearDeviceStatusBit(uint16 bit)
{
    ClearDeviceStatusBit(bit);
}

void Control_SetCalibrationStatus(uint16 status)
{
    SetCalibrationStatus(status);
}

void Control_SetCalibrationStatusBit(uint16 bit)
{
    SetCalibrationStatusBit(bit);
}

void Control_ClearCalibrationStatusBit(uint16 bit)
{
    ClearCalibrationStatusBit(bit);
}

void Control_WriteOdom(float left_speed, 
                       float right_speed, 
                       float left_dist, 
                       float right_dist, 
                       float heading)
{
    WriteSpeed(left_speed, right_speed);
    WriteDistance(left_dist, right_dist);
    WriteHeading(heading);
}

void Control_UpdateHeartbeat(uint32 heartbeat)
{
    UpdateHeartbeat(heartbeat);
}

/* [] END OF FILE */
