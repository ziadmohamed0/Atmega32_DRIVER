/*
 * Lcd_Config.c
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "Lcd_Config.h"

/********** SECTION : LCDs **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood
LCD_8_MODE LCD8 = {

		.port[0] = PortA_p0,
		.port[1] = PortA_p1,
		.port[2] = PortA_p2,
		.port[3] = PortA_p3,
		.port[4] = PortA_p4,
		.port[5] = PortA_p5,
		.port[6] = PortA_p6,
		.port[7] = PortA_p7,
		.RS = PortB_p6,
		.E  = PortB_p7
};

#elif _LCD_Mood ==  _LCD_4_Bit_Mood

LCD_4_MODE LCD4 = {

		.Port[0] = PortB_p4,
		.Port[1] = PortB_p5,
		.Port[2] = PortB_p6,
		.Port[3] = PortB_p7,
		.RS = PortB_p2,
		.E  = PortB_p3,
};

#endif

