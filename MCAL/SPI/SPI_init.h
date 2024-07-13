/*
 * SPI_init.h
 *
 *  Created on: Jun 17, 2024
 *      Author: ziad
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_

/*********** INCLUDES ***********/
#include "SPI_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : SPI initialization function select your configurations from configurations file.
 * @param1 : void
 * @retVal : void
 */
void SPI_init(void);

/**
 * @brief  : SPI Master Mode The All other pins are inputs. When SS is driven high,
 * 			 all pins are inputs except MISO which can be user configured as an output,
 * 			 and the SPI is passive, which means that it will not receive incoming data.
 * 			 Note that the SPI logic will be reset once the SS pin is driven high.
 * @param1 : copyData
 * @retVal : Ret1
 */
uint_8 SPI_master(uint_8 copyData);


/**
 * @brief  : SPI Slave Mode The MSTR bit in SPCR is cleared and the SPI system becomes a slave.
 * 			 As a result of the SPI becoming a slave, the MOSI and SCK pins become inputs.
 * 			 The SPIF Flag in SPSR is set, and if the SPI interrupt is enabled,
 * 			 and the I-bit in SREG is set, the interrupt routine will be executed.
 * @param1 : copyData
 * @retVal : Ret1
 */
uint_8 SPI_slave(uint_8 copyData);


/**
 * @brief  : SPI interrupt enable function by set GIE bit in SREG register
 * 			 & set SPIE bit in SPCR register.
 * @param1 : void
 * @retVal : void
 */
void SPI_interruptEnable(void);

/**
 * @brief  : SPI interrupt disable function by clear SPIE bit in SPCR register.
 * @param1 : void
 * @retVal : void
 */
void SPI_interruptDisable(void);

#endif /* MCAL_SPI_SPI_INIT_H_ */
