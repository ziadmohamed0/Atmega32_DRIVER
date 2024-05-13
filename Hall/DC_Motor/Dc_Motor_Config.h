/*
 * Dc_Motor_Config.h
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */

#ifndef HALL_DC_MOTOR_DC_MOTOR_CONFIG_H_
#define HALL_DC_MOTOR_DC_MOTOR_CONFIG_H_

/********** SECTION : Includes **********/
#include "../../Mcal/DIO/dio_Init.h"

/********** SECTION : Motors Pins **********/
typedef struct{
	u8 IN1;
	u8 IN2;
}motor1;

typedef struct{
	u8 IN3;
	u8 IN4;
}motor2;

/********** SECTION : Motors **********/
motor1 m1;
motor2 m2;


#endif /* HALL_DC_MOTOR_DC_MOTOR_CONFIG_H_ */
