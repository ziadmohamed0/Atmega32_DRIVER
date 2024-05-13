/*
 * KeyPad_Prog.c
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */

/********** SECTION : Includes **********/
#include "KeyPad_Init.h"


extern u8 Pattern[NO_ROW][NO_COL];
extern u8 Row_Pin[NO_ROW];
extern u8 Col_Pin[NO_COL];
/********** SECTION : Functions Definitions **********/

/**
  * @brief  : Initialization KeyPad Pins
  * @param  : CopyKeyPad
  */
void keypad_vidInit()
{
	DIO_vidSetPinSDir(Row_Pin,NO_ROW,Direction_Pin_Input);
	DIO_vidSetPinSDir(Col_Pin,NO_COL,Direction_Pin_Output);
	DIO_vidSetPinSVal(Row_Pin,NO_ROW,Status_Pin_High);
	DIO_vidSetPinSVal(Col_Pin,NO_COL,Status_Pin_High);
}


/**
  * @brief  : Get Value From KeyPad Pins And Store It In CopyValue
  * @param  : CopyKeyPad
  * @param  : CopyValue
  */
u8 keypad_u8Stat(u8 *ptr)
{
	u8 i , j;
	u8 flag = 0;
	for(i = 0 ; i < 4 ; i++)
	{
		Dio_setPinVal(Col_Pin[i],Status_Pin_Low);
		for(j=0;j<4;j++)
		{
			if(Dio_getPinVal(Row_Pin[j]) == 0)
			{
				*ptr = Pattern[j][i];
				flag=1;
//				_delay_ms(20);
				while(Dio_getPinVal(Row_Pin[j])==0);
//				if(DIO_u8GetPinVal(Row_Pin[j]) == 0)
//				{
//					*ptr = Pattern[j][i];
//				}
				_delay_ms(20);
				Dio_setPinVal(Col_Pin[i],Status_Pin_High);
				return flag;
			}
		}
		Dio_setPinVal(Col_Pin[i],Status_Pin_High);
	}
	return flag;
}
