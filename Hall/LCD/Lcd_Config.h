/*
 * Lcd_Config.h
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

#ifndef HALL_LCD_LCD_CONFIG_H_
#define HALL_LCD_LCD_CONFIG_H_

/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"

/********** SECTION : STRUCTS **********/
typedef struct {
	u8	RS;
	u8	E;
	u8 port[8];
}LCD_8_MODE;

typedef struct {
	u8	RS;
	u8	E;
	u8	Port[4];
}LCD_4_MODE;

/********** SECTION : VARIABLES **********/
LCD_8_MODE LCD_1;
LCD_4_MODE LCD_2;

#endif /* HALL_LCD_LCD_CONFIG_H_ */
