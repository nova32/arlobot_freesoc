/*******************************************************************************
* File Name: Rear_ADC_SAR_IRQ.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Rear_ADC_SAR_IRQ_H)
#define CY_ISR_Rear_ADC_SAR_IRQ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Rear_ADC_SAR_IRQ_Start(void);
void Rear_ADC_SAR_IRQ_StartEx(cyisraddress address);
void Rear_ADC_SAR_IRQ_Stop(void);

CY_ISR_PROTO(Rear_ADC_SAR_IRQ_Interrupt);

void Rear_ADC_SAR_IRQ_SetVector(cyisraddress address);
cyisraddress Rear_ADC_SAR_IRQ_GetVector(void);

void Rear_ADC_SAR_IRQ_SetPriority(uint8 priority);
uint8 Rear_ADC_SAR_IRQ_GetPriority(void);

void Rear_ADC_SAR_IRQ_Enable(void);
uint8 Rear_ADC_SAR_IRQ_GetState(void);
void Rear_ADC_SAR_IRQ_Disable(void);

void Rear_ADC_SAR_IRQ_SetPending(void);
void Rear_ADC_SAR_IRQ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Rear_ADC_SAR_IRQ ISR. */
#define Rear_ADC_SAR_IRQ_INTC_VECTOR            ((reg32 *) Rear_ADC_SAR_IRQ__INTC_VECT)

/* Address of the Rear_ADC_SAR_IRQ ISR priority. */
#define Rear_ADC_SAR_IRQ_INTC_PRIOR             ((reg8 *) Rear_ADC_SAR_IRQ__INTC_PRIOR_REG)

/* Priority of the Rear_ADC_SAR_IRQ interrupt. */
#define Rear_ADC_SAR_IRQ_INTC_PRIOR_NUMBER      Rear_ADC_SAR_IRQ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Rear_ADC_SAR_IRQ interrupt. */
#define Rear_ADC_SAR_IRQ_INTC_SET_EN            ((reg32 *) Rear_ADC_SAR_IRQ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Rear_ADC_SAR_IRQ interrupt. */
#define Rear_ADC_SAR_IRQ_INTC_CLR_EN            ((reg32 *) Rear_ADC_SAR_IRQ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Rear_ADC_SAR_IRQ interrupt state to pending. */
#define Rear_ADC_SAR_IRQ_INTC_SET_PD            ((reg32 *) Rear_ADC_SAR_IRQ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Rear_ADC_SAR_IRQ interrupt. */
#define Rear_ADC_SAR_IRQ_INTC_CLR_PD            ((reg32 *) Rear_ADC_SAR_IRQ__INTC_CLR_PD_REG)


#endif /* CY_ISR_Rear_ADC_SAR_IRQ_H */


/* [] END OF FILE */
