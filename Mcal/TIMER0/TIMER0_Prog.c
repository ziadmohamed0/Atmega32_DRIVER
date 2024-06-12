/*
 * TIMER0_Prog.c
 *
 *  Created on: May 25, 2024
 *      Author: ziad
 */
/************ INCLUDES ***********/
#include "TIMER0_Init.h"

/************ FUNCTIONS DIFEN ***********/
void TIMER0_Init(void)
{
#if TIMER_MODE_WAVE == NORMAL_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER_MODE_WAVE == PWM_MODE
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif TIMER_MODE_WAVE == CTC_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif TIMER_MODE_WAVE == FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#endif
}


void TIMER0_Start(void)
{
	TCCR0 |= TIMER_SELECT_ENABLE;
}

void TIMER0_Stop(void)
{
	TCCR0 &= TIMER0_CLOCK_STOP;
}

void TIMER0_writeOVR(u8 Copy_Start_Value)
{
	TCNT0 = Copy_Start_Value;
}

void TIMER0_writeCOM(u8 Copy_Start_Value)
{
	OCR0 = Copy_Start_Value;
}

void TIMER0_ovrInterruptEnable(void)
{
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,TOIE0);
}

void TIMER0_ovrInterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}

void TIMER0_compInterruptEnable(void)
{
	SET_BIT(SREG,SREG_GIE);
	SET_BIT(TIMSK,OCIE0);
}

void TIMER0_comInterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}
