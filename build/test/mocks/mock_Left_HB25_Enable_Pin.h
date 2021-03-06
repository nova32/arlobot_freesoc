/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_LEFT_HB25_ENABLE_PIN_H
#define _MOCK_LEFT_HB25_ENABLE_PIN_H

#include "Left_HB25_Enable_Pin.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#pragma GCC diagnostic push
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_Left_HB25_Enable_Pin_Init(void);
void mock_Left_HB25_Enable_Pin_Destroy(void);
void mock_Left_HB25_Enable_Pin_Verify(void);




#define Left_HB25_Enable_Pin_Write_Ignore() Left_HB25_Enable_Pin_Write_CMockIgnore()
void Left_HB25_Enable_Pin_Write_CMockIgnore(void);
#define Left_HB25_Enable_Pin_Write_Expect(value) Left_HB25_Enable_Pin_Write_CMockExpect(__LINE__, value)
void Left_HB25_Enable_Pin_Write_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8 value);
typedef void (* CMOCK_Left_HB25_Enable_Pin_Write_CALLBACK)(uint8 value, int cmock_num_calls);
void Left_HB25_Enable_Pin_Write_StubWithCallback(CMOCK_Left_HB25_Enable_Pin_Write_CALLBACK Callback);
#define Left_HB25_Enable_Pin_SetDriveMode_Ignore() Left_HB25_Enable_Pin_SetDriveMode_CMockIgnore()
void Left_HB25_Enable_Pin_SetDriveMode_CMockIgnore(void);
#define Left_HB25_Enable_Pin_SetDriveMode_Expect(mode) Left_HB25_Enable_Pin_SetDriveMode_CMockExpect(__LINE__, mode)
void Left_HB25_Enable_Pin_SetDriveMode_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8 mode);
typedef void (* CMOCK_Left_HB25_Enable_Pin_SetDriveMode_CALLBACK)(uint8 mode, int cmock_num_calls);
void Left_HB25_Enable_Pin_SetDriveMode_StubWithCallback(CMOCK_Left_HB25_Enable_Pin_SetDriveMode_CALLBACK Callback);
#define Left_HB25_Enable_Pin_ReadDataReg_IgnoreAndReturn(cmock_retval) Left_HB25_Enable_Pin_ReadDataReg_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Left_HB25_Enable_Pin_ReadDataReg_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8 cmock_to_return);
#define Left_HB25_Enable_Pin_ReadDataReg_ExpectAndReturn(cmock_retval) Left_HB25_Enable_Pin_ReadDataReg_CMockExpectAndReturn(__LINE__, cmock_retval)
void Left_HB25_Enable_Pin_ReadDataReg_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8 cmock_to_return);
typedef uint8 (* CMOCK_Left_HB25_Enable_Pin_ReadDataReg_CALLBACK)(int cmock_num_calls);
void Left_HB25_Enable_Pin_ReadDataReg_StubWithCallback(CMOCK_Left_HB25_Enable_Pin_ReadDataReg_CALLBACK Callback);
#define Left_HB25_Enable_Pin_Read_IgnoreAndReturn(cmock_retval) Left_HB25_Enable_Pin_Read_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Left_HB25_Enable_Pin_Read_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8 cmock_to_return);
#define Left_HB25_Enable_Pin_Read_ExpectAndReturn(cmock_retval) Left_HB25_Enable_Pin_Read_CMockExpectAndReturn(__LINE__, cmock_retval)
void Left_HB25_Enable_Pin_Read_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8 cmock_to_return);
typedef uint8 (* CMOCK_Left_HB25_Enable_Pin_Read_CALLBACK)(int cmock_num_calls);
void Left_HB25_Enable_Pin_Read_StubWithCallback(CMOCK_Left_HB25_Enable_Pin_Read_CALLBACK Callback);
#define Left_HB25_Enable_Pin_SetInterruptMode_Ignore() Left_HB25_Enable_Pin_SetInterruptMode_CMockIgnore()
void Left_HB25_Enable_Pin_SetInterruptMode_CMockIgnore(void);
#define Left_HB25_Enable_Pin_SetInterruptMode_Expect(position, mode) Left_HB25_Enable_Pin_SetInterruptMode_CMockExpect(__LINE__, position, mode)
void Left_HB25_Enable_Pin_SetInterruptMode_CMockExpect(UNITY_LINE_TYPE cmock_line, uint16 position, uint16 mode);
typedef void (* CMOCK_Left_HB25_Enable_Pin_SetInterruptMode_CALLBACK)(uint16 position, uint16 mode, int cmock_num_calls);
void Left_HB25_Enable_Pin_SetInterruptMode_StubWithCallback(CMOCK_Left_HB25_Enable_Pin_SetInterruptMode_CALLBACK Callback);
#define Left_HB25_Enable_Pin_ClearInterrupt_IgnoreAndReturn(cmock_retval) Left_HB25_Enable_Pin_ClearInterrupt_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void Left_HB25_Enable_Pin_ClearInterrupt_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8 cmock_to_return);
#define Left_HB25_Enable_Pin_ClearInterrupt_ExpectAndReturn(cmock_retval) Left_HB25_Enable_Pin_ClearInterrupt_CMockExpectAndReturn(__LINE__, cmock_retval)
void Left_HB25_Enable_Pin_ClearInterrupt_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8 cmock_to_return);
typedef uint8 (* CMOCK_Left_HB25_Enable_Pin_ClearInterrupt_CALLBACK)(int cmock_num_calls);
void Left_HB25_Enable_Pin_ClearInterrupt_StubWithCallback(CMOCK_Left_HB25_Enable_Pin_ClearInterrupt_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#pragma GCC diagnostic pop
#endif

#endif
