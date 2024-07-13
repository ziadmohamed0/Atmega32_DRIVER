/*
 * I2C_init.h
 *
 *  Created on: Jun 22, 2024
 *      Author: ziad
 */

#ifndef MCAL_I2C_I2C_INIT_H_
#define MCAL_I2C_I2C_INIT_H_

/*********** INCLUDES ***********/
#include "I2C_config.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : I2C initialization function select your configurations from configurations file.
 * @param1 : void
 * @retVal : void
 */
void I2C_init(void);

/**
 * @brief  : I2C interrupt enable function by set GIE bit in SREG register
 * 			 & set TWIE bit in TWCR register.
 * @param1 : void
 * @retVal : void
 */
void I2C_interruptEnabel(void);

/**
 * @brief  : I2C interrupt disable function by clear TWIE bit in TWCR register.
 * @param1 : void
 * @retVal : void
 */
void I2C_interruptDisabel(void);

#endif /* MCAL_I2C_I2C_INIT_H_ */
