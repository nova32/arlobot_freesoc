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
 * Description
 *
 * Provides a wrapper for the Cypress USB serial component.
 *
 *-------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------
 * Includes
 *-------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>
#include "serial.h"

/*---------------------------------------------------------------------------------------------------
 * Constants
 *-------------------------------------------------------------------------------------------------*/
#define USBFS_DEVICE    (0u)

/* The buffer size is equal to the maximum packet size of the IN and OUT bulk
* endpoints.
*/
#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH     (20u)

#define MAX_STRING_LENGTH (255)

#define CDC_IS_READY_TIMEOUT (1000)


/*---------------------------------------------------------------------------------------------------
 * Functions
 *-------------------------------------------------------------------------------------------------*/
static void WaitForCDCIsReady(uint32 timeout)
{
    /* The purpose of this routine is to check if CDC is ready in a non-blocking manner.
       If a serial port is connected to the USB then CDC is ready should return immediately; however
       if nothing is connected to the USB then obviously we're not interested in the output and
       so we don't want the main loop to be blocked by calls to check the CDC.
    */
       
    uint32 tick;

    if (timeout > 0)
    {
        tick = timeout;

        while (tick > 0)
        {
            if (USBUART_CDCIsReady())
            {
                break;
            }
            tick--;
        }
    }    
}


/*---------------------------------------------------------------------------------------------------
 * Name: Ser_Init
 * Description: Initializes the serial module
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Ser_Init()
{
}

/*---------------------------------------------------------------------------------------------------
 * Name: Ser_Start
 * Description: Starts the serial module
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Ser_Start()
{
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
    
}

/*---------------------------------------------------------------------------------------------------
 * Name: Ser_Update
 * Description: Pulses the USB serial component to keep it alive.  Call from the main loop.
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Ser_Update()
{
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
    
}

/*---------------------------------------------------------------------------------------------------
 * Name: Ser_PutString
 * Description: Sends a string to the serial port
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Ser_PutString(char *str)
{
    if (0u != USBUART_GetConfiguration())
    {
        WaitForCDCIsReady(CDC_IS_READY_TIMEOUT);
        USBUART_PutString(str);
    }
    
}

void Ser_PutStringFormat(const char *fmt, ...)
{    
    char str[MAX_STRING_LENGTH];
    va_list ap;

    va_start(ap, fmt);
    vsnprintf(str, MAX_STRING_LENGTH, fmt, ap);
    va_end(ap);       
    
    Ser_PutString(str);
    
}

/*---------------------------------------------------------------------------------------------------
 * Name: Ser_ReadData
 * Description: Reads one or more bytes (max 64) of data from the USB serial port.
 * Parameters: None
 * Return: Number of bytes read.
 * 
 *-------------------------------------------------------------------------------------------------*/
uint8 Ser_ReadData(uint8_t *data)
{
    uint8 count = 0;
    uint8 buffer[64];
    
    if (0u != USBUART_GetConfiguration())
    {
        /* Check for input data from host. */
        if (0u != USBUART_DataIsReady())
        {
            /* Read received data and re-enable OUT endpoint. */
            count = USBUART_GetAll(buffer);

            if (0u != count)
            {
                memset(data, 0, 64);
                memcpy(data, buffer, count);
            }
        }
    }

    return count;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Ser_ReadByte
 * Description: Returns a byte from the serial port.
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
uint8 Ser_ReadByte()
{
    /* Service USB CDC when device is configured. */
    if (0u != USBUART_GetConfiguration())
    {
        /* Check for input data from host. */
        if (0u != USBUART_DataIsReady())
        {
            /* Read received data and re-enable OUT endpoint. */
            return USBUART_GetChar();
        }
    }
    
    return 0;
}

/*---------------------------------------------------------------------------------------------------
 * Name: Ser_WriteByte
 * Description: Writes a byte to the serial port.
 * Parameters: None
 * Return: None
 * 
 *-------------------------------------------------------------------------------------------------*/
void Ser_WriteByte(uint8 value)
{
    
    if (0u != USBUART_GetConfiguration())
    {
        WaitForCDCIsReady(CDC_IS_READY_TIMEOUT);        
        USBUART_PutChar(value);
    }
    
}

/* [] END OF FILE */
