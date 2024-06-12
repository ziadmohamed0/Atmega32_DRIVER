/*
 * UART_Reg.h
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

/*********** INCLUDES ***********/
#include "../EX_Intrrupt/EX_Init.h"

/*********** VECTORS ***********/
#define USART_RXC	__vector_13
#define USART_UDRE	__vector_14
#define USART_TXC	__vector_15

/*********** REGISTERS ***********/
#define UBRRH *((volatile u8*)0x40)
#define UCSRC *((volatile u8*)0x40)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UBRRL *((volatile u8*)0x29)
#define UDR   *((volatile u8*)0x2C)

/*********** BITS REGISTER ***********/
typedef enum
{
	MPCM,
	U2X,
	PE,
	DOR,
	FE,
	UDRE,
	TXC,
	RXC
}BITS_UCSRA;


typedef enum
{
	TXB8,
	RXB8,
	UCSZ2,
	TXEN,
	RXEN,
	UDRIE,
	TXCIE,
	RXCIE
}BITS_UCSRB;

typedef enum
{
	UCPOL,
	UCSZ0,
	UCSZ1,
	USBS,
	UPM0,
	UPM1,
	UMSEL,
	URSEL
}BITS_UCSRC;

#endif /* MCAL_UART_UART_REG_H_ */
