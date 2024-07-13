/*
 * TIMER1_reg.h
 *
 *  Created on: Jun 19, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER1_TIMER1_REG_H_
#define MCAL_TIMER1_TIMER1_REG_H_

/************ INCLUDE ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/************ REGISTERS ***********/
#define TCCR1A  *((volatile uint_8 *) 0x4F)
#define TCCR1B  *((volatile uint_8 *) 0x4E)
#define TCNT1H  *((volatile uint_8 *) 0x4D)
#define TCNT1L  *((volatile uint_8 *) 0x4C)
#define OCR1AH  *((volatile uint_8 *) 0x4B)
#define OCR1AL  *((volatile uint_8 *) 0x4A)
#define OCR1BH  *((volatile uint_8 *) 0x49)
#define OCR1BL  *((volatile uint_8 *) 0x48)
#define ICR1H   *((volatile uint_8 *) 0x47)
#define ICR1L   *((volatile uint_8 *) 0x46)
#define TIMSK   *((volatile uint_8 *) 0x59)
#define TIFR   	*((volatile uint_8 *) 0x58)

/************ BITS ***********/

	/* ----- TCCR1A BITS ----- */
typedef enum
{
	WGM10,
	WGM11,
	FOC1B,
	FOC1A,
	COM1B0,
	COM1B1,
	COM1A0,
	COM1A1
}_BITS_TCCR1A;

	/* ----- TCCR1B BITS ----- */
typedef enum
{
	CS10,
	CS11,
	CS12,
	WGM12,
	WGM13,
	Reserved,
	ICES1,
	ICNC1
}_BITS_TCCR1B;

	/* ----- TIMSK BITS ----- */
typedef enum
{
	TOIE1 = 2,
	OCIE1B,
	OCIE1A,
	TICIE1
}_BITS_TIMSK;

	/* ----- TIFR BITS ----- */
typedef enum
{
	TOV1 = 2,
	OCF1B,
	OCF1A,
	ICF1
}_BITS_TIFR;

#endif /* MCAL_TIMER1_TIMER1_REG_H_ */
