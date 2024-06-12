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
				.PORT_DATA_PIN_NUM = PORTB_reg,
				.EN = PortA_p1,
				.RS = PortA_p0,
				.D[0] = PortB_p0,
				.D[1] = PortB_p1,
				.D[2] = PortB_p2,
				.D[3] = PortB_p3,
				.D[4] = PortB_p4,
				.D[5] = PortB_p5,
				.D[6] = PortB_p6,
				.D[7] = PortB_p7,
				};
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
PINS_LCD LCD = {
				.PORT_DATA_PIN_NUM = PORTA_reg,
				.EN   = PortA_p1,
				.RS   = PortA_p0,
				.D[0] = PortA_p4,
				.D[1] = PortA_p5,
				.D[2] = PortA_p6,
				.D[3] = PortA_p7,
				};
#endif
