/*
 * UART_Prog.c
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "UART_Init.h"


/*********** FUNCTIONS DEFIN ***********/
void UART_init(BAUD_RATE copyBaudRate)
{
//	UBRRH = (copyBaudRate >> 8);
	UBRRL = copyBaudRate;

	/* ----- SYNCH MODE ----- */
#if	(SYNCH_MODE == ASYNCHRONOUS_MODE)
	CLR_BIT(UCSRC,UMSEL);
#elif (SYNCH_MODE == SYNCHRONOUS_MODE)
	SET_BIT(UCSRC,UMSEL);
#endif

	/* ----- PARITY MODE ----- */

#if (PARITY_MODE == PARITY_EVEN)
	SET_BIT(UCSRC,UPM1);
	CLR_BIT(UCSRC,UPM0);
#elif (PARITY_MODE == PARITY_ODD)
	SET_BIT(UCSRC,UPM1);
	SET_BIT(UCSRC,UPM0);
#endif

	/* ----- STOP NUM BITS MODE ----- */
#if	(STOP_NUM_BITS == STOP_1_BIT)
	CLR_BIT(UCSRC,USBS);
#elif (STOP_NUM_BITS == STOP_2_BIT)
	SET_BIT(UCSRC,USBS);
#endif

	/* ----- DATA SIZE MODE ----- */
#if (DATA_SIZE == DATA_5_BITS)
	CLR_BIT(UCSRC,UCSZ2);
	CLR_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRC,UCSZ0);
#elif (DATA_SIZE == DATA_6_BITS)
	CLR_BIT(UCSRC,UCSZ2);
	CLR_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
#elif (DATA_SIZE == DATA_7_BITS)
	CLR_BIT(UCSRC,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRC,UCSZ0);
#elif (DATA_SIZE == DATA_8_BITS)
	 SET_BIT(UCSRC,UCSZ0);
	 SET_BIT(UCSRC,UCSZ1);
	 CLR_BIT(UCSRC,UCSZ2);
#elif (DATA_SIZE == DATA_9_BITS)
	SET_BIT(UCSRC,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
#endif
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);
}

void UART_sendData(u16 copyData)
{
	while(GET_BIT(UCSRA,UDRE) == 0);
	UDR = copyData;
}

u8 UART_reciveData(u8 *copyVar)
{
	if(GET_BIT(UCSRA,RXC))
	{
		*copyVar = UDR;
		return 1;
	}
	else
	{
		return 0;
	}
}

u8 UART_reciveDataBlock(void)
{
	while(GET_BIT(UCSRA,RXC) == 0);
	return UDR;
}
