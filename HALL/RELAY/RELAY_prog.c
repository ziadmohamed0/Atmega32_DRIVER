/*
 * RELAY_prog.c
 *
 *  Created on: Jun 23, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "RELAY_init.h"

/*********** FUNCTIONS DEFIN ***********/
/**
 * @brief  : Relay function initializations to set directions output for relay's pin .
 * @param1 : void
 * @retVal : void
 */
void RELAY_init(void)
{
	DIO_setPinDIR(RELAY_PIN, _DIRECTION_PIN_OUTPUT);
}

/**
 * @brief  : Relay function turn on to set status high of relay's pin.
 * @param1 : void
 * @retVal : void
 */
void RELAY_turnON(void)
{
	DIO_setPinVAL(RELAY_PIN, _STATUS_PIN_HIGH);
}

/**
 * @brief  : Relay function turn off to set status low of relay's pin.
 * @param1 : void
 * @retVal : void
 */
void RELAY_turnOFF(void)
{
	DIO_setPinVAL(RELAY_PIN, _STATUS_PIN_LOW);
}
