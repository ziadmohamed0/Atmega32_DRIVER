/*
 * LCD_Prog.c
 *
 *  Created on: Jun 9, 2024
 *      Author: ziad
 */


/*********** INCLUDES ***********/
#include "LCD_Init.h"

/*********** STATIC FUNCTIONS DECLER ***********/
/**
 * @brief  : function get data for LCD 4 Bit Mode
 * @param1 : copyLCDNum
 * @retVal : void
 */
static void LCD_getData(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD);

/**
 * @brief  : LCD enable signal static function
 * @param1 : copyLCDNum
 * @retVal : void
 */
static void LCD_enableSignal(PINS_LCD copyLCDNum);

/*
* @brief  : function to set cursor & display in any row & column.
* @param1 : copyLCDNum
* @param2 : copyRow
* @param3 : copyColumn
* @retVal : void
*/
static void LCD_setCursorPosition(PINS_LCD copyLCDNum , ROW_NUM copyRow , u8 copyColumn);
/*
* @brief  : function Convert from Number to String Size 8 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u8(u8 copyNum , u8 *copySTR);
/*
* @brief  : function Convert from Number to String Size 16 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u16(u16 copyNum , u8 *copySTR);
/*
* @brief  : function Convert from Number to String Size 32 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u32(u32 copyNum , u8 *copySTR);

/*********** FUNCTIONS DECLER ***********/
/**
 * @brief  : LCD initialization function by initialization all Directions of
 *           pins LCD is DIRECTION_PIN_OUTPUT.
 *           if _LCD_MODE is _8_BIT_MODE_LCD then EN , RS , D0 ~ D7 is output pins.
 *           if _LCD_MODE is _4_BIT_MODE_LCD then EN , RS , D4 ~ D7 is output pins.
 * @param1 : copyLCDNum
 * @retVal : void
 */
void LCD_init(PINS_LCD copyLCDNum)
{
#if (_LCD_MODE == _8_BIT_MODE_LCD)
	u8 Counter = Initial_Counter;
	Dio_setPinDir(copyLCDNum.EN, Direction_Pin_Output);
	Dio_setPinDir(copyLCDNum.RS, Direction_Pin_Output);
	for (Counter = Initial_Counter;  Counter < 8; Counter++)
	{
		Dio_setPinDir(copyLCDNum.D[Counter], Direction_Pin_Output);
	}
	_delay_ms(20);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	_delay_ms(5);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	_delay_us(150);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	LCD_writeCMD(copyLCDNum, _LCD_CLEAR_DIS);
	LCD_writeCMD(copyLCDNum, _LCD_RETURN_HOME);
	LCD_writeCMD(copyLCDNum, _LCD_ENTERY_INC);
	LCD_writeCMD(copyLCDNum, _LCD_DISPLAY_ON);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	LCD_writeCMD(copyLCDNum, 0x80);
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
	u8 Counter = Initial_Counter;
	Dio_setPinDir(copyLCDNum.EN, Direction_Pin_Output);
	Dio_setPinDir(copyLCDNum.RS, Direction_Pin_Output);
	for (Counter = Initial_Counter;  Counter < 4; Counter++)
	{
		Dio_setPinDir(copyLCDNum.D[Counter], Direction_Pin_Output);
	}
	_delay_ms(20);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	_delay_ms(5);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	_delay_us(150);
	LCD_writeCMD(copyLCDNum, _LCD_8_BIT_MODE);
	LCD_writeCMD(copyLCDNum, _LCD_CLEAR_DIS);
	LCD_writeCMD(copyLCDNum, _LCD_RETURN_HOME);
	LCD_writeCMD(copyLCDNum, _LCD_ENTERY_INC);
	LCD_writeCMD(copyLCDNum, _LCD_DISPLAY_ON);
	LCD_writeCMD(copyLCDNum, _LCD_4_BIT_MODE);
	LCD_writeCMD(copyLCDNum, 0x80);
	#endif
}

/**
 * @brief  : LCD write command function
 *           if Command is _LCD_CLEAR_DIS Clear all the display data.
 *           if Command is _LCD_RETURN_HOME Return display to its original position.
 *           if Command is _LCD_ENTERY_INC Sets the move direction of cursor and display Right.
 *           if Command is _LCD_ENTERY_DEC Sets the move direction of cursor and display Left.
 *           if Command is _LCD_DISPLAY_ON Sets the LCD is ON.
 *           if Command is _LCD_DISPLAY_OFF Sets the LCD is OFF.
 *           if Command is _LCD_CURSOR_ON Sets the LCD is ON.
 *           if Command is _LCD_CURSOR_BLINK Sets the LCD is ON.
 *           if Command is _LCD_SHIFT_RIGHT Shifts the entire display to the Right.
 *           if Command is _LCD_SHIFT_LEFT Shifts the entire display to the Left.
 *           if Command is _LCD_8_BIT_MODE length (DB7 ~ DB0).
 *           if Command is _LCD_4_BIT_MODE length (DB7 ~ DB4).
 *           if Command is _LCD_CG_RAM_SET Sets the CG RAM address to the address counter.
 *           if Command is _LCD_DD_RAM_SET Sets the DD RAM address to the address counter.
 * @param1 : copyLCDNum
 * @param2 : copyCMD
 * @retVal : void
 */
