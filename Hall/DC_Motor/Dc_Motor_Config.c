/*
 * Dc_Motor_Config.c
 *
 *  Created on: Mar 22, 2024
 *      Author: ziad
 */
#include "Dc_Motor_Config.h"

motor1 m1 = {
		.IN1 = PortB_p0,
		.IN2 = PortB_p1,
		.ENA = PortB_p4,
		.ENA_Status = Status_Pin_High
};

motor2 m2 = {
		.IN3 = PortB_p2,
		.IN4 = PortB_p3,
		.ENB = PortB_p5,
		.ENB_Status = Status_Pin_High

};
