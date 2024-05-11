/*
 * EX_Prog.c
 *
 *  Created on: May 3, 2024
 *      Author: ziad
 */

/* -------------------- Section : Includes -------------------- */
#include "EX_Init.h"
#include "../DIO/dio_Init.h"
/* -------------------- Section : Static Functions -------------------- */

/**
  * @brief  : Static Function Control Direction of External Interrupt {0}
  * @param  : CopyDirIn
  */
static void EX_ControlIN0(EX_Interrupt_Dir CopyDirIn);

/**
  * @brief  : Static Function Control Direction of External Interrupt {1}
  * @param  : CopyDirIn
  */
static void EX_ControlIN1(EX_Interrupt_Dir CopyDirIn);

/**
  * @brief  : Static Function Control Direction of External Interrupt {2}
  * @param  : CopyDirIn
  */
static void EX_ControlIN2(EX_Interrupt_Dir CopyDirIn);

/* -------------------- Section : Functions -------------------- */

/**
  * @brief  : Initialization External Interrupt
  * @param  : CopyNumEXI
  * @param  : CopyDirIn
  */
void EXI_Init(EX_Interrupt_Num CopyNumEXI , EX_Interrupt_Dir CopyDirIn)
{
	switch (CopyNumEXI) {
		case IN0:
			SET_BIT(SREG,SREG_GIE);		// Enable General Interrupt Register
			SET_BIT(GICR , GICR_INT0);	// Enable Local Interrupt Register of INT0
			EX_ControlIN0(CopyDirIn);
			Dio_setPinDir(PortD_p2,Direction_Pin_Input);
			break;
		case IN1:
			SET_BIT(SREG,SREG_GIE);		// Enable General Interrupt Register
			SET_BIT(GICR , GICR_INT1);	// Enable Local Interrupt Register of INT1
			EX_ControlIN1(CopyDirIn);
			Dio_setPinDir(PortD_p3,Direction_Pin_Input);
			break;
		case IN2:
			SET_BIT(SREG,SREG_GIE);		// Enable General Interrupt Register
			SET_BIT(GICR , GICR_INT2);	// Enable Local Interrupt Register of INT2
			EX_ControlIN2(CopyDirIn);
			Dio_setPinDir(PortB_p3,Direction_Pin_Input);
			break;
	}
}

/* -------------------- Section : Static Functions -------------------- */

/**
  * @brief  : Static Function Control Direction of External Interrupt {0}
  * @param  : CopyDirIn
  */
static void EX_ControlIN0(EX_Interrupt_Dir CopyDirIn)
{
	switch (CopyDirIn) {
		case LOW_LEVEL:
			CLR_BIT(MCUCR , MCUCR_ISC11);
			CLR_BIT(MCUCR , MCUCR_ISC10);
			break;
		case ANY_LOGIC:
			CLR_BIT(MCUCR , MCUCR_ISC11);
			SET_BIT(MCUCR , MCUCR_ISC10);
			break;
		case FALLING_EDGE:
			SET_BIT(MCUCR , MCUCR_ISC11);
			CLR_BIT(MCUCR , MCUCR_ISC10);
			break;
		case RISING_AGE:
			SET_BIT(MCUCR , MCUCR_ISC11);
			SET_BIT(MCUCR , MCUCR_ISC10);
			break;
	}
}

/**
  * @brief  : Static Function Control Direction of External Interrupt {1}
  * @param  : CopyDirIn
  */
static void EX_ControlIN1(EX_Interrupt_Dir CopyDirIn)
{
	switch (CopyDirIn)
	{
			case LOW_LEVEL:
				CLR_BIT(MCUCR , MCUCR_ISC01);
				CLR_BIT(MCUCR , MCUCR_ISC00);
				break;
			case ANY_LOGIC:
				CLR_BIT(MCUCR , MCUCR_ISC01);
				SET_BIT(MCUCR , MCUCR_ISC00);
				break;
			case FALLING_EDGE:
				SET_BIT(MCUCR , MCUCR_ISC01);
				CLR_BIT(MCUCR , MCUCR_ISC00);
				break;
			case RISING_AGE:
				SET_BIT(MCUCR , MCUCR_ISC01);
				SET_BIT(MCUCR , MCUCR_ISC00);
				break;
		}
}

/**
  * @brief  : Static Function Control Direction of External Interrupt {2}
  * @param  : CopyDirIn
  */
static void EX_ControlIN2(EX_Interrupt_Dir CopyDirIn)
{
	switch (CopyDirIn)
	{
			case FALLING_EDGE:
				CLR_BIT(MCUCSR , MCUCSR_ISC2);
				break;
			case RISING_AGE:
				SET_BIT(MCUCSR , MCUCSR_ISC2);
				break;
			default:
				CLR_BIT(MCUCSR , MCUCSR_ISC2);
				break;
		}
}
