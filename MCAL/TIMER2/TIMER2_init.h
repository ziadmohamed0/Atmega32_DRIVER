/*
 * TIMER2_init.h
 *
 *  Created on: Jun 30, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER2_TIMER2_INIT_H_
#define MCAL_TIMER2_TIMER2_INIT_H_

/*********** INCLUDES ***********/
#include "TIMER2_config.h"

/************ FUNCTIONS DECLER ***********/
/**
 * @brief  : Timer/Counter {2} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER2_Init(_TIMER2_PRESCALER_SELECT_ copyPrescaler);

/**
 * @brief  : Timer/Counter {2} Start counting by select prescaler from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER2_Start(_TIMER2_PRESCALER_SELECT_ copyPrescaler);

/**
 * @brief  : Timer/Counter {2} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_Stop(void);

/**
 * @brief  : Timer/Counter {2} write over flow by put start value over flow.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER2_writeOVR(uint_8 Copy_Start_Value);

/**
 * @brief  : Timer/Counter {2} write Compare match put start value comparing.
 * @param1 : Copy_Start_Value
 * @retVal : void
 */
void TIMER2_writeCOM(uint_8 Copy_Start_Value);

/**
 * @brief  : Timer/Counter {2} interrupt over flow enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_ovrInterruptEnable(void);

/**
 * @brief  : Timer/Counter {2} interrupt over flow disable by write zero in TIMSK register in TOIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_ovrInterruptDisable(void);

/**
 * @brief  : Timer/Counter {2} interrupt Compare match enable by write one in SREG register in GIE bit
 * 			 &  write one in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_compInterruptEnable(void);

/**
 * @brief  : Timer/Counter {2} interrupt Compare match disable by write zero in TIMSK register in OCIE0 bit.
 * @param1 : void
 * @retVal : void
 */
void TIMER2_comInterruptDisable(void);

#endif /* MCAL_TIMER2_TIMER2_INIT_H_ */
