/*
 * TIMER1_prog.c
 *
 *  Created on: Jun 19, 2024
 *      Author: ziad
 */
/************ INCLUDE ***********/
#include "TIMER1_init.h"

/************ FUNCTIONS DECLER ***********/
/**
 * @brief  : Timer/Counter {1} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER1_Init(_TIMER1__PRESCALER_SELECT_ copyPrescaler)
{
	TCCR1B |= copyPrescaler;

#if (_TIMER1_MODE_WAVE == _TIMER1_NORMAL_MODE)
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif (_TIMER1_MODE_WAVE == _TIMER1_CTC_MODE)
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
#elif (_TIMER1_MODE_WAVE == _TIMER1_PWM_MODE)
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif (_TIMER1_MODE_WAVE == _TIMER1_FAST_PWM_MODE)
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#endif

#if (_TIMER1_COM_OC1 == _TIMER1_OC1_DISCONNECTED)
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
#elif (_TIMER1_COM_OC1 == _TIMER1_OC1_TOGGLE)
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
#elif (_TIMER1_COM_OC1 == _TIMER1_OC1_NON_INVERTING)
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#elif (_TIMER1_COM_OC1 == _TIMER1_OC1_INVERTING)
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#endif
}

/**
 * @brief  : Timer/Counter {1} Start counting by select prescaler from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER1_Start(_TIMER1__PRESCALER_SELECT_ copyPrescaler)
{
	TCCR1B |= copyPrescaler;
}

/**
 * @brief  : Timer/Counter {1} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER1_Stop(void)
{
	TCCR1B &= TIMER1_CLOCK_STOP;
}
