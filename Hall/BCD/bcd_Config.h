/*
 * bcd_Config.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ziad
 */

#ifndef HALL_BCD_BCD_CONFIG_H_
#define HALL_BCD_BCD_CONFIG_H_

/* -------------------- Section : Includes -------------------- */
#include "../../Mcal/DIO/dio_Init.h"

/* -------------------- Section : Type Of 7-Segment -------------------- */
#define Common_Cathod	0
#define Common_Anode	1

#define Disable			0
#define Enable			1

/* -------------------- Section : Pins of 7-Segment -------------------- */
typedef struct {
	u8 Pin_1;
	u8 Pin_2;
	u8 Pin_3;
	u8 Pin_4;
}BCD;

/* -------------------- Section : Types & Pins of Multiplexing 7-Segment -------------------- */
#define Multiplexing_2	0
#define Multiplexing_4	1
#define Multiplexing_6	2
#define Multiplexing_8	3

#define Multiplexing	Multiplexing_6



typedef enum{
	MPX_2,MPX_4,MPX_6,MPX_8
}MPX;

#if (Multiplexing == Multiplexing_2)
typedef struct {
	u8 EN_1;
	u8 EN_2;
}MPX_2_Enables;

#elif (Multiplexing == Multiplexing_4)
typedef struct {
	u8 EN_1;
	u8 EN_2;
	u8 EN_3;
	u8 EN_4;
}MPX_4_Enables;

#elif (Multiplexing == Multiplexing_6)
typedef struct {
	u8 EN_1;
	u8 EN_2;
	u8 EN_3;
	u8 EN_4;
	u8 EN_5;
	u8 EN_6;
}MPX_6_Enables;

#elif (Multiplexing == Multiplexing_8)
typedef struct {
	u8 EN_1;
	u8 EN_2;
	u8 EN_3;
	u8 EN_4;
	u8 EN_5;
	u8 EN_6;
	u8 EN_7;
	u8 EN_8;
}MPX_8_Enables;
#endif
/* -------------------- Section : Declarations -------------------- */
BCD Seg;

#endif /* HALL_BCD_BCD_CONFIG_H_ */
