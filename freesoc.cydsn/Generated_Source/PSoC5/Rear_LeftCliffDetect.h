/*******************************************************************************
* File Name: Rear_LeftCliffDetect.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Rear_LeftCliffDetect_H) /* Pins Rear_LeftCliffDetect_H */
#define CY_PINS_Rear_LeftCliffDetect_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Rear_LeftCliffDetect_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Rear_LeftCliffDetect__PORT == 15 && ((Rear_LeftCliffDetect__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Rear_LeftCliffDetect_Write(uint8 value);
void    Rear_LeftCliffDetect_SetDriveMode(uint8 mode);
uint8   Rear_LeftCliffDetect_ReadDataReg(void);
uint8   Rear_LeftCliffDetect_Read(void);
void    Rear_LeftCliffDetect_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rear_LeftCliffDetect_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Rear_LeftCliffDetect_SetDriveMode() function.
     *  @{
     */
        #define Rear_LeftCliffDetect_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Rear_LeftCliffDetect_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Rear_LeftCliffDetect_DM_RES_UP          PIN_DM_RES_UP
        #define Rear_LeftCliffDetect_DM_RES_DWN         PIN_DM_RES_DWN
        #define Rear_LeftCliffDetect_DM_OD_LO           PIN_DM_OD_LO
        #define Rear_LeftCliffDetect_DM_OD_HI           PIN_DM_OD_HI
        #define Rear_LeftCliffDetect_DM_STRONG          PIN_DM_STRONG
        #define Rear_LeftCliffDetect_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Rear_LeftCliffDetect_MASK               Rear_LeftCliffDetect__MASK
#define Rear_LeftCliffDetect_SHIFT              Rear_LeftCliffDetect__SHIFT
#define Rear_LeftCliffDetect_WIDTH              1u

/* Interrupt constants */
#if defined(Rear_LeftCliffDetect__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rear_LeftCliffDetect_SetInterruptMode() function.
     *  @{
     */
        #define Rear_LeftCliffDetect_INTR_NONE      (uint16)(0x0000u)
        #define Rear_LeftCliffDetect_INTR_RISING    (uint16)(0x0001u)
        #define Rear_LeftCliffDetect_INTR_FALLING   (uint16)(0x0002u)
        #define Rear_LeftCliffDetect_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Rear_LeftCliffDetect_INTR_MASK      (0x01u) 
#endif /* (Rear_LeftCliffDetect__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Rear_LeftCliffDetect_PS                     (* (reg8 *) Rear_LeftCliffDetect__PS)
/* Data Register */
#define Rear_LeftCliffDetect_DR                     (* (reg8 *) Rear_LeftCliffDetect__DR)
/* Port Number */
#define Rear_LeftCliffDetect_PRT_NUM                (* (reg8 *) Rear_LeftCliffDetect__PRT) 
/* Connect to Analog Globals */                                                  
#define Rear_LeftCliffDetect_AG                     (* (reg8 *) Rear_LeftCliffDetect__AG)                       
/* Analog MUX bux enable */
#define Rear_LeftCliffDetect_AMUX                   (* (reg8 *) Rear_LeftCliffDetect__AMUX) 
/* Bidirectional Enable */                                                        
#define Rear_LeftCliffDetect_BIE                    (* (reg8 *) Rear_LeftCliffDetect__BIE)
/* Bit-mask for Aliased Register Access */
#define Rear_LeftCliffDetect_BIT_MASK               (* (reg8 *) Rear_LeftCliffDetect__BIT_MASK)
/* Bypass Enable */
#define Rear_LeftCliffDetect_BYP                    (* (reg8 *) Rear_LeftCliffDetect__BYP)
/* Port wide control signals */                                                   
#define Rear_LeftCliffDetect_CTL                    (* (reg8 *) Rear_LeftCliffDetect__CTL)
/* Drive Modes */
#define Rear_LeftCliffDetect_DM0                    (* (reg8 *) Rear_LeftCliffDetect__DM0) 
#define Rear_LeftCliffDetect_DM1                    (* (reg8 *) Rear_LeftCliffDetect__DM1)
#define Rear_LeftCliffDetect_DM2                    (* (reg8 *) Rear_LeftCliffDetect__DM2) 
/* Input Buffer Disable Override */
#define Rear_LeftCliffDetect_INP_DIS                (* (reg8 *) Rear_LeftCliffDetect__INP_DIS)
/* LCD Common or Segment Drive */
#define Rear_LeftCliffDetect_LCD_COM_SEG            (* (reg8 *) Rear_LeftCliffDetect__LCD_COM_SEG)
/* Enable Segment LCD */
#define Rear_LeftCliffDetect_LCD_EN                 (* (reg8 *) Rear_LeftCliffDetect__LCD_EN)
/* Slew Rate Control */
#define Rear_LeftCliffDetect_SLW                    (* (reg8 *) Rear_LeftCliffDetect__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Rear_LeftCliffDetect_PRTDSI__CAPS_SEL       (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Rear_LeftCliffDetect_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Rear_LeftCliffDetect_PRTDSI__OE_SEL0        (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__OE_SEL0) 
#define Rear_LeftCliffDetect_PRTDSI__OE_SEL1        (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Rear_LeftCliffDetect_PRTDSI__OUT_SEL0       (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__OUT_SEL0) 
#define Rear_LeftCliffDetect_PRTDSI__OUT_SEL1       (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Rear_LeftCliffDetect_PRTDSI__SYNC_OUT       (* (reg8 *) Rear_LeftCliffDetect__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Rear_LeftCliffDetect__SIO_CFG)
    #define Rear_LeftCliffDetect_SIO_HYST_EN        (* (reg8 *) Rear_LeftCliffDetect__SIO_HYST_EN)
    #define Rear_LeftCliffDetect_SIO_REG_HIFREQ     (* (reg8 *) Rear_LeftCliffDetect__SIO_REG_HIFREQ)
    #define Rear_LeftCliffDetect_SIO_CFG            (* (reg8 *) Rear_LeftCliffDetect__SIO_CFG)
    #define Rear_LeftCliffDetect_SIO_DIFF           (* (reg8 *) Rear_LeftCliffDetect__SIO_DIFF)
#endif /* (Rear_LeftCliffDetect__SIO_CFG) */

/* Interrupt Registers */
#if defined(Rear_LeftCliffDetect__INTSTAT)
    #define Rear_LeftCliffDetect_INTSTAT            (* (reg8 *) Rear_LeftCliffDetect__INTSTAT)
    #define Rear_LeftCliffDetect_SNAP               (* (reg8 *) Rear_LeftCliffDetect__SNAP)
    
	#define Rear_LeftCliffDetect_0_INTTYPE_REG 		(* (reg8 *) Rear_LeftCliffDetect__0__INTTYPE)
#endif /* (Rear_LeftCliffDetect__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Rear_LeftCliffDetect_H */


/* [] END OF FILE */