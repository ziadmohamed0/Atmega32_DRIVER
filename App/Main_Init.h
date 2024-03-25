/*
 * Main_Init.h
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */

#ifndef APP_MAIN_INIT_H_
#define APP_MAIN_INIT_H_

#include "../Hall/Led/Led_Init.h"
#include "../Hall/BCD/bcd_Init.h"
#include "../Hall/DC_Motor/Dc_Motor_Init.h"
#include "../Hall/LCD/Lcd_Init.h"

/* -------------------- Section : Function Declarations -------------------- */
void Inzalizations(void);
void ProgLoop(void);

#endif /* APP_MAIN_INIT_H_ */
