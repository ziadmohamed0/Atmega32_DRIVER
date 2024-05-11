/*
 * ADC_Prog.c
 *
 *  Created on: May 5, 2024
 *      Author: ziad
 */

/* -------------------- Section : Includes -------------------- */
#include "ADC_Init.h"

/* -------------------- Section : Functions -------------------- */

/**
  * @brief  : Initialization ADC
  */
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

/**
  * @brief  : Conversion Digital Signal to Analog Signal And Return The Result
  * @param  : CopyChanal
  * @retval : Res
  */
u16 ADC_readDigitalSignal(ADC_CHANNEL CopyChanal)
{
	u16 Res = Initial_Counter;
	ADMUX_Reg &= ADC_CLEAR_MASK;
	ADMUX_Reg |= CopyChanal;
	SET_BIT(ADCSRA_Reg,ADCSRA_ADSC);
	while((GET_BIT(ADCSRA_Reg,ADCSRA_ADSC)));
	Res = ADCL_Reg;
	Res |= (ADCH_Reg << 8);
	return Res;
}

/**
  * @brief  : Enable ADC
  */
void ADC_Enable(void)
{
	SET_BIT(ADCSRA_Reg,ADCSRA_ADEN);
}

/**
  * @brief  : Disable ADC
  */
void ADC_Disable(void)
{
	CLR_BIT(ADCSRA_Reg,ADCSRA_ADEN);
}

/**
  * @brief  : Enable Interrupt of ADC
  */
void ADC_EnableINT(void)
{
	SET_BIT(SREG_Reg , GIE);
	SET_BIT(ADCSRA_Reg, ADCSRA_ADIE);
}

/**
  * @brief  : Disable Interrupt of ADC
  */
void ADC_DisableINT(void)
{
	CLR_BIT(ADCSRA_Reg, ADCSRA_ADIE);
}

/**
  * @brief  : Clear The ADCSRA_ADIF Bit
  */
void ADC_CLRflag(void)
{
	CLR_BIT(ADCSRA_Reg , ADCSRA_ADIF);
}
