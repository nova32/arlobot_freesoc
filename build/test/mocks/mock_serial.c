/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_serial.h"

static const char* CMockString_Ser_Init = "Ser_Init";
static const char* CMockString_Ser_PutString = "Ser_PutString";
static const char* CMockString_Ser_PutStringFormat = "Ser_PutStringFormat";
static const char* CMockString_Ser_ReadByte = "Ser_ReadByte";
static const char* CMockString_Ser_ReadData = "Ser_ReadData";
static const char* CMockString_Ser_ReadLine = "Ser_ReadLine";
static const char* CMockString_Ser_Start = "Ser_Start";
static const char* CMockString_Ser_Update = "Ser_Update";
static const char* CMockString_Ser_WriteByte = "Ser_WriteByte";
static const char* CMockString_data = "data";
static const char* CMockString_disable = "disable";
static const char* CMockString_echo = "echo";
static const char* CMockString_fmt = "fmt";
static const char* CMockString_line = "line";
static const char* CMockString_str = "str";
static const char* CMockString_value = "value";

typedef struct _CMOCK_Ser_Init_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_Ser_Init_CALL_INSTANCE;

typedef struct _CMOCK_Ser_Start_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  UINT8 Expected_disable;

} CMOCK_Ser_Start_CALL_INSTANCE;

typedef struct _CMOCK_Ser_Update_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_Ser_Update_CALL_INSTANCE;

typedef struct _CMOCK_Ser_PutString_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  char* Expected_str;

} CMOCK_Ser_PutString_CALL_INSTANCE;

typedef struct _CMOCK_Ser_PutStringFormat_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  char* Expected_fmt;

} CMOCK_Ser_PutStringFormat_CALL_INSTANCE;

typedef struct _CMOCK_Ser_ReadData_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  UINT8 ReturnVal;
  int CallOrder;
  UINT8* Expected_data;

} CMOCK_Ser_ReadData_CALL_INSTANCE;

typedef struct _CMOCK_Ser_ReadByte_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  UINT8 ReturnVal;
  int CallOrder;

} CMOCK_Ser_ReadByte_CALL_INSTANCE;

typedef struct _CMOCK_Ser_ReadLine_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  UINT8 ReturnVal;
  int CallOrder;
  char* Expected_line;
  UINT8 Expected_echo;

} CMOCK_Ser_ReadLine_CALL_INSTANCE;

typedef struct _CMOCK_Ser_WriteByte_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  UINT8 Expected_value;

} CMOCK_Ser_WriteByte_CALL_INSTANCE;

