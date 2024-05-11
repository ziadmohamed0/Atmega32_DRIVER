/*
 * dio_Init.h
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "dio_Reg.h"
#include "../../Serv/Std_Types.h"
#include "../../Serv/Bit_Math.h"
#include "../../Serv/Includes.h"
#include "../ADC/ADC_Init.h"

/* -------------------- Section : Enums -------------------- */
/* ========== Enum for Pins ========== */
typedef enum{
	PortA_p0 , PortA_p1 , PortA_p2 , PortA_p3 , PortA_p4 , PortA_p5 , PortA_p6 , PortA_p7,
	PortB_p0 , PortB_p1 , PortB_p2 , PortB_p3 , PortB_p4 , PortB_p5 , PortB_p6 , PortB_p7,
	PortC_p0 , PortC_p1 , PortC_p2 , PortC_p3 , PortC_p4 , PortC_p5 , PortC_p6 , PortC_p7,
	PortD_p0 , PortD_p1 , PortD_p2 , PortD_p3 , PortD_p4 , PortD_p5 , PortD_p6 , PortD_p7,
}Pins;


/* ========== Enum for Ports ========== */
typedef enum{
	PORTA_reg = 0,
	PORTB_reg,
	PORTC_reg,
	PORTD_reg,
}Ports;

/* -------------------- Section : Macros -------------------- */
#define	Status_Port_High		(u8)0xFF
#define	Status_Port_Low			(u8)0x00

#define Direction_Port_Input	(u8)0x00
#define Direction_Port_Output	(u8)0xFF

#define	Status_Pin_Toggle		(u8)2
#define	Status_Pin_High			(u8)1
#define	Status_Pin_Low			(u8)0

#define Direction_Pin_Input		(u8)0
#define Direction_Pin_Output	(u8)1

/* -------------------- Section : Pins Functions Declarations -------------------- */

/**
  * @brief  : Set Direction of Bit (Input or Output)
  * @param  : CopyPinNum
  * @param  : CopyPinDir
  */
void Dio_setPinDir(u8 CopyPinNum,u8 CopyPinDir);

/**
  * @brief  : Set Status of Bit (High or Low or Toggle)
  * @param  : CopyPinNum
  * @param  : CopyPinVal
  */
void Dio_setPinVal(u8 CopyPinNum,u8 CopyPinVal);

/**
  * @brief  : Get Status of Bit (High or Low)
  * @param  : CopyPinNum
  * @RetVal : Ret
  */
Std_Return Dio_getPinVal(u8 CopyPinNum);

/**
  * @brief  : Set Direction of Some Bit From u8PinsNum to Copyu8Size (Input or Output)
  * @param  : u8PinsNum
  * @param  : Copyu8Size
  * @param  : Copyu8Dir
  */
void DIO_vidSetPinSDir(u8 * u8PinsNum,u8 Copyu8Size,u8 Copyu8Dir);

/**
  * @brief  : Set Status of Some Bit From u8PinsNum to Copyu8Size (High or Low or Toggle)
  * @param  : u8PinsNum
  * @param  : Copyu8Size
  * @param  : Copyu8Val
  */
void DIO_vidSetPinSVal(u8 * u8PinsNum,u8 Copyu8Size,u8 Copyu8Val);


/* -------------------- Section : Ports Functions Declarations -------------------- */

/**
  * @brief  : Set Direction of Port (Input or Output)
  * @param  : CopyPortNum
  * @param  : CopyPinDir
  */
void Dio_setPortDir(u8 CopyPortNum,u8 CopyPinDir);

/**
  * @brief  : Set Status of Port (High or Low or Toggle)
  * @param  : CopyPortNum
  * @param  : CopyPinVal
  */
void Dio_setPortVal(u8 CopyPortNum,u8 CopyPinVal);

/**
  * @brief  : Get Status of Port (High or Low)
  * @param  : CopyPortNum
  * @RetVal : Ret
  */
Std_Return Dio_getPortVal(u8 CopyPortNum);


#endif /* MCAL_DIO_DIO_INIT_H_ */
