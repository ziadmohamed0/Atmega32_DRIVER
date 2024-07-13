/*
 * TIMER0_prog.c
 *
 *  Created on: Jun 16, 2024
 *      Author: ziad
 */
/************ INCLUDE ***********/
#include "TIMER0_init.h"

/************ FUNCTIONS DIFEN ***********/
/**
 * @brief  : Timer/Counter {0} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER0_Init(_TIMER0__PRESCALER_SELECT_ copyPrescaler)
{
#if (_TIMER_MODE_WAVE == _TIMER0_NORMAL_MODE)
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,FOC0);
#elif (_TIMER_MODE_WAVE == _TIMER0_CTC_MODE)
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif (_TIMER_MODE_WAVE == _TIMER0_PWM_MODE)
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif (_TIMER_MODE_WAVE == _TIMER0_FAST_PWM_MODE)
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#endif

#if (_TIMER0_COM_OC0 == _TIMER0_OC0_DISCONNECTED)
	CLR_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
#elif	(_TIMER0_COM_OC0 == _TIMER0_OC0_INVERTING)
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
#elif	(_TIMER0_COM_OC0 == _TIMER0_OC0_NON_INVERTING)
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
#elif	(_TIMER0_COM_OC0 == _TIMER0_OC0_TOGGLE)
	CLR_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
#endif
	TCCR0 &= TIMER0_CLOCK_STOP ;
	TCCR0 |= copyPrescaler;
}

/**
 * @brief  : Timer/Counter {0} Start counting by select prescaler from configuration file.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Start(_TIMER0__PRESCALER_SELECT_ copyPrescaler)
{
	TCCR0 |= copyPrescaler;
}

/**
 * @brief  : Timer/Counter {0} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_Stop(void)
{
	TCCR0 &= TIMER0_CLOCK_STOP;
}

/**
 * @brief  : Timer/Counter {0} write over flow by put start value over flow.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER0_writeOVR(uint_8 Copy_Start_Value)
{
	TCNT0 = Copy_Start_Value;
}

/**
 * @brief  : Timer/Counter {0} write Compare match put start value comparing.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER0_writeCOM(uint_8 Copy_Start_Value)
{
	OCR0 = Copy_Start_Value;
}

/**
 * @brief  : Timer/Counter {0} interrupt over flow enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_ovrInterruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE0);
}

/**
 * @brief  : Timer/Counter {0} interrupt over flow disable by write zero in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_ovrInterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}

/**
 * @brief  : Timer/Counter {0} interrupt Compare match enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_compInterruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE0);
}

/**
 * @brief  : Timer/Counter {0} interrupt Compare match disable by write zero in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER0_comInterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}