static struct mock_serialInstance
{
  int Ser_Init_IgnoreBool;
  CMOCK_Ser_Init_CALLBACK Ser_Init_CallbackFunctionPointer;
  int Ser_Init_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_Init_CallInstance;
  int Ser_Start_IgnoreBool;
  CMOCK_Ser_Start_CALLBACK Ser_Start_CallbackFunctionPointer;
  int Ser_Start_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_Start_CallInstance;
  int Ser_Update_IgnoreBool;
  CMOCK_Ser_Update_CALLBACK Ser_Update_CallbackFunctionPointer;
  int Ser_Update_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_Update_CallInstance;
  int Ser_PutString_IgnoreBool;
  CMOCK_Ser_PutString_CALLBACK Ser_PutString_CallbackFunctionPointer;
  int Ser_PutString_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_PutString_CallInstance;
  int Ser_PutStringFormat_IgnoreBool;
  CMOCK_Ser_PutStringFormat_CALLBACK Ser_PutStringFormat_CallbackFunctionPointer;
  int Ser_PutStringFormat_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_PutStringFormat_CallInstance;
  int Ser_ReadData_IgnoreBool;
  UINT8 Ser_ReadData_FinalReturn;
  CMOCK_Ser_ReadData_CALLBACK Ser_ReadData_CallbackFunctionPointer;
  int Ser_ReadData_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_ReadData_CallInstance;
  int Ser_ReadByte_IgnoreBool;
  UINT8 Ser_ReadByte_FinalReturn;
  CMOCK_Ser_ReadByte_CALLBACK Ser_ReadByte_CallbackFunctionPointer;
  int Ser_ReadByte_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_ReadByte_CallInstance;
  int Ser_ReadLine_IgnoreBool;
  UINT8 Ser_ReadLine_FinalReturn;
  CMOCK_Ser_ReadLine_CALLBACK Ser_ReadLine_CallbackFunctionPointer;
  int Ser_ReadLine_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_ReadLine_CallInstance;
  int Ser_WriteByte_IgnoreBool;
  CMOCK_Ser_WriteByte_CALLBACK Ser_WriteByte_CallbackFunctionPointer;
  int Ser_WriteByte_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE Ser_WriteByte_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_serial_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.Ser_Init_IgnoreBool)
    Mock.Ser_Init_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_Init);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_Init_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_Init_CallbackFunctionPointer != NULL)
    Mock.Ser_Init_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_Start_IgnoreBool)
    Mock.Ser_Start_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_Start);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_Start_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_Start_CallbackFunctionPointer != NULL)
    Mock.Ser_Start_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_Update_IgnoreBool)
    Mock.Ser_Update_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_Update);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_Update_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_Update_CallbackFunctionPointer != NULL)
    Mock.Ser_Update_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_PutString_IgnoreBool)
    Mock.Ser_PutString_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_PutString);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_PutString_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_PutString_CallbackFunctionPointer != NULL)
    Mock.Ser_PutString_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_PutStringFormat_IgnoreBool)
    Mock.Ser_PutStringFormat_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_PutStringFormat);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_PutStringFormat_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_PutStringFormat_CallbackFunctionPointer != NULL)
    Mock.Ser_PutStringFormat_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_ReadData_IgnoreBool)
    Mock.Ser_ReadData_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_ReadData);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_ReadData_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_ReadData_CallbackFunctionPointer != NULL)
    Mock.Ser_ReadData_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_ReadByte_IgnoreBool)
    Mock.Ser_ReadByte_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_ReadByte);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_ReadByte_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_ReadByte_CallbackFunctionPointer != NULL)
    Mock.Ser_ReadByte_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_ReadLine_IgnoreBool)
    Mock.Ser_ReadLine_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_ReadLine);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_ReadLine_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_ReadLine_CallbackFunctionPointer != NULL)
    Mock.Ser_ReadLine_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.Ser_WriteByte_IgnoreBool)
    Mock.Ser_WriteByte_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_Ser_WriteByte);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.Ser_WriteByte_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.Ser_WriteByte_CallbackFunctionPointer != NULL)
    Mock.Ser_WriteByte_CallInstance = CMOCK_GUTS_NONE;
}

void mock_serial_Init(void)
{
  mock_serial_Destroy();
}

