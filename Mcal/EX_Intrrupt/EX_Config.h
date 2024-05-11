/*
 * EX_Config.h
 *
 *  Created on: May 3, 2024
 *      Author: ziad
 */

#ifndef MCAL_EX_CONFIG_H_
#define MCAL_EX_CONFIG_H_

/* -------------------- Section : Includes -------------------- */
#include "../../Serv/Bit_Math.h"
#include "../../Serv/Std_Types.h"
#include "../../Serv/Includes.h"
#include "EX_Reg.h"
/* -------------------- Section : Enums -------------------- */

/* ========== Pins of External Interrupt ========== */
typedef enum
{
	IN0,
	IN1,
	IN2
}EX_Interrupt_Num;


/* ========== Directions of External Interrupt ========== */
typedef enum
{
	LOW_LEVEL,
	ANY_LOGIC,
	FALLING_EDGE,
	RISING_AGE
}EX_Interrupt_Dir;

#endif /* MCAL_EX_CONFIG_H_ */
