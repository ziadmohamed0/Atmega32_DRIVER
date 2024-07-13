/*
 * I2C_config.h
 *
 *  Created on: Jun 22, 2024
 *      Author: ziad
 */

#ifndef MCAL_I2C_I2C_CONFIG_H_
#define MCAL_I2C_I2C_CONFIG_H_

/*********** INCLUDES ***********/
#include "I2C_reg.h"

/*********** PRESCALER ***********/
typedef enum
{
	_I2C_1_PRESCALER,
	_I2C_4_PRESCALER,
	_I2C_16_PRESCALER,
	_I2C_64_PRESCALER
}_I2C_PRESCALER;

#endif /* MCAL_I2C_I2C_CONFIG_H_ */