void mock_serial_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.Ser_Init_CallbackFunctionPointer = NULL;
  Mock.Ser_Init_CallbackCalls = 0;
  Mock.Ser_Start_CallbackFunctionPointer = NULL;
  Mock.Ser_Start_CallbackCalls = 0;
  Mock.Ser_Update_CallbackFunctionPointer = NULL;
  Mock.Ser_Update_CallbackCalls = 0;
  Mock.Ser_PutString_CallbackFunctionPointer = NULL;
  Mock.Ser_PutString_CallbackCalls = 0;
  Mock.Ser_PutStringFormat_CallbackFunctionPointer = NULL;
  Mock.Ser_PutStringFormat_CallbackCalls = 0;
  Mock.Ser_ReadData_CallbackFunctionPointer = NULL;
  Mock.Ser_ReadData_CallbackCalls = 0;
  Mock.Ser_ReadByte_CallbackFunctionPointer = NULL;
  Mock.Ser_ReadByte_CallbackCalls = 0;
  Mock.Ser_ReadLine_CallbackFunctionPointer = NULL;
  Mock.Ser_ReadLine_CallbackCalls = 0;
  Mock.Ser_WriteByte_CallbackFunctionPointer = NULL;
  Mock.Ser_WriteByte_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void Ser_Init(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_Init_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_Init);
  cmock_call_instance = (CMOCK_Ser_Init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_Init_CallInstance);
  Mock.Ser_Init_CallInstance = CMock_Guts_MemNext(Mock.Ser_Init_CallInstance);
  if (Mock.Ser_Init_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.Ser_Init_CallbackFunctionPointer != NULL)
  {
    Mock.Ser_Init_CallbackFunctionPointer(Mock.Ser_Init_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
}

void Ser_Init_CMockIgnore(void)
{
  Mock.Ser_Init_IgnoreBool = (int)1;
}

void Ser_Init_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_Init_CALL_INSTANCE));
  CMOCK_Ser_Init_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_Init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_Init_CallInstance = CMock_Guts_MemChain(Mock.Ser_Init_CallInstance, cmock_guts_index);
  Mock.Ser_Init_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  UNITY_CLR_DETAILS();
}

void Ser_Init_StubWithCallback(CMOCK_Ser_Init_CALLBACK Callback)
{
  Mock.Ser_Init_IgnoreBool = (int)0;
  Mock.Ser_Init_CallbackFunctionPointer = Callback;
}

void Ser_Start(UINT8 disable)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_Start_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_Start);
  cmock_call_instance = (CMOCK_Ser_Start_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_Start_CallInstance);
  Mock.Ser_Start_CallInstance = CMock_Guts_MemNext(Mock.Ser_Start_CallInstance);
  if (Mock.Ser_Start_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.Ser_Start_CallbackFunctionPointer != NULL)
  {
    Mock.Ser_Start_CallbackFunctionPointer(disable, Mock.Ser_Start_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_Ser_Start,CMockString_disable);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_disable, disable, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_Ser_Start(CMOCK_Ser_Start_CALL_INSTANCE* cmock_call_instance, UINT8 disable)
{
  cmock_call_instance->Expected_disable = disable;
}

void Ser_Start_CMockIgnore(void)
{
  Mock.Ser_Start_IgnoreBool = (int)1;
}

void Ser_Start_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT8 disable)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_Start_CALL_INSTANCE));
  CMOCK_Ser_Start_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_Start_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_Start_CallInstance = CMock_Guts_MemChain(Mock.Ser_Start_CallInstance, cmock_guts_index);
  Mock.Ser_Start_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_Ser_Start(cmock_call_instance, disable);
  UNITY_CLR_DETAILS();
}

void Ser_Start_StubWithCallback(CMOCK_Ser_Start_CALLBACK Callback)
{
  Mock.Ser_Start_IgnoreBool = (int)0;
  Mock.Ser_Start_CallbackFunctionPointer = Callback;
}

void Ser_Update(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_Update_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_Update);
  cmock_call_instance = (CMOCK_Ser_Update_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_Update_CallInstance);
  Mock.Ser_Update_CallInstance = CMock_Guts_MemNext(Mock.Ser_Update_CallInstance);
  if (Mock.Ser_Update_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.Ser_Update_CallbackFunctionPointer != NULL)
  {
    Mock.Ser_Update_CallbackFunctionPointer(Mock.Ser_Update_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
}

void Ser_Update_CMockIgnore(void)
{
  Mock.Ser_Update_IgnoreBool = (int)1;
}

void Ser_Update_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_Update_CALL_INSTANCE));
  CMOCK_Ser_Update_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_Update_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_Update_CallInstance = CMock_Guts_MemChain(Mock.Ser_Update_CallInstance, cmock_guts_index);
  Mock.Ser_Update_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  UNITY_CLR_DETAILS();
}

