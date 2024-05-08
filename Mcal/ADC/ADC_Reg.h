/*
 * ADC_Reg.h
 *
 *  Created on: May 5, 2024
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_


/* -------------------- Section : Interrupt -------------------- */
#define ADC_Vector	__vector_16

/* -------------------- Section : Registers -------------------- */
#define ADMUX_Reg	*((volatile u8 *)0x27)
#define ADCSRA_Reg	*((volatile u8 *)0x26)
#define ADCH_Reg	*((volatile u8 *)0x25)
#define ADCL_Reg	*((volatile u8 *)0x24)
#define SFIOR_Reg	*((volatile u8 *)0x50)
#define SREG_Reg    *((volatile u8 *)0x5F)

/*------- Section : ADMUX -------*/
#define ADMUX_ADLAR   (u8)5
#define ADMUX_REFS0   (u8)6
#define ADMUX_REFS1   (u8)7

/*------ Section : ADCSRA -------*/
#define ADCSRA_ADEN     (u8)7
#define ADCSRA_ADSC     (u8)6
#define ADCSRA_ADATE    (u8)5
#define ADCSRA_ADIF     (u8)4
#define ADCSRA_ADIE     (u8)3
#define ADCSRA_ADPS2    (u8)2
#define ADCSRA_ADPS1    (u8)1
#define ADCSRA_ADPS0    (u8)0

/*------- Section : SREG -------*/
#define GIE   7

#endif /* MCAL_ADC_ADC_REG_H_ */
