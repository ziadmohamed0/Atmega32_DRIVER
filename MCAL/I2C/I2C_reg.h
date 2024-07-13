/*
 * I2C_reg.h
 *
 *  Created on: Jun 22, 2024
 *      Author: ziad
 */

#ifndef MCAL_I2C_I2C_REG_H_
#define MCAL_I2C_I2C_REG_H_

/*********** INCLUDES ***********/
#include "../INTERRUPT/INTERRUPT_init.h"

/*********** REGISTERS ***********/
#define TWCR	*((volatile uint_8 *) 0x56)
#define TWBR	*((volatile uint_8 *) 0x20)
#define TWSR	*((volatile uint_8 *) 0x21)
#define TWAR	*((volatile uint_8 *) 0x22)
#define TWDR	*((volatile uint_8 *) 0x23)

/*********** BITS ***********/
	/* ----- TWBR ----- */
typedef enum
{
	TWBR0,
	TWBR1,
	TWBR2,
	TWBR3,
	TWBR4,
	TWBR5,
	TWBR6,
	TWBR7
}_BITS_TWBR;

	/* ----- TWCR ----- */
typedef enum
{
	TWIE,
	RES,
	TWEN,
	TWWC,
	TWSTO,
	TWSTA,
	TWEA,
	TWINT
}_BITS_TWCR;

	/* ----- TWSR ----- */
typedef enum
{
	TWPS0,
	TWPS1,
	RES1,
	TWS3,
	TWS4,
	TWS5,
	TWS6,
	TWS7
}_BITS_TWSR;

	/* ----- TWDR ----- */
typedef enum
{
	TWD0,
	TWD1,
	TWD2,
	TWD3,
	TWD4,
	TWD5,
	TWD6,
	TWD7
}_BITS_TWDR;

	/* ----- TWAR ----- */
typedef enum
{
	TWGCE,
	TWA0,
	TWA1,
	TWA2,
	TWA3,
	TWA4,
	TWA5,
	TWA6
}_BITS_TWAR;

#endif /* MCAL_I2C_I2C_REG_H_ */