void Ser_Update_StubWithCallback(CMOCK_Ser_Update_CALLBACK Callback)
{
  Mock.Ser_Update_IgnoreBool = (int)0;
  Mock.Ser_Update_CallbackFunctionPointer = Callback;
}

void Ser_PutString(char* str)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_PutString_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_PutString);
  cmock_call_instance = (CMOCK_Ser_PutString_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_PutString_CallInstance);
  Mock.Ser_PutString_CallInstance = CMock_Guts_MemNext(Mock.Ser_PutString_CallInstance);
  if (Mock.Ser_PutString_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.Ser_PutString_CallbackFunctionPointer != NULL)
  {
    Mock.Ser_PutString_CallbackFunctionPointer(str, Mock.Ser_PutString_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_Ser_PutString,CMockString_str);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_str, str, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_Ser_PutString(CMOCK_Ser_PutString_CALL_INSTANCE* cmock_call_instance, char* str)
{
  cmock_call_instance->Expected_str = str;
}

void Ser_PutString_CMockIgnore(void)
{
  Mock.Ser_PutString_IgnoreBool = (int)1;
}

void Ser_PutString_CMockExpect(UNITY_LINE_TYPE cmock_line, char* str)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_PutString_CALL_INSTANCE));
  CMOCK_Ser_PutString_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_PutString_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_PutString_CallInstance = CMock_Guts_MemChain(Mock.Ser_PutString_CallInstance, cmock_guts_index);
  Mock.Ser_PutString_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_Ser_PutString(cmock_call_instance, str);
  UNITY_CLR_DETAILS();
}

void Ser_PutString_StubWithCallback(CMOCK_Ser_PutString_CALLBACK Callback)
{
  Mock.Ser_PutString_IgnoreBool = (int)0;
  Mock.Ser_PutString_CallbackFunctionPointer = Callback;
}

void Ser_PutStringFormat(const char* fmt, ...)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_PutStringFormat_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_PutStringFormat);
  cmock_call_instance = (CMOCK_Ser_PutStringFormat_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_PutStringFormat_CallInstance);
  Mock.Ser_PutStringFormat_CallInstance = CMock_Guts_MemNext(Mock.Ser_PutStringFormat_CallInstance);
  if (Mock.Ser_PutStringFormat_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.Ser_PutStringFormat_CallbackFunctionPointer != NULL)
  {
    Mock.Ser_PutStringFormat_CallbackFunctionPointer(fmt, Mock.Ser_PutStringFormat_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_Ser_PutStringFormat,CMockString_fmt);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_fmt, fmt, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_Ser_PutStringFormat(CMOCK_Ser_PutStringFormat_CALL_INSTANCE* cmock_call_instance, const char* fmt)
{
  cmock_call_instance->Expected_fmt = (char*)fmt;
}

void Ser_PutStringFormat_CMockIgnore(void)
{
  Mock.Ser_PutStringFormat_IgnoreBool = (int)1;
}

void Ser_PutStringFormat_CMockExpect(UNITY_LINE_TYPE cmock_line, const char* fmt)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_PutStringFormat_CALL_INSTANCE));
  CMOCK_Ser_PutStringFormat_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_PutStringFormat_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_PutStringFormat_CallInstance = CMock_Guts_MemChain(Mock.Ser_PutStringFormat_CallInstance, cmock_guts_index);
  Mock.Ser_PutStringFormat_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_Ser_PutStringFormat(cmock_call_instance, fmt);
  UNITY_CLR_DETAILS();
}

void Ser_PutStringFormat_StubWithCallback(CMOCK_Ser_PutStringFormat_CALLBACK Callback)
{
  Mock.Ser_PutStringFormat_IgnoreBool = (int)0;
  Mock.Ser_PutStringFormat_CallbackFunctionPointer = Callback;
}

