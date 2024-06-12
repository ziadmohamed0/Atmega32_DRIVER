/*
 * Initialized_Prog.c
 *
 *  Created on: Apr 8, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "Initialize_Init.h"

/********** SECTION : Global Area **********/
u8 Var;
u8 data;

/********** SECTION : Functions setUp Definitions **********/

/**
* @brief  : Function to Initialization All Peripherals
*/
void App_Init(void)
{
	UART_init(BAUD_9600);
	LCD_init(LCD);
//	LCD_writeChar(LCD,'x');
//	LCD_goTo(LCD, ROW2, 1);
//	LCD_writeChar(LCD,'z');
}
/********** SECTION : Functions Loop Definitions **********/
/**
* @brief  : Function to Looping My Program
*/
void App_Loop(void)
{
	if(UART_reciveData(&Var))
	{
		LCD_writeChar(LCD, Var);
	}
	else
	{

	}
	_delay_ms(200);
}

