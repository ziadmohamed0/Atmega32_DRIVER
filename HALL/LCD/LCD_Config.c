/*
 * LCD_Config.c
 *
 *  Created on: May 28, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "LCD_Config.h"

/*********** LCDS ***********/
#if (_LCD_MODE == _8_BIT_MODE_LCD)
PINS_LCD LCD = {
				.PORT_DATA_PIN_NUM = _PORTB,
				.RS = PINA1,
				.EN = PINA0,
				.D[0] = PINB0,
				.D[1] = PINB1,
				.D[2] = PINB2,
				.D[3] = PINB3,
				.D[4] = PINB4,
				.D[5] = PINB5,
				.D[6] = PINB6,
				.D[7] = PINB7,
				};
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
PINS_LCD LCD = {
				.RS   = PINC0,
				.EN   = PINC1,
				.D[0] = PINC2,
				.D[1] = PINC3,
				.D[2] = PINC4,
				.D[3] = PINC5,
				};
#endif