UINT8 Ser_ReadData(UINT8* data)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_ReadData_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_ReadData);
  cmock_call_instance = (CMOCK_Ser_ReadData_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_ReadData_CallInstance);
  Mock.Ser_ReadData_CallInstance = CMock_Guts_MemNext(Mock.Ser_ReadData_CallInstance);
  if (Mock.Ser_ReadData_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.Ser_ReadData_FinalReturn;
    Mock.Ser_ReadData_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.Ser_ReadData_CallbackFunctionPointer != NULL)
  {
    return Mock.Ser_ReadData_CallbackFunctionPointer(data, Mock.Ser_ReadData_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_Ser_ReadData,CMockString_data);
    if (cmock_call_instance->Expected_data == NULL)
      { UNITY_TEST_ASSERT_NULL(data, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_data, data, 1, cmock_line, CMockStringMismatch); }
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_Ser_ReadData(CMOCK_Ser_ReadData_CALL_INSTANCE* cmock_call_instance, UINT8* data)
{
  cmock_call_instance->Expected_data = data;
}

void Ser_ReadData_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, UINT8 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_ReadData_CALL_INSTANCE));
  CMOCK_Ser_ReadData_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_ReadData_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_ReadData_CallInstance = CMock_Guts_MemChain(Mock.Ser_ReadData_CallInstance, cmock_guts_index);
  Mock.Ser_ReadData_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.Ser_ReadData_IgnoreBool = (int)1;
}

void Ser_ReadData_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, UINT8* data, UINT8 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_ReadData_CALL_INSTANCE));
  CMOCK_Ser_ReadData_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_ReadData_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_ReadData_CallInstance = CMock_Guts_MemChain(Mock.Ser_ReadData_CallInstance, cmock_guts_index);
  Mock.Ser_ReadData_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_Ser_ReadData(cmock_call_instance, data);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void Ser_ReadData_StubWithCallback(CMOCK_Ser_ReadData_CALLBACK Callback)
{
  Mock.Ser_ReadData_IgnoreBool = (int)0;
  Mock.Ser_ReadData_CallbackFunctionPointer = Callback;
}

UINT8 Ser_ReadByte(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_ReadByte_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_ReadByte);
  cmock_call_instance = (CMOCK_Ser_ReadByte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_ReadByte_CallInstance);
  Mock.Ser_ReadByte_CallInstance = CMock_Guts_MemNext(Mock.Ser_ReadByte_CallInstance);
  if (Mock.Ser_ReadByte_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.Ser_ReadByte_FinalReturn;
    Mock.Ser_ReadByte_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.Ser_ReadByte_CallbackFunctionPointer != NULL)
  {
    return Mock.Ser_ReadByte_CallbackFunctionPointer(Mock.Ser_ReadByte_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void Ser_ReadByte_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, UINT8 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_ReadByte_CALL_INSTANCE));
  CMOCK_Ser_ReadByte_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_ReadByte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_ReadByte_CallInstance = CMock_Guts_MemChain(Mock.Ser_ReadByte_CallInstance, cmock_guts_index);
  Mock.Ser_ReadByte_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.Ser_ReadByte_IgnoreBool = (int)1;
}

void Ser_ReadByte_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, UINT8 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_ReadByte_CALL_INSTANCE));
  CMOCK_Ser_ReadByte_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_ReadByte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_ReadByte_CallInstance = CMock_Guts_MemChain(Mock.Ser_ReadByte_CallInstance, cmock_guts_index);
  Mock.Ser_ReadByte_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void Ser_ReadByte_StubWithCallback(CMOCK_Ser_ReadByte_CALLBACK Callback)
{
  Mock.Ser_ReadByte_IgnoreBool = (int)0;
  Mock.Ser_ReadByte_CallbackFunctionPointer = Callback;
}

