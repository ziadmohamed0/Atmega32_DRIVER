/*
 * dio_Prog.c
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

/* -------------------- Section : Includes -------------------- */
#include "dio_Init.h"

/* -------------------- Section : Functions Definaions -------------------- */
volatile u8	*Arr_DDr[4]  =  {DDRA_REG ,DDRB_REG ,DDRC_REG ,DDRD_REG };
volatile u8	*Arr_Port[4] = {PORTA_REG ,PORTB_REG ,PORTC_REG ,PORTD_REG };
volatile u8	*Arr_Pin[4]  = {PINA_REG ,PINB_REG ,PINC_REG ,PIND_REG };

/* -------------------- Section : Pins Functions Definaions -------------------- */

/**
  * @brief  : Set Direction of Bit (Input or Output)
  * @param  : CopyPinNum
  * @param  : CopyPinDir
  */
void Dio_setPinDir(u8 CopyPinNum,u8 CopyPinDir)
{
	switch (CopyPinDir)
	{
		case Direction_Pin_Output:
				SET_BIT(*Arr_DDr[CopyPinNum / 8 ],CopyPinNum % 8 );
			break;

		case Direction_Pin_Input:
				CLR_BIT(*Arr_DDr[CopyPinNum / 8 ],CopyPinNum % 8 );
			break;

		default :
			break;
	}
}


/**
  * @brief  : Set Status of Bit (High or Low or Toggle)
  * @param  : CopyPinNum
  * @param  : CopyPinVal
  */
void Dio_setPinVal(u8 CopyPinNum,u8 CopyPinVal)
{
	switch (CopyPinVal)
	{
		case Status_Pin_High:
				SET_BIT(*Arr_Port[CopyPinNum / 8 ],CopyPinNum % 8 );
			break;

		case Status_Pin_Low:
				CLR_BIT(*Arr_Port[CopyPinNum / 8 ],CopyPinNum % 8 );
			break;

		case Status_Pin_Toggle:
				TOGGLE_BIT(*Arr_Port[CopyPinNum / 8 ],CopyPinNum % 8 );
			break;

		default :
			break;
	}
}

/**
  * @brief  : Get Status of Bit (High or Low)
  * @param  : CopyPinNum
  * @RetVal : Ret
  */
Std_Return Dio_getPinVal(u8 CopyPinNum)
{
	u8 Ret = 0;
	Ret = GET_BIT(*Arr_Pin[CopyPinNum / 8 ],CopyPinNum % 8 );
	return Ret;
}

/**
  * @brief  : Set Direction of Some Bit From u8PinsNum to Copyu8Size (Input or Output)
  * @param  : u8PinsNum
  * @param  : Copyu8Size
  * @param  : Copyu8Dir
  */
void DIO_vidSetPinSDir(u8 * u8PinsNum,u8 Copyu8Size,u8 Copyu8Dir)
{
	u8 i;
	for(i=0;i<Copyu8Size;i++)
	{
		switch (Copyu8Dir)
		{
		case Direction_Pin_Input  :CLR_BIT((*Arr_DDr[u8PinsNum[i] / 8]), (u8PinsNum[i] % 8));break;
		case Direction_Pin_Output :SET_BIT((*Arr_DDr[u8PinsNum[i] / 8]), (u8PinsNum[i] % 8));break;
		}
	}
}

/**
  * @brief  : Set Status of Some Bit From u8PinsNum to Copyu8Size (High or Low or Toggle)
  * @param  : u8PinsNum
  * @param  : Copyu8Size
  * @param  : Copyu8Val
  */
void DIO_vidSetPinSVal(u8 * u8PinsNum,u8 Copyu8Size,u8 Copyu8Val)
{
	u8 i;
	for(i=0;i<Copyu8Size;i++)
	{
		switch (Copyu8Val)
		{
		case Status_Pin_Low  :CLR_BIT(*Arr_Port[u8PinsNum[i] / 8], u8PinsNum[i] % 8);break;
		case Status_Pin_High :SET_BIT(*Arr_Port[u8PinsNum[i] / 8], u8PinsNum[i] % 8);break;
		}
	}
}


/* -------------------- Section : Ports Functions Definaions -------------------- */

/**
  * @brief  : Set Direction of Port (Input or Output)
  * @param  : CopyPortNum
  * @param  : CopyPinDir
  */
void Dio_setPortDir(u8 CopyPortNum,u8 CopyPinDir)
{
	*Arr_DDr[CopyPortNum] = CopyPinDir;
}

/**
  * @brief  : Set Status of Port (High or Low or Toggle)
  * @param  : CopyPortNum
  * @param  : CopyPinVal
  */
void Dio_setPortVal(u8 CopyPortNum,u8 CopyPinVal)
{
	*Arr_Port[CopyPortNum] = CopyPinVal;
}

/**
  * @brief  : Get Status of Port (High or Low)
  * @param  : CopyPortNum
  * @RetVal : Ret
  */
Std_Return Dio_getPortVal(u8 CopyPortNum)
{
	u8 Ret = 0;
	Ret = *Arr_Pin[CopyPortNum];
	return Ret;
}
