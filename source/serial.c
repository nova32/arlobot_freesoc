/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "serial.h"
#include "utils.h"

#ifdef COMMS_DEBUG_ENABLED    
#define USBFS_DEVICE    (0u)

/* The buffer size is equal to the maximum packet size of the IN and OUT bulk
* endpoints.
*/
#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH     (20u)
#endif

static uint8 buffer[500];

void Ser_Init()
{
}

void Ser_Start()
{
#ifdef COMMS_DEBUG_ENABLED    
    /* Start USBFS operation with 5-V operation. */
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);

    /* Host can send double SET_INTERFACE request. */
    if (0u != USBUART_IsConfigurationChanged())
    {
        /* Initialize IN endpoints when device is configured. */
        if (0u != USBUART_GetConfiguration())
        {
            /* Enumeration is done, enable OUT endpoint to receive data 
             * from host. */
            USBUART_CDC_Init();
        }
    }

    /* Service USB CDC when device is configured. */
    if (0u != USBUART_GetConfiguration())
    {
        USBUART_PutString("USB UART is configured!\r\n");
    }
#endif
}

uint8 Ser_Write(uint8 *data, size_t num)
{
#ifdef COMMS_DEBUG_ENABLED    
    if (0 != USBUART_CDCIsReady())
    {
        USBUART_PutData(data, num);
        return 0;    
    }
    
    return 1;
#else
    data = data;
    num = num;
    return 0;
#endif    
}

uint8 Ser_Read(uint8 *data, size_t *num)
{
#ifdef COMMS_DEBUG_ENABLED    
    uint16 count;
    
    if (0u != USBUART_DataIsReady())
    {
        /* Read received data and re-enable OUT endpoint. */
        count = USBUART_GetAll(buffer);
                
        *num = min(*num, count);
        memcpy(data, buffer, *num);
        return 0;
    }
    
    return 1;
#else
    data = data;
    num = num;
    return 0;
#endif    
}

void Ser_PutString(char *str)
{
#ifdef COMMS_DEBUG_ENABLED    
    if (0 != USBUART_CDCIsReady())
    {
        USBUART_PutString(str);
    }
#else
    str = str;
#endif    
}

/* [] END OF FILE */