UINT8 Ser_ReadLine(char* line, UINT8 echo)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_ReadLine_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_ReadLine);
  cmock_call_instance = (CMOCK_Ser_ReadLine_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_ReadLine_CallInstance);
  Mock.Ser_ReadLine_CallInstance = CMock_Guts_MemNext(Mock.Ser_ReadLine_CallInstance);
  if (Mock.Ser_ReadLine_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.Ser_ReadLine_FinalReturn;
    Mock.Ser_ReadLine_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.Ser_ReadLine_CallbackFunctionPointer != NULL)
  {
    return Mock.Ser_ReadLine_CallbackFunctionPointer(line, echo, Mock.Ser_ReadLine_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_Ser_ReadLine,CMockString_line);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_line, line, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_Ser_ReadLine,CMockString_echo);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_echo, echo, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_Ser_ReadLine(CMOCK_Ser_ReadLine_CALL_INSTANCE* cmock_call_instance, char* line, UINT8 echo)
{
  cmock_call_instance->Expected_line = line;
  cmock_call_instance->Expected_echo = echo;
}

void Ser_ReadLine_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, UINT8 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_ReadLine_CALL_INSTANCE));
  CMOCK_Ser_ReadLine_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_ReadLine_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_ReadLine_CallInstance = CMock_Guts_MemChain(Mock.Ser_ReadLine_CallInstance, cmock_guts_index);
  Mock.Ser_ReadLine_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.Ser_ReadLine_IgnoreBool = (int)1;
}

void Ser_ReadLine_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, char* line, UINT8 echo, UINT8 cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_ReadLine_CALL_INSTANCE));
  CMOCK_Ser_ReadLine_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_ReadLine_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_ReadLine_CallInstance = CMock_Guts_MemChain(Mock.Ser_ReadLine_CallInstance, cmock_guts_index);
  Mock.Ser_ReadLine_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_Ser_ReadLine(cmock_call_instance, line, echo);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void Ser_ReadLine_StubWithCallback(CMOCK_Ser_ReadLine_CALLBACK Callback)
{
  Mock.Ser_ReadLine_IgnoreBool = (int)0;
  Mock.Ser_ReadLine_CallbackFunctionPointer = Callback;
}

void Ser_WriteByte(UINT8 value)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_Ser_WriteByte_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_Ser_WriteByte);
  cmock_call_instance = (CMOCK_Ser_WriteByte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.Ser_WriteByte_CallInstance);
  Mock.Ser_WriteByte_CallInstance = CMock_Guts_MemNext(Mock.Ser_WriteByte_CallInstance);
  if (Mock.Ser_WriteByte_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.Ser_WriteByte_CallbackFunctionPointer != NULL)
  {
    Mock.Ser_WriteByte_CallbackFunctionPointer(value, Mock.Ser_WriteByte_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_Ser_WriteByte,CMockString_value);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_value, value, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_Ser_WriteByte(CMOCK_Ser_WriteByte_CALL_INSTANCE* cmock_call_instance, UINT8 value)
{
  cmock_call_instance->Expected_value = value;
}

void Ser_WriteByte_CMockIgnore(void)
{
  Mock.Ser_WriteByte_IgnoreBool = (int)1;
}

void Ser_WriteByte_CMockExpect(UNITY_LINE_TYPE cmock_line, UINT8 value)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_Ser_WriteByte_CALL_INSTANCE));
  CMOCK_Ser_WriteByte_CALL_INSTANCE* cmock_call_instance = (CMOCK_Ser_WriteByte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.Ser_WriteByte_CallInstance = CMock_Guts_MemChain(Mock.Ser_WriteByte_CallInstance, cmock_guts_index);
  Mock.Ser_WriteByte_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_Ser_WriteByte(cmock_call_instance, value);
  UNITY_CLR_DETAILS();
}

void Ser_WriteByte_StubWithCallback(CMOCK_Ser_WriteByte_CALLBACK Callback)
{
  Mock.Ser_WriteByte_IgnoreBool = (int)0;
  Mock.Ser_WriteByte_CallbackFunctionPointer = Callback;
}

