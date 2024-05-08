/*
 * ADC_Prog.c
 *
 *  Created on: May 5, 2024
 *      Author: ziad
 */

/* -------------------- Section : Includes -------------------- */
#include "ADC_Init.h"

/* -------------------- Section : Functions -------------------- */
void ADC_INIT(void)
{
#if	ADC_Stat == ADC_AREF
	CLR_BIT(ADMUX_Reg , ADMUX_REFS0);
	CLR_BIT(ADMUX_Reg , ADMUX_REFS1);
#elif ADC_Stat == ADC_AVCC
	SET_BIT(ADMUX_Reg , ADMUX_REFS0);
	CLR_BIT(ADMUX_Reg , ADMUX_REFS1);
#elif ADC_Stat == ADC_Inter
	SET_BIT(ADMUX_Reg , ADMUX_REFS0);
	SET_BIT(ADMUX_Reg , ADMUX_REFS1);
#endif
	SET_BIT(ADCSRA_Reg,ADCSRA_ADEN);
	ADCSRA_Reg |= ADC_PRESCALER;
}
u8 ADC_readDigitalSignal(ADC_CHANNEL CopyChanal)
{

	return 0;
}

void ADC_Enable(void)
{
	SET_BIT(ADCSRA_Reg,ADCSRA_ADEN);
}
void ADC_Disable(void)
{
	CLR_BIT(ADCSRA_Reg,ADCSRA_ADEN);
}


void ADC_EnableINT(void)
{
	SET_BIT(SREG_Reg , GIE);
	SET_BIT(ADCSRA_Reg, ADCSRA_ADIE);
}
void ADC_DisableINT(void)
{
	CLR_BIT(ADCSRA_Reg, ADCSRA_ADIE);
}

void ADC_CLRflag(void)
{
	CLR_BIT(ADCSRA_Reg , ADCSRA_ADIF);
}
