/*
 * bcd_Init.h
 *
 *  Created on: Mar 17, 2024
 *      Author: ziad
 */

#ifndef HALL_BCD_BCD_INIT_H_
#define HALL_BCD_BCD_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "bcd_Config.h"

/* -------------------- Section : Function Declarations -------------------- */
/**
  * @brief  : Initialization 7-segment With BCD
  * @param  : Copy7seg
  */
void Bcd_7segInit(BCD Copy7seg);

/**
  * @brief  : Write Number in 7-segment With BCD
  * @param  : Copy7segNum
  * @param  : CopyNumber
  */
void Bcd_7segWriteNum(BCD Copy7segNum , u8 CopyNumber);

#if (Multiplexing == Multiplexing_2)
/**
  * @brief  :  Set or Clear Enable Pins & Select Type Of 2 Multiplexing 7-segment
  * @param  : Copy7segNum
  * @param  : CopyNumber
  */
void Bcd_MPX_2Enable(MPX_2_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);

#elif (Multiplexing == Multiplexing_4)
/**
  * @brief  :  Set or Clear Enable Pins & Select Type Of 4 Multiplexing 7-segment
  * @param  : Copy7segNum
  * @param  : CopyNumber
  */
void Bcd_MPX_4Enable(MPX_4_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);

#elif (Multiplexing == Multiplexing_6)
/**
  * @brief  :  Set or Clear Enable Pins & Select Type Of 6 Multiplexing 7-segment
  * @param  : Copy7segNum
  * @param  : CopyNumber
  */
void Bcd_MPX_6Enable(MPX_6_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);

#elif (Multiplexing == Multiplexing_8)
/**
  * @brief  :  Set or Clear Enable Pins & Select Type Of 8 Multiplexing 7-segment
  * @param  : Copy7segNum
  * @param  : CopyNumber
  */
void Bcd_MPX_8Enable(MPX_8_Enables CopyPinsEnable , u8 CopyCommonType, u8 CopyStatus);
#endif

#endif /* HALL_BCD_BCD_INIT_H_ */
