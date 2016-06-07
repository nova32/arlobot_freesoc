/*******************************************************************************
* File Name: Rear_EOS_Intr.h
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
#if !defined(CY_ISR_Rear_EOS_Intr_H)
#define CY_ISR_Rear_EOS_Intr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Rear_EOS_Intr_Start(void);
void Rear_EOS_Intr_StartEx(cyisraddress address);
void Rear_EOS_Intr_Stop(void);

CY_ISR_PROTO(Rear_EOS_Intr_Interrupt);

void Rear_EOS_Intr_SetVector(cyisraddress address);
cyisraddress Rear_EOS_Intr_GetVector(void);

void Rear_EOS_Intr_SetPriority(uint8 priority);
uint8 Rear_EOS_Intr_GetPriority(void);

void Rear_EOS_Intr_Enable(void);
uint8 Rear_EOS_Intr_GetState(void);
void Rear_EOS_Intr_Disable(void);

void Rear_EOS_Intr_SetPending(void);
void Rear_EOS_Intr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Rear_EOS_Intr ISR. */
#define Rear_EOS_Intr_INTC_VECTOR            ((reg32 *) Rear_EOS_Intr__INTC_VECT)

/* Address of the Rear_EOS_Intr ISR priority. */
#define Rear_EOS_Intr_INTC_PRIOR             ((reg8 *) Rear_EOS_Intr__INTC_PRIOR_REG)

/* Priority of the Rear_EOS_Intr interrupt. */
#define Rear_EOS_Intr_INTC_PRIOR_NUMBER      Rear_EOS_Intr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Rear_EOS_Intr interrupt. */
#define Rear_EOS_Intr_INTC_SET_EN            ((reg32 *) Rear_EOS_Intr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Rear_EOS_Intr interrupt. */
#define Rear_EOS_Intr_INTC_CLR_EN            ((reg32 *) Rear_EOS_Intr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Rear_EOS_Intr interrupt state to pending. */
#define Rear_EOS_Intr_INTC_SET_PD            ((reg32 *) Rear_EOS_Intr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Rear_EOS_Intr interrupt. */
#define Rear_EOS_Intr_INTC_CLR_PD            ((reg32 *) Rear_EOS_Intr__INTC_CLR_PD_REG)


#endif /* CY_ISR_Rear_EOS_Intr_H */


/* [] END OF FILE */
