/*
 * TIMER0_Reg.h
 *
 *  Created on: May 25, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER0_TIMER0_REG_H_
#define MCAL_TIMER0_TIMER0_REG_H_

/************ INCLUDES ***********/
#include "../../Serv/Includes.h"
#include "../../Serv/Std_Types.h"
#include "../../Serv/Bit_Math.h"
#include "../EX_Intrrupt/EX_Init.h"

/************ VECTOR ***********/
#define TIMER0_OVF_VEC	__vector_11
#define TIMER0_COM_VEC	__vector_10

/************ REGISTERS ***********/
#define TCCR0   *((volatile u8 *) 0x53 )
#define TCNT0   *((volatile u8 *) 0x52 )
#define OCR0    *((volatile u8 *) 0x5C )
#define TIMSK   *((volatile u8 *) 0x59 )
#define TIFR    *((volatile u8 *) 0x58 )

/************ TCCR0 REGISTERS ***********/
typedef enum {
	CS00,
	CS01,
	CS02,
	WGM01,
	COM00,
	COM01,
	WGM00,
	FOC0
}TCCR0_BIT_Reg;

/************ TIMSK REGISTERS ***********/
typedef enum {
	TOIE0,
	OCIE0
}TIMSK_BIT_Reg;

#endif /* MCAL_TIMER0_TIMER0_REG_H_ */
