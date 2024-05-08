/*
 * ADC_Init.h
 *
 *  Created on: May 5, 2024
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "../../Serv/Bit_Math.h"
#include "../../Serv/Std_Types.h"
#include "../../Serv/Includes.h"
#include "ADC_Config.h"

/* -------------------- Section : Enums -------------------- */
typedef enum
{
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7,
	ADC_CHANNEL8
}ADC_CHANNEL;

/* -------------------- Section : Functions -------------------- */
void ADC_INIT(void);
u8 ADC_readDigitalSignal(ADC_CHANNEL CopyChanal);
void ADC_Enable(void);
void ADC_Disable(void);

void ADC_EnableINT(void);
void ADC_DisableINT(void);

void ADC_CLRflag(void);

#endif /* MCAL_ADC_ADC_INIT_H_ */
