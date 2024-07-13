/*
 * SPI_prog.c
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

/*********** INCLUDES ***********/
#include "SPI_init.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : SPI initialization function select your configurations from configurations file.
 * @param1 : void
 * @retVal : void
 */
void SPI_init(void)
{
	SET_BIT(SPCR,SPE); // enable SPI

#if(_SPI_DATA_ORDER == LSB)
	SET_BIT(SPCR,DORD);
#elif (_SPI_DATA_ORDER == MSB)
	CLR_BIT(SPCR,DORD);
#endif

#if (_SPI_MODE == _SPI_MASTER)
	SET_BIT(SPCR,MSTR);
#elif (_SPI_MODE == _SPI_SLAVE)
	CLR_BIT(SPCR,MSTR);
#endif

#if (CPOL_MODE == _FALLING_RISING)
	SET_BIT(SPCR,CPOL);
#elif (CPOL_MODE == _RISING_FALLING)
	CLR_BIT(SPCR,CPOL);
#endif

#if (CPHA_MODE == _SAMPLE_SETUP)
	CLR_BIT(SPCR,CPHA);
#elif (CPHA_MODE == _SETUP_SAMPLE)
	SET_BIT(SPCR,CPHA);
#endif
}

/**
 * @brief  : SPI Master The MSTR bit in SPCR is cleared and the SPI system becomes a slave.
 * 			 As a result of the SPI becoming a slave, the MOSI and SCK pins become inputs.
 * 			 The SPIF Flag in SPSR is set, and if the SPI interrupt is enabled,
 * 			 and the I-bit in SREG is set, the interrupt routine will be executed.
 * @param1 : copyData
 * @retVal : Ret1
 */
uint_8 SPI_master(uint_8 copyData)
{
	SPDR = copyData;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}


/**
 * @brief  : SPI Slave Mode The MSTR bit in SPCR is cleared and the SPI system becomes a slave.
 * 			 As a result of the SPI becoming a slave, the MOSI and SCK pins become inputs.
 * 			 The SPIF Flag in SPSR is set, and if the SPI interrupt is enabled,
 * 			 and the I-bit in SREG is set, the interrupt routine will be executed.
 * @param1 : copyData
 * @retVal : Ret1
 */
uint_8 SPI_slave(uint_8 copyData)
{
	SPDR = copyData;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

/**
 * @brief  : SPI interrupt enable function by set GIE bit in SREG register
 * 			 & set SPIE bit in SPCR register.
 * @param1 : void
 * @retVal : void
 */
void SPI_interruptEnable(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(SPCR,SPIE);
}

/**
 * @brief  : SPI interrupt disable function by clear SPIE bit in SPCR register.
 * @param1 : void
 * @retVal : void
 */
void SPI_interruptDisable(void)
{
	CLR_BIT(SPCR,SPIE);
}
