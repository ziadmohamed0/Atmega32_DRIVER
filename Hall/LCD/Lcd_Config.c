/*
 * Lcd_Config.c
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "Lcd_Config.h"

/********** SECTION : Variable_Definations **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood
LCD_8_MODE LCD_1 = {
		.RS = PortA_p6,
		.E  = PortA_p7,
		.port[0] = PortB_p0,
		.port[1] = PortB_p1,
		.port[2] = PortB_p2,
		.port[3] = PortB_p3,
		.port[4] = PortB_p4,
		.port[5] = PortB_p5,
		.port[6] = PortB_p6,
		.port[7] = PortB_p7
};

#elif _LCD_Mood ==  _LCD_4_Bit_Mood

LCD_4_MODE LCD_2 = {
		.RS = PortA_p6,
		.E  = PortA_p7,
		.Port[0] = PortB_p0,
		.Port[1] = PortB_p1,
		.Port[2] = PortB_p2,
		.Port[3] = PortB_p3
};

#endif

