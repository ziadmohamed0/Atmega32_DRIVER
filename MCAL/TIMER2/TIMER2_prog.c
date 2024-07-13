/*
 * TIMER2_prog.c
 *
 *  Created on: Jun 30, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "TIMER2_init.h"

/************ FUNCTIONS DEFIN ***********/
/**
 * @brief  : Timer/Counter {2} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER2_Init(_TIMER2_PRESCALER_SELECT_ copyPrescaler)
{
	TCCR2 |= copyPrescaler;
#if (TIMER2_CLK_SOURCE == TIEMR2_INT)
	CLR_BIT(ASSR,AS2);
#elif (TIMER2_CLK_SOURCE == TIMER2_EXTR)
	SET_BIT(ASSR,AS2);
#endif

#if (_TIMER2_MODE_WAVE == _TIMER2_NORMAL_MODE)
	CLR_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
#elif (_TIMER2_MODE_WAVE == _TIMER2_CTC_MODE)
	CLR_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,WGM20);
#elif (_TIMER2_MODE_WAVE == _TIMER2_PWM_MODE)
	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
#elif (_TIMER2_MODE_WAVE == _TIMER2_FAST_PWM_MODE)
	SET_BIT(TCCR2,WGM21);
	SET_BIT(TCCR2,WGM20);
#endif

#if (_TIMER2_COM_OC2 == _TIMER2_OC2_DISCONNECTED)
	CLR_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
#elif (_TIMER2_COM_OC2 == _TIMER2_OC2_TOGGLE)
	CLR_BIT(TCCR2,COM21);
	SET_BIT(TCCR2,COM20);
#elif (_TIMER2_COM_OC2 == _TIMER2_OC2_NON_INVERTING)
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
#elif (_TIMER2_COM_OC2 == _TIMER2_OC2_INVERTING)
	SET_BIT(TCCR2,COM21);
	SET_BIT(TCCR2,COM20);
#endif
}

/**
 * @brief  : Timer/Counter {2} Start counting by select prescaler from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER2_Start(_TIMER2_PRESCALER_SELECT_ copyPrescaler)
{
	TCCR2 |= copyPrescaler;
}

/**
 * @brief  : Timer/Counter {2} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_Stop(void)
{
	TCCR2 &= TIMER2_CLOCK_STOP;
}

/**
 * @brief  : Timer/Counter {2} write over flow by put start value over flow.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER2_writeOVR(uint_8 Copy_Start_Value)
{
	TCNT2 = Copy_Start_Value;
}

/**
 * @brief  : Timer/Counter {2} write Compare match put start value comparing.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER2_writeCOM(uint_8 Copy_Start_Value)
{
	OCR2 = Copy_Start_Value;
}

/**
 * @brief  : Timer/Counter {2} interrupt over flow enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_ovrInterruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE2);
}

/**
 * @brief  : Timer/Counter {2} interrupt over flow disable by write zero in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_ovrInterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE2);
}

/**
 * @brief  : Timer/Counter {2} interrupt Compare match enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_compInterruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE2);
}

/**
 * @brief  : Timer/Counter {2} interrupt Compare match disable by write zero in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_comInterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE2);
}
