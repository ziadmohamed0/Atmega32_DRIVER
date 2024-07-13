/*
 * TIMER0_config.h
 *
 *  Created on: Jun 16, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

/************ INCLUDE ***********/
#include "TIMER0_reg.h"


/*********************************************/
/* micro_TIK-Time = (scaler / CPU_freq)*10^6 */
/* milli_TIK-Time = (scaler / CPU_freq)*10^3 */
/*********************************************/

/*********** TIMER MODE ***********/
#define _TIMER0_NORMAL_MODE 	0U
#define _TIMER0_CTC_MODE 		1U
#define _TIMER0_PWM_MODE 		2U
#define _TIMER0_FAST_PWM_MODE 	3U

#define _TIMER_MODE_WAVE 	_TIMER0_NORMAL_MODE

/*********** TIMER COMPAR MATCH MODE ***********/
#define _TIMER0_OC0_DISCONNECTED 	0U
#define _TIMER0_OC0_TOGGLE 			1U
#define _TIMER0_OC0_NON_INVERTING 	2U
#define _TIMER0_OC0_INVERTING 		3U

#define _TIMER0_COM_OC0	_TIMER0_OC0_DISCONNECTED

/*********** TIMER PRESCALER ***********/

	/* --- TIMER SELSET PRESCLER --- */
typedef enum
{
	_TIMER0_NO_PRESCLER,
	_TIMER0_1_PRESCLER,
	_TIMER0_8_PRESCLER,
	_TIMER0_64_PRESCLER,
	_TIMER0_256_PRESCLER,
	_TIMER0_1024_PRESCLER,
	_TIMER0_FALLING_PRESCLER,
	_TIMER0_RISING_PRESCLER
}_TIMER0__PRESCALER_SELECT_;

#define TIMER0_CLOCK_STOP    (uint_8)0xF8

	/* --- Compare Output Mode USED In PWM Mode --- */

#define NURMAL_MODE_OUTPUT       (( 0 << COM01) | (0 << COM00))         //(0U << COM00)
#define TOGGLE_CTC_MODE          (( 0 << COM01) | (1 << COM00))
#define START_CLEAR_COMP         (( 1 << COM01) | (0 << COM00))        //(2U << COM00)
#define START_SET_COMP           (( 1 << COM01) | (1 << COM00))         //(3U << COM00)


#define TIMER_COMP_OUTPUT_MODE   TOGGLE_CTC_MODE

#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
