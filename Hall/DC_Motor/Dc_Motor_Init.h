/*
 * Dc_Motor_Init.h
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */

#ifndef HALL_DC_MOTOR_DC_MOTOR_INIT_H_
#define HALL_DC_MOTOR_DC_MOTOR_INIT_H_

/********** SECTION : Includes **********/
#include "Dc_Motor_Config.h"

/********** SECTION : Functions Declarations **********/

/**
  * @brief  : Initialization 2 Motor With Motor Driver
  * @param  : CopyMotor_1
  * @param  : CopyMotor_2
  */
void Motor_2_Motors_Init(motor1 CopyMotor_1,motor2 CopyMotor_2);

/**
  * @brief  : 2 Motor With Motor Driver Move Forward
  * @param  : CopyMotor_1
  * @param  : CopyMotor_2
  */
void Motor_2_Motors_Forward(motor1 CopyMotor_1,motor2 CopyMotor_2);

/**
  * @brief  : 2 Motor With Motor Driver Move Reverse
  * @param  : CopyMotor_1
  * @param  : CopyMotor_2
  */
void Motor_2_Motors_Reverse(motor1 CopyMotor_1,motor2 CopyMotor_2);

/**
  * @brief  : 2 Motor With Motor Driver Move Stop
  * @param  : CopyMotor_1
  * @param  : CopyMotor_2
  */
void Motor_2_Motors_Off(motor1 CopyMotor_1,motor2 CopyMotor_2);

#endif /* HALL_DC_MOTOR_DC_MOTOR_INIT_H_ */
