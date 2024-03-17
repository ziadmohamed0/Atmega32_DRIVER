/*
 * Main.c
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

#include "Main_Init.h"

int main (void)
{
	Dio_setPortDir(PORTD,Direction_Port_Output);
	Dio_setPortDir(PORTB,Direction_Port_Output);
	while(1)
	{
		Dio_setPortVal(PORTD, 0x80);
		_delay_ms(500);
		Dio_setPortVal(PORTB, 0x80);
		_delay_ms(500);


		Dio_setPortVal(PORTD, 0x7F);
		_delay_ms(500);
		Dio_setPortVal(PORTB, 0x7F);
		_delay_ms(500);
	}
}
