/*
 * Dc_Motor_Prog.c
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"
#include "Dc_Motor_Init.h"

/********** SECTION : Functions Definitions **********/
void Motor_Init(void)
{
	Dio_setPinDir(m1.ENA, Direction_Pin_Output);
	Dio_setPinDir(m1.IN1, Direction_Pin_Output);
	Dio_setPinDir(m1.IN2, Direction_Pin_Output);

	Dio_setPinDir(m2.ENB, Direction_Pin_Output);
	Dio_setPinDir(m2.IN3, Direction_Pin_Output);
	Dio_setPinDir(m2.IN4, Direction_Pin_Output);
}


void Motor_Forward(u8 CopyMotorNum)
{
	switch(CopyMotorNum)
	{
	case Motor_1:
		Dio_setPinVal(m1.ENA, m1.ENA_Status);
		Dio_setPinVal(m1.IN1, Status_Pin_High);
		Dio_setPinVal(m1.IN2, Status_Pin_Low);
		break;
	case Motor_2:
		Dio_setPinVal(m2.ENB, m2.ENB_Status);
		Dio_setPinVal(m2.IN3, Status_Pin_High);
		Dio_setPinVal(m2.IN4, Status_Pin_Low);
		break;
	case Motors:
		Dio_setPinVal(m1.ENA, m1.ENA_Status);
		Dio_setPinVal(m2.ENB, m2.ENB_Status);
		Dio_setPinVal(m1.IN1, Status_Pin_High);
		Dio_setPinVal(m1.IN2, Status_Pin_Low);
		Dio_setPinVal(m2.IN3, Status_Pin_High);
		Dio_setPinVal(m2.IN4, Status_Pin_Low);
		break;
	}
}

void Motor_Reverse(u8 CopyMotorNum)
{
	switch(CopyMotorNum)
	{
	case Motor_1:
		Dio_setPinVal(m1.ENA, m1.ENA_Status);
		Dio_setPinVal(m1.IN1, Status_Pin_Low);
		Dio_setPinVal(m1.IN2, Status_Pin_High);
		break;
	case Motor_2:
		Dio_setPinVal(m2.ENB, m2.ENB_Status);
		Dio_setPinVal(m2.IN3, Status_Pin_Low);
		Dio_setPinVal(m2.IN4, Status_Pin_High);
		break;
	case Motors:
		Dio_setPinVal(m1.ENA, m1.ENA_Status);
		Dio_setPinVal(m2.ENB, m2.ENB_Status);
		Dio_setPinVal(m1.IN1, Status_Pin_Low);
		Dio_setPinVal(m1.IN2, Status_Pin_High);
		Dio_setPinVal(m2.IN3, Status_Pin_Low);
		Dio_setPinVal(m2.IN4, Status_Pin_High);
		break;
	}
}


void Motor_Off(u8 CopyMotorNum)
{
	switch(CopyMotorNum)
	{
	case Motor_1:
		Dio_setPinVal(m1.ENA, m1.ENA_Status);
		Dio_setPinVal(m1.IN1, Status_Pin_Low);
		Dio_setPinVal(m1.IN2, Status_Pin_Low);
		break;
	case Motor_2:
		Dio_setPinVal(m2.ENB, m2.ENB_Status);
		Dio_setPinVal(m2.IN3, Status_Pin_Low);
		Dio_setPinVal(m2.IN4, Status_Pin_Low);
		break;
	case Motors:
		Dio_setPinVal(m1.ENA, m1.ENA_Status);
		Dio_setPinVal(m2.ENB, m2.ENB_Status);
		Dio_setPinVal(m1.IN1, Status_Pin_Low);
		Dio_setPinVal(m1.IN2, Status_Pin_Low);
		Dio_setPinVal(m2.IN3, Status_Pin_Low);
		Dio_setPinVal(m2.IN4, Status_Pin_Low);
		break;
	}
}
