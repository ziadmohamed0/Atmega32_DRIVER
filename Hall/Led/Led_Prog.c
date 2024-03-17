/*
 * Led_Prog.c
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

/* -------------------- Section : Includes -------------------- */
#include "Led_Init.h"

/**
 *@ brief : Function To Control Port Of Leds With Bush Button
 *@ Param1 : CopyPortOutNum : Led Port Number
 *@ Param2 : CopyBottonPin : Button  On Pin Number
 *@ Param3 : CopyBottonPin : Button Off Pin Number
 */
void Led_On_PortLeds_Button(u8 CopyPortOutNum , u8 CopyButtonPin_On , u8 CopyButtonPin_Off )
{
		/* ===== Port of Leds Declaration ===== */
		Dio_setPortDir(CopyPortOutNum,Direction_Port_Output);

		/* ===== Pin of Buttons Declaration ===== */
		Dio_setPinDir(CopyButtonPin_On , Direction_Pin_Input);
		Dio_setPinDir(CopyButtonPin_Off , Direction_Pin_Input);

		/* ========== If Button Pressed Led Is On ========== */
		if(Dio_getPinVal(CopyButtonPin_On) == Status_Pin_Low)
		{
			Dio_setPortVal(CopyPortOutNum, Status_Port_High);
		}

		/* ========== If Button Pressed Led Is Off ========== */
		if(Dio_getPinVal(CopyButtonPin_Off) == Status_Pin_Low)
		{
			Dio_setPortVal(CopyPortOutNum, Status_Port_Low);
		}

}
/**
 *@ brief : Function To Control Led With Bush Button
 *@ Param1 : CopyPinOutNum : Led Pin Number
 *@ Param2 : CopyBottonPin : Button  On Pin Number
 *@ Param3 : CopyBottonPin : Button Off Pin Number
 */
void Led_On_OneLed_Button(u8 CopyPinOutNum ,u8 CopyButtonPin_On , u8 CopyButtonPin_Off)
{
	/* ===== Pin of Led Declaration ===== */
	Dio_setPinDir(CopyPinOutNum , Direction_Pin_Output);

	/* ===== Pins of Buttons Declaration ===== */
	Dio_setPinDir(CopyButtonPin_On , Direction_Pin_Input);
	Dio_setPinDir(CopyButtonPin_Off , Direction_Pin_Input);

	/* ========== If Button Pressed Led Is On ========== */
	if(Dio_getPinVal(CopyButtonPin_On) == Status_Pin_Low)
	{
		Dio_setPinVal(CopyPinOutNum , Status_Pin_High);
	}

	/* ========== If Button Pressed Led Is Off ========== */
	if(Dio_getPinVal(CopyButtonPin_Off) == Status_Pin_Low)
	{
		Dio_setPortVal(CopyPinOutNum, Status_Port_Low);
	}
}