void LCD_writeCMD(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD)
{
#if (_LCD_MODE == _8_BIT_MODE_LCD)
	u8 Counter = Initial_Counter;
	Dio_setPinVal(copyLCDNum.RS , Status_Pin_Low);
	for(Counter = Initial_Counter; Counter < 8 ; Counter++)
	{
		Dio_setPinVal(copyLCDNum.D[Counter], ((copyCMD >> Counter) & (u8)0x01));
	}
	LCD_enableSignal(copyLCDNum);
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
	Dio_setPinVal(copyLCDNum.RS , Status_Pin_Low);
	LCD_getData(copyLCDNum,copyCMD >> 4);
	LCD_enableSignal(copyLCDNum);
	LCD_getData(copyLCDNum,copyCMD);
	LCD_enableSignal(copyLCDNum);
#endif
}

/**
 * @brief  : LCD write Character function
 * @param1 : copyLCDNum
 * @param2 : copyChar
 * @retVal : void
 */
void LCD_writeChar(PINS_LCD copyLCDNum, u8 copyChar)
{
#if (_LCD_MODE == _8_BIT_MODE_LCD)
	Dio_setPinVal(copyLCDNum.RS , Status_Pin_High);
	Dio_setPortVal(copyLCDNum.PORT_DATA_PIN_NUM, copyChar);
	_delay_ms(1);
	LCD_enableSignal(copyLCDNum);
#elif (_LCD_MODE == _4_BIT_MODE_LCD)
	Dio_setPinVal(copyLCDNum.RS , Status_Pin_High);
	LCD_getData(copyLCDNum,copyChar >> 4);
	LCD_enableSignal(copyLCDNum);
	LCD_getData(copyLCDNum,copyChar);
	LCD_enableSignal(copyLCDNum);
#endif
}

/**
 * @brief  : LCD write String function
 * @param1 : copyLCDNum
 * @param2 : copySTR
 * @retVal : void
 */
void LCD_writeSTR(PINS_LCD copyLCDNum, u8 *copySTR)
{
	while(*copySTR)
	{
		LCD_writeChar(copyLCDNum, *copySTR++);
	}
}

/**
 * @brief  : LCD write Number function size 8 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u8(PINS_LCD copyLCDNum, u8 *copyNum)
{
	u8 Ret[5];
	LCD_convertNum_u8(copyNum, &Ret);
	LCD_writeSTR(copyLCDNum, Ret);
}

/**
 * @brief  : LCD write Number function size 16 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u16(PINS_LCD copyLCDNum, u16 *copyNum)
{
	u16 Ret[5];
	LCD_convertNum_u16(copyNum, &Ret);
	LCD_writeSTR(copyLCDNum, Ret);
}

/**
 * @brief  : LCD write Number function size 32 Bits.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u32(PINS_LCD copyLCDNum, u32 *copyNum)
{
	u32 Ret[5];
	LCD_convertNum_u32(copyNum, &Ret);
	LCD_writeSTR(copyLCDNum, Ret);
}

/**
 * @brief  : LCD write Character function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyRow
 * @param3 : copyColumn
 * @param4 : copyChar
 * @retVal : void
 */
void LCD_writeCharPosition(PINS_LCD copyLCDNum, ROW_NUM copyRow, u8 copyColumn, u8 copyChar)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeChar(copyLCDNum, copyChar);
}

/**
 * @brief  : LCD write String function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyRow
 * @param3 : copyColumn
 * @param4 : copySTR
 * @retVal : void
 */
void LCD_writeSTRPosition(PINS_LCD copyLCDNum, ROW_NUM copyRow, u8 copyColumn,u8 *copySTR)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeSTR(copyLCDNum, copySTR);
}

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u8Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, u8 copyColumn,u8 *copyNum)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeNum_u8(copyLCDNum, copyNum);
}

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u16Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, u8 copyColumn,u16 *copyNum)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeNum_u16(copyLCDNum, copyNum);
}

/**
 * @brief  : LCD write Number function in Any Position in LCD.
 * @param1 : copyLCDNum
 * @param2 : copyNum
 * @retVal : void
 */
