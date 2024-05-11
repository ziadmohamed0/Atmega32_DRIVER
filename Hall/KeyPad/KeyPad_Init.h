/*
 * KeyPad_Init.h
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */

#ifndef HALL_KEYPAD_KEYPAD_INIT_H_
#define HALL_KEYPAD_KEYPAD_INIT_H_

/********** SECTION : Includes **********/
#include "KeyPad_Config.h"

/********** SECTION : Functions Declarations **********/

/**
  * @brief  : Initialization KeyPad Pins
  * @param  : CopyKeyPad
  */
void KeyPad_Init(KeyPad CopyKeyPad);

/**
  * @brief  : Get Value From KeyPad Pins And Store It In CopyValue
  * @param  : CopyKeyPad
  * @param  : CopyValue
  */
void KeyPad_getValue(KeyPad CopyKeyPad, u8 *CopyValue);

#endif /* HALL_KEYPAD_KEYPAD_INIT_H_ */
