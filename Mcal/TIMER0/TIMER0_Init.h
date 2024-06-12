/*
 * TIMER0_Init0.h
 *
 *  Created on: May 25, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER0_TIMER0_INIT_H_
#define MCAL_TIMER0_TIMER0_INIT_H_

/************ INCLUDES ***********/
#include "TIMER0_Config.h"

/************ FUNCTIONS DECLER ***********/
void TIMER0_Init(void);

void TIMER0_Start(void);
void TIMER0_Stop(void);

void TIMER0_writeOVR(u8 Copy_Start_Value);
void TIMER0_writeCOM(u8 Copy_Start_Value);

void TIMER0_ovrInterruptEnable(void);
void TIMER0_ovrInterruptDisable(void);

void TIMER0_compInterruptEnable(void);
void TIMER0_comInterruptDisable(void);

#endif /* MCAL_TIMER0_TIMER0_INIT_H_ */
