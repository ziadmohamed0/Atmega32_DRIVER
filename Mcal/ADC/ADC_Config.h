/*
 * ADC_Config.h
 *
 *  Created on: May 5, 2024
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/* -------------------- Section : Includes -------------------- */
#include "../EX_Intrrupt/EX_Init.h"
#include "ADC_Reg.h"

/* -------------------- Section : Voltage Reference Configuration -------------------- */
#define ADC_AREF	0
#define ADC_AVCC	1
#define ADC_Inter	2
#define ADC_Stat	ADC_AVCC

/* -------------------- Section : ADC Clear -------------------- */
#define ADC_CLEAR_MASK  (u8)0xE0

/* -------------------- Section : ADC PRESCALER Configuration -------------------- */
#define ADC_DIVISION_FACTOR_2        (u8)0x01
#define ADC_DIVISION_FACTOR_4        (u8)0x02
#define ADC_DIVISION_FACTOR_8        (u8)0x03
#define ADC_DIVISION_FACTOR_16       (u8)0x04
#define ADC_DIVISION_FACTOR_32       (u8)0x05
#define ADC_DIVISION_FACTOR_64       (u8)0x06
#define ADC_DIVISION_FACTOR_128      (u8)0x07

#define ADC_PRESCALER   ADC_DIVISION_FACTOR_2

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
