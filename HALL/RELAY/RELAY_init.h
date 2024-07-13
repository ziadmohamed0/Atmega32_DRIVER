/*
 * RELAY_init.h
 *
 *  Created on: Jun 23, 2024
 *      Author: ziad
 */

#ifndef HALL_RELAY_RELAY_INIT_H_
#define HALL_RELAY_RELAY_INIT_H_

/*********** INCLUDES ***********/
#include "RELAY_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : Relay function initializations to set directions output for relay's pin .
 * @param1 : void
 * @retVal : void
 */
void RELAY_init(void);

/**
 * @brief  : Relay function turn on to set status high of relay's pin.
 * @param1 : void
 * @retVal : void
 */
void RELAY_turnON(void);

/**
 * @brief  : Relay function turn off to set status low of relay's pin.
 * @param1 : void
 * @retVal : void
 */
void RELAY_turnOFF(void);

#endif /* HALL_RELAY_RELAY_INIT_H_ */
