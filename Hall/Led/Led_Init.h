/*
 * Led_Init.h
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

#ifndef HALL_LED_LED_INIT_H_
#define HALL_LED_LED_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "../../Mcal/DIO/dio_Init.h"

void Led_On_PortLeds_Button(u8 CopyPortOutNum , u8 CopyButtonPin_On , u8 CopyButtonPin_Off );
void Led_On_OneLed_Button(u8 CopyPinOutNum ,u8 CopyButtonPin_On , u8 CopyButtonPin_Off);


#endif /* HALL_LED_LED_INIT_H_ */