void LCD_writeNum_u32Position(PINS_LCD copyLCDNum, ROW_NUM copyRow, u8 copyColumn,u32 *copyNum)
{
	LCD_setCursorPosition(copyLCDNum, copyRow, copyColumn);
	LCD_writeNum_u32(copyLCDNum, copyNum);
}

/*
* @brief  : function to set cursor & display in any row & column.
* @param1 : copyLCDNum
* @param2 : copyRow
* @param3 : copyColumn
* @retVal : void
*/
void LCD_goTo(PINS_LCD copyLCDNum , ROW_NUM copyRow , u8 copyColumn)
{
	copyColumn--;
#if ((_Rows_LCD_TYPE == LM044_LCD) || (_Rows_LCD_TYPE == LM04L_LCD))
	switch (copyRow)
	{
		case ROW1 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_1 + copyColumn)); break;
		case ROW2 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_2 + copyColumn)); break;
		case ROW3 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_3 + copyColumn)); break;
		case ROW4 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_4 + copyColumn)); break;
	}
#elif 	(_Rows_LCD_TYPE == LM32L_LCD)
	switch (copyRow)
	{
		case ROW1:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_1 + copyColumn)); break;
		case ROW2:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_2 + copyColumn)); break;
	}
#endif
}
/*********** STATIC FUNCTIONS DEFIN ***********/
#if (_LCD_MODE == _4_BIT_MODE_LCD)
/**
 * @brief  : function get data for LCD 4 Bit Mode
 * @param1 : copyLCDNum
 * @param2 : copyCMD
 * @retVal : void
 */
static void LCD_getData(PINS_LCD copyLCDNum, _LCD_COMMANDS copyCMD)
{
	Dio_setPinVal(copyLCDNum.D[0] , (copyCMD >> 0) & (u8)0x01);
	Dio_setPinVal(copyLCDNum.D[1] , (copyCMD >> 1) & (u8)0x01);
	Dio_setPinVal(copyLCDNum.D[2] , (copyCMD >> 2) & (u8)0x01);
	Dio_setPinVal(copyLCDNum.D[3] , (copyCMD >> 3) & (u8)0x01);
}
#endif

/**
 * @brief  : LCD enable signal static function
 * @param1 : copyLCDNum
 * @retVal : void
 */
static void LCD_enableSignal(PINS_LCD copyLCDNum)
{
#if (_LCD_MODE == _4_BIT_MODE_LCD)
	Dio_setPinVal(copyLCDNum.EN,Status_Pin_High);
	_delay_us(5);
	Dio_setPinVal(copyLCDNum.EN, Status_Pin_Low);
#elif (_LCD_MODE == _8_BIT_MODE_LCD)
	Dio_setPinVal(copyLCDNum.EN, Status_Pin_High);
	_delay_us(5);
	Dio_setPinVal(copyLCDNum.EN, Status_Pin_Low);
#endif
}

/*
* @brief  : function to set cursor & display in any row & column.
* @param1 : copyLCDNum
* @param2 : copyRow
* @param3 : copyColumn
* @retVal : void
*/
static void LCD_setCursorPosition(PINS_LCD copyLCDNum , ROW_NUM copyRow , u8 copyColumn)
{
	copyColumn--;
#if ((_Rows_LCD_TYPE == LM044_LCD) || (_Rows_LCD_TYPE == LM04L_LCD))
	switch (copyRow)
	{
		case ROW1 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_1 + copyColumn)); break;
		case ROW2 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_2 + copyColumn)); break;
		case ROW3 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_3 + copyColumn)); break;
		case ROW4 : LCD_writeCMD(copyLCDNum, (ADDREES_ROW_4 + copyColumn)); break;
	}
#elif 	(_Rows_LCD_TYPE == LM32L_LCD)
	switch (copyRow)
	{
		case ROW1:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_1 + copyColumn)); break;
		case ROW2:LCD_writeCMD(copyLCDNum, (ADDREES_ROW_2 + copyColumn)); break;
	}
#endif
}

/*
* @brief  : function Convert from Number to String Size 8 Bits
* @param1 : copyLCDNum
* @param2 : copySTR
* @retVal : void
*/
static void LCD_convertNum_u8(u8 copyNum , u8 *copySTR)
{
	memset(copySTR , '\0' , 4);
	sprintf(copySTR , "%i", copyNum);
}

/*
* @brief  : function Convert from Number to String Size 16 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u16(u16 copyNum , u8 *copySTR)
{
	memset(copySTR , '\0' , 6);
	sprintf(copySTR , "%i", copyNum);
}

/*
* @brief  : function Convert from Number to String Size 32 Bits
* @param1 : copyLCDNum
* @param2 : copyNum
* @retVal : void
*/
static void LCD_convertNum_u32(u32 copyNum , u8 *copySTR)
{
	memset(copySTR , '\0' , 11);
	sprintf(copySTR , "%i", copyNum);
}
