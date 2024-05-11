/*
 * bcd_Config.c
 *
 *  Created on: Mar 23, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "bcd_Config.h"

/********** SECTION : 7-Segment **********/
BCD Seg = {
	.Pin_1 = PortA_p0,
	.Pin_2 = PortA_p1,
	.Pin_3 = PortA_p2,
	.Pin_4 = PortA_p3
};


