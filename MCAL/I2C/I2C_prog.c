/*
 * I2C_prog.c
 *
 *  Created on: Jun 22, 2024
 *      Author: ziad
 */
/*********** INCLUDES ***********/
#include "I2C_init.h"

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : I2C initialization function select your configurations from configurations file.
 * @param1 : void
 * @retVal : void
 */
void I2C_init(void)
{

}


/**
 * @brief  : I2C interrupt enable function by set GIE bit in SREG register
 * 			 & set TWIE bit in TWCR register.
 * @param1 : void
 * @retVal : void
 */
void I2C_interruptEnabel(void)
{
	SET_BIT(SREG,GIE);
	SET_BIT(TWCR,TWIE);
}


/**
 * @brief  : I2C interrupt disable function by clear TWIE bit in TWCR register.
 * @param1 : void
 * @retVal : void
 */
void I2C_interruptDisabel(void)
{
	CLR_BIT(TWCR,TWIE);
}
