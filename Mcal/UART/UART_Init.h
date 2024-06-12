/*
 * UART_Init.h
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */

#ifndef MCAL_UART_UART_INIT_H_
#define MCAL_UART_UART_INIT_H_

/*********** INCLUDES ***********/
#include "UART_Config.h"

/*********** FUNCTIONS DECLER ***********/
void UART_init(BAUD_RATE copyBaudRate);
void UART_sendData(u16 copyData);
u8 UART_reciveData(u8 *copyVar);
u8 UART_reciveDataBlock(void);

#endif /* MCAL_UART_UART_INIT_H_ */
