/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_CONTROL_H
#define _MOCK_CONTROL_H

#include "control.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#pragma GCC diagnostic push
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_control_Init(void);
void mock_control_Destroy(void);
void mock_control_Verify(void);




#define Control_Init_Ignore() Control_Init_CMockIgnore()
void Control_Init_CMockIgnore(void);
#define Control_Init_Expect() Control_Init_CMockExpect(__LINE__)
void Control_Init_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_Control_Init_CALLBACK)(int cmock_num_calls);
void Control_Init_StubWithCallback(CMOCK_Control_Init_CALLBACK Callback);
#define Control_Start_Ignore() Control_Start_CMockIgnore()
void Control_Start_CMockIgnore(void);
#define Control_Start_Expect() Control_Start_CMockExpect(__LINE__)
void Control_Start_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_Control_Start_CALLBACK)(int cmock_num_calls);
void Control_Start_StubWithCallback(CMOCK_Control_Start_CALLBACK Callback);
#define Control_Update_Ignore() Control_Update_CMockIgnore()
void Control_Update_CMockIgnore(void);
#define Control_Update_Expect() Control_Update_CMockExpect(__LINE__)
void Control_Update_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_Control_Update_CALLBACK)(int cmock_num_calls);
void Control_Update_StubWithCallback(CMOCK_Control_Update_CALLBACK Callback);
#define Control_SetCommandVelocityFunc_Ignore() Control_SetCommandVelocityFunc_CMockIgnore()
void Control_SetCommandVelocityFunc_CMockIgnore(void);
#define Control_SetCommandVelocityFunc_Expect(cmd) Control_SetCommandVelocityFunc_CMockExpect(__LINE__, cmd)
void Control_SetCommandVelocityFunc_CMockExpect(UNITY_LINE_TYPE cmock_line, COMMAND_FUNC_TYPE cmd);
typedef void (* CMOCK_Control_SetCommandVelocityFunc_CALLBACK)(COMMAND_FUNC_TYPE cmd, int cmock_num_calls);
void Control_SetCommandVelocityFunc_StubWithCallback(CMOCK_Control_SetCommandVelocityFunc_CALLBACK Callback);
#define Control_RestoreCommandVelocityFunc_Ignore() Control_RestoreCommandVelocityFunc_CMockIgnore()
void Control_RestoreCommandVelocityFunc_CMockIgnore(void);
#define Control_RestoreCommandVelocityFunc_Expect() Control_RestoreCommandVelocityFunc_CMockExpect(__LINE__)
void Control_RestoreCommandVelocityFunc_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_Control_RestoreCommandVelocityFunc_CALLBACK)(int cmock_num_calls);
void Control_RestoreCommandVelocityFunc_StubWithCallback(CMOCK_Control_RestoreCommandVelocityFunc_CALLBACK Callback);
#define Control_LeftGetCmdVelocity_IgnoreAndReturn(cmock_retval) Control_LeftGetCmdVelocity_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Control_LeftGetCmdVelocity_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
#define Control_LeftGetCmdVelocity_ExpectAndReturn(cmock_retval) Control_LeftGetCmdVelocity_CMockExpectAndReturn(__LINE__, cmock_retval)
void Control_LeftGetCmdVelocity_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
typedef FLOAT (* CMOCK_Control_LeftGetCmdVelocity_CALLBACK)(int cmock_num_calls);
void Control_LeftGetCmdVelocity_StubWithCallback(CMOCK_Control_LeftGetCmdVelocity_CALLBACK Callback);
#define Control_RightGetCmdVelocity_IgnoreAndReturn(cmock_retval) Control_RightGetCmdVelocity_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Control_RightGetCmdVelocity_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
#define Control_RightGetCmdVelocity_ExpectAndReturn(cmock_retval) Control_RightGetCmdVelocity_CMockExpectAndReturn(__LINE__, cmock_retval)
void Control_RightGetCmdVelocity_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
typedef FLOAT (* CMOCK_Control_RightGetCmdVelocity_CALLBACK)(int cmock_num_calls);
void Control_RightGetCmdVelocity_StubWithCallback(CMOCK_Control_RightGetCmdVelocity_CALLBACK Callback);
#define Control_LinearGetCmdVelocity_IgnoreAndReturn(cmock_retval) Control_LinearGetCmdVelocity_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Control_LinearGetCmdVelocity_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
#define Control_LinearGetCmdVelocity_ExpectAndReturn(cmock_retval) Control_LinearGetCmdVelocity_CMockExpectAndReturn(__LINE__, cmock_retval)
void Control_LinearGetCmdVelocity_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
typedef FLOAT (* CMOCK_Control_LinearGetCmdVelocity_CALLBACK)(int cmock_num_calls);
void Control_LinearGetCmdVelocity_StubWithCallback(CMOCK_Control_LinearGetCmdVelocity_CALLBACK Callback);
#define Control_AngularGetCmdVelocity_IgnoreAndReturn(cmock_retval) Control_AngularGetCmdVelocity_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Control_AngularGetCmdVelocity_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
#define Control_AngularGetCmdVelocity_ExpectAndReturn(cmock_retval) Control_AngularGetCmdVelocity_CMockExpectAndReturn(__LINE__, cmock_retval)
void Control_AngularGetCmdVelocity_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, FLOAT cmock_to_return);
typedef FLOAT (* CMOCK_Control_AngularGetCmdVelocity_CALLBACK)(int cmock_num_calls);
void Control_AngularGetCmdVelocity_StubWithCallback(CMOCK_Control_AngularGetCmdVelocity_CALLBACK Callback);
#define Control_GetCmdVelocity_Ignore() Control_GetCmdVelocity_CMockIgnore()
void Control_GetCmdVelocity_CMockIgnore(void);
#define Control_GetCmdVelocity_Expect(linear, angular) Control_GetCmdVelocity_CMockExpect(__LINE__, linear, angular)
void Control_GetCmdVelocity_CMockExpect(UNITY_LINE_TYPE cmock_line, FLOAT* linear, FLOAT* angular);
typedef void (* CMOCK_Control_GetCmdVelocity_CALLBACK)(FLOAT* linear, FLOAT* angular, int cmock_num_calls);
void Control_GetCmdVelocity_StubWithCallback(CMOCK_Control_GetCmdVelocity_CALLBACK Callback);
#define Control_SetCmdVelocity_Ignore() Control_SetCmdVelocity_CMockIgnore()
void Control_SetCmdVelocity_CMockIgnore(void);
#define Control_SetCmdVelocity_Expect(linear, angular) Control_SetCmdVelocity_CMockExpect(__LINE__, linear, angular)
void Control_SetCmdVelocity_CMockExpect(UNITY_LINE_TYPE cmock_line, FLOAT linear, FLOAT angular);
typedef void (* CMOCK_Control_SetCmdVelocity_CALLBACK)(FLOAT linear, FLOAT angular, int cmock_num_calls);
void Control_SetCmdVelocity_StubWithCallback(CMOCK_Control_SetCmdVelocity_CALLBACK Callback);
#define Control_OverrideDebug_Ignore() Control_OverrideDebug_CMockIgnore()
void Control_OverrideDebug_CMockIgnore(void);
#define Control_OverrideDebug_Expect(override) Control_OverrideDebug_CMockExpect(__LINE__, override)
void Control_OverrideDebug_CMockExpect(UNITY_LINE_TYPE cmock_line, BOOL override);
typedef void (* CMOCK_Control_OverrideDebug_CALLBACK)(BOOL override, int cmock_num_calls);
void Control_OverrideDebug_StubWithCallback(CMOCK_Control_OverrideDebug_CALLBACK Callback);
#define Control_SetDeviceStatusBit_Ignore() Control_SetDeviceStatusBit_CMockIgnore()
void Control_SetDeviceStatusBit_CMockIgnore(void);
#define Control_SetDeviceStatusBit_Expect(bit) Control_SetDeviceStatusBit_CMockExpect(__LINE__, bit)
void Control_SetDeviceStatusBit_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT16 bit);
typedef void (* CMOCK_Control_SetDeviceStatusBit_CALLBACK)(UINT16 bit, int cmock_num_calls);
void Control_SetDeviceStatusBit_StubWithCallback(CMOCK_Control_SetDeviceStatusBit_CALLBACK Callback);
#define Control_ClearDeviceStatusBit_Ignore() Control_ClearDeviceStatusBit_CMockIgnore()
void Control_ClearDeviceStatusBit_CMockIgnore(void);
#define Control_ClearDeviceStatusBit_Expect(bit) Control_ClearDeviceStatusBit_CMockExpect(__LINE__, bit)
void Control_ClearDeviceStatusBit_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT16 bit);
typedef void (* CMOCK_Control_ClearDeviceStatusBit_CALLBACK)(UINT16 bit, int cmock_num_calls);
void Control_ClearDeviceStatusBit_StubWithCallback(CMOCK_Control_ClearDeviceStatusBit_CALLBACK Callback);
#define Control_SetCalibrationStatus_Ignore() Control_SetCalibrationStatus_CMockIgnore()
void Control_SetCalibrationStatus_CMockIgnore(void);
#define Control_SetCalibrationStatus_Expect(status) Control_SetCalibrationStatus_CMockExpect(__LINE__, status)
void Control_SetCalibrationStatus_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT16 status);
typedef void (* CMOCK_Control_SetCalibrationStatus_CALLBACK)(UINT16 status, int cmock_num_calls);
void Control_SetCalibrationStatus_StubWithCallback(CMOCK_Control_SetCalibrationStatus_CALLBACK Callback);
#define Control_SetCalibrationStatusBit_Ignore() Control_SetCalibrationStatusBit_CMockIgnore()
void Control_SetCalibrationStatusBit_CMockIgnore(void);
#define Control_SetCalibrationStatusBit_Expect(bit) Control_SetCalibrationStatusBit_CMockExpect(__LINE__, bit)
void Control_SetCalibrationStatusBit_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT16 bit);
typedef void (* CMOCK_Control_SetCalibrationStatusBit_CALLBACK)(UINT16 bit, int cmock_num_calls);
void Control_SetCalibrationStatusBit_StubWithCallback(CMOCK_Control_SetCalibrationStatusBit_CALLBACK Callback);
#define Control_ClearCalibrationStatusBit_Ignore() Control_ClearCalibrationStatusBit_CMockIgnore()
void Control_ClearCalibrationStatusBit_CMockIgnore(void);
#define Control_ClearCalibrationStatusBit_Expect(bit) Control_ClearCalibrationStatusBit_CMockExpect(__LINE__, bit)
void Control_ClearCalibrationStatusBit_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT16 bit);
typedef void (* CMOCK_Control_ClearCalibrationStatusBit_CALLBACK)(UINT16 bit, int cmock_num_calls);
void Control_ClearCalibrationStatusBit_StubWithCallback(CMOCK_Control_ClearCalibrationStatusBit_CALLBACK Callback);
#define Control_WriteOdom_Ignore() Control_WriteOdom_CMockIgnore()
void Control_WriteOdom_CMockIgnore(void);
#define Control_WriteOdom_Expect(linear, angular, left_dist, right_dist, heading) Control_WriteOdom_CMockExpect(__LINE__, linear, angular, left_dist, right_dist, heading)
void Control_WriteOdom_CMockExpect(UNITY_LINE_TYPE cmock_line, FLOAT linear, FLOAT angular, FLOAT left_dist, FLOAT right_dist, FLOAT heading);
typedef void (* CMOCK_Control_WriteOdom_CALLBACK)(FLOAT linear, FLOAT angular, FLOAT left_dist, FLOAT right_dist, FLOAT heading, int cmock_num_calls);
void Control_WriteOdom_StubWithCallback(CMOCK_Control_WriteOdom_CALLBACK Callback);
#define Control_UpdateHeartbeat_Ignore() Control_UpdateHeartbeat_CMockIgnore()
void Control_UpdateHeartbeat_CMockIgnore(void);
#define Control_UpdateHeartbeat_Expect(heartbeat) Control_UpdateHeartbeat_CMockExpect(__LINE__, heartbeat)
void Control_UpdateHeartbeat_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT32 heartbeat);
typedef void (* CMOCK_Control_UpdateHeartbeat_CALLBACK)(UINT32 heartbeat, int cmock_num_calls);
void Control_UpdateHeartbeat_StubWithCallback(CMOCK_Control_UpdateHeartbeat_CALLBACK Callback);
#define Control_SetLeftRightVelocityOverride_Ignore() Control_SetLeftRightVelocityOverride_CMockIgnore()
void Control_SetLeftRightVelocityOverride_CMockIgnore(void);
#define Control_SetLeftRightVelocityOverride_Expect(enable) Control_SetLeftRightVelocityOverride_CMockExpect(__LINE__, enable)
void Control_SetLeftRightVelocityOverride_CMockExpect(UNITY_LINE_TYPE cmock_line, BOOL enable);
typedef void (* CMOCK_Control_SetLeftRightVelocityOverride_CALLBACK)(BOOL enable, int cmock_num_calls);
void Control_SetLeftRightVelocityOverride_StubWithCallback(CMOCK_Control_SetLeftRightVelocityOverride_CALLBACK Callback);
#define Control_SetLeftRightVelocity_Ignore() Control_SetLeftRightVelocity_CMockIgnore()
void Control_SetLeftRightVelocity_CMockIgnore(void);
#define Control_SetLeftRightVelocity_Expect(left, right) Control_SetLeftRightVelocity_CMockExpect(__LINE__, left, right)
void Control_SetLeftRightVelocity_CMockExpect(UNITY_LINE_TYPE cmock_line, FLOAT left, FLOAT right);
typedef void (* CMOCK_Control_SetLeftRightVelocity_CALLBACK)(FLOAT left, FLOAT right, int cmock_num_calls);
void Control_SetLeftRightVelocity_StubWithCallback(CMOCK_Control_SetLeftRightVelocity_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#pragma GCC diagnostic pop
#endif

#endif