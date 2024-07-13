/*
 * TIMER1_init.h
 *
 *  Created on: Jun 19, 2024
 *      Author: ziad
 */

#ifndef MCAL_TIMER1_TIMER1_INIT_H_
#define MCAL_TIMER1_TIMER1_INIT_H_

/************ INCLUDE ***********/
#include "TIMER1_config.h"

/************ FUNCTIONS DECLER ***********/
/**
 * @brief  : Timer/Counter {1} initialization function by select timer wave mode
 *			 from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER1_Init(_TIMER1__PRESCALER_SELECT_ copyPrescaler);

/**
 * @brief  : Timer/Counter {1} Start counting by select prescaler from configuration file.
 * @param1 : copyPrescaler
 * @retVal : void
 */
void TIMER1_Start(_TIMER1__PRESCALER_SELECT_ copyPrescaler);

/**
 * @brief  : Timer/Counter {1} Stop counting.
 * @param1 : void
 * @retVal : void
 */
void TIMER1_Stop(void);

#endif /* MCAL_TIMER1_TIMER1_INIT_H_ */
