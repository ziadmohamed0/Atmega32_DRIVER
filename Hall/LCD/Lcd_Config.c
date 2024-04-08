/*
 * Lcd_Config.c
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "Lcd_Config.h"

/********** SECTION : Variable_Definations **********/
LCD_8_MODE LCD_1 = {
		.RS = PortC_p6,
		.E  = PortC_p7,
		.port[0] = PortD_p0,
		.port[1] = PortD_p1,
		.port[2] = PortD_p2,
		.port[3] = PortD_p3,
		.port[4] = PortD_p4,
		.port[5] = PortD_p5,
		.port[6] = PortD_p6,
		.port[7] = PortD_p7
};

LCD_4_MODE LCD_2 = {
		.RS = PortA_p6,
		.E  = PortA_p7,
		.Port[0] = PortB_p0,
		.Port[1] = PortB_p1,
		.Port[2] = PortB_p2,
		.Port[3] = PortB_p3
};
