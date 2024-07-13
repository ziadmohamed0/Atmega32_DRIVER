/*
 * TIMER2_reg.h
 *
 *  Created on: Jun 30, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER2_TIMER2_REG_H_
#define MCAL_TIMER2_TIMER2_REG_H_

/*********** INCLUDES ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/*********** REGISTERS ***********/
#define TCCR2	*((volatile uint_8 *) 0x45)
#define TCNT2	*((volatile uint_8 *) 0x44)
#define OCR2	*((volatile uint_8 *) 0x43)
#define ASSR	*((volatile uint_8 *) 0x42)
#define TIMSK	*((volatile uint_8 *) 0x59)
#define TIFR	*((volatile uint_8 *) 0x58)
#define SFIOR	*((volatile uint_8 *) 0x50)

/*********** BITS ***********/
	/* ----- TCCR2 BITS ----- */
typedef enum
{
	CS20,
	CS21,
	CS22,
	WGM21,
	COM20,
	COM21,
	WGM20,
	FOC2
}_BITS_TCCR2;

	/* ----- ASSR BITS ----- */
typedef enum
{
	TCR2UB,
	OCR2UB,
	TCN2UB,
	AS2
}_BITS_ASSR;

	/* ----- TIMSK BITS ----- */
typedef enum
{
	TOIE2 = 6 ,
	OCIE2
}_TIMER2_BITS_TIMSK;

	/* ----- TIFR BITS ----- */
typedef enum
{
	TOV2 = 6 ,
	OCF2
}_TIMER2_BITS_TIFR;

	/* ----- SFIOR BITS ----- */
#define PSR2	1U

#endif /* MCAL_TIMER2_TIMER2_REG_H_ */
