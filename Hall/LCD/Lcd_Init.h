/*
 * Lcd_Init.h
 *
 *  Created on: Mar 24, 2024
 *      Author: ziad
 */

#ifndef HALL_LCD_LCD_INIT_H_
#define HALL_LCD_LCD_INIT_H_

/********** SECTION : Includes **********/
#include "Lcd_Config.h"

/********** SECTION : Commands Of LCD **********/
#define _LCD_Clear_Dis					(u8)0x01
#define _LCD_Return_Home				(u8)0x02
#define _LCD_Entery_INC					(u8)0x06
#define _LCD_Entery_DEC					(u8)0x04
#define _LCD_Dis_OFF					(u8)0x08
#define _LCD_Dis_ON						(u8)0x0C
#define _LCD_Cursor_ON					(u8)0x0E
#define _LCD_Cursor_Blink_On			(u8)0x0F
#define _LCD_Shift_Left					(u8)0x18
#define _LCD_Shift_Right				(u8)0x1C
#define _LCD_4_Bit_Mode					(u8)0x28
#define _LCD_8_Bit_Mode					(u8)0x38
#define _LCD_Set_CGRAM					(u8)0x40
#define _LCD_Set_DDRAM					(u8)0x80

/********** SECTION : Number Of Rows **********/
#define Row_1	(u8)1
#define Row_2	(u8)2
#define Row_3	(u8)3
#define Row_4	(u8)4

/********** SECTION : Functions Declarations  8 Bit Mode **********/
#if _LCD_Mood ==  _LCD_8_Bit_Mood

/**
  * @brief  : Initialization Lcd 8 Bit Mode
  * @param  : CopyLCD
  */
void LCD_8_INIT(LCD_8_MODE CopyLCD);

/**
  * @brief  : Write Command in Lcd 8 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyCMD
  */
void LCD_8_CMD_Write(LCD_8_MODE CopyLCD , u8 CopyCMD);

/**
  * @brief  : Write Character in first address in Lcd 8 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyChar
  */
void LCD_8_Char_Write(LCD_8_MODE CopyLCD , u8 CopyChar);

/**
  * @brief  : Write Character in CopyRow in CopyCoulmn on Lcd 8 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyRow
  * @param  : CopyCoulmn
  * @param  : CopyChar
  */
void LCD_8_Char_Postion(LCD_8_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 CopyChar);

/**
  * @brief  : Write String in first address in Lcd 8 Bit Mode
  * @param  : CopyLCD
  * @param  : CopySTR
  */
void LCD_8_String_Write(LCD_8_MODE CopyLCD , u8 *CopySTR);

/**
  * @brief  : Write String in CopyRow in CopyCoulmn on Lcd 8 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyRow
  * @param  : CopyCoulmn
  * @param  : CopySTR
  */
void LCD_8_STR_Write_Postion(LCD_8_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 *CopySTR);

/********** SECTION : Functions Declarations  4 Bit Mode **********/
#elif _LCD_Mood == _LCD_4_Bit_Mood

/**
  * @brief  : Initialization Lcd 4 Bit Mode
  * @param  : CopyLCD
  */
void LCD_4_INIT(LCD_4_MODE CopyLCD);

/**
  * @brief  : Write Command in Lcd 4 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyCMD
  */
void LCD_4_CMD_Write(LCD_4_MODE CopyLCD , u8 CopyCMD);

/**
  * @brief  : Write Character in first address in Lcd 4 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyChar
  */
void LCD_4_Char_Write(LCD_4_MODE CopyLCD , u8 CopyChar);

/**
  * @brief  : Write Character in CopyRow in CopyCoulmn on Lcd 4 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyRow
  * @param  : CopyCoulmn
  * @param  : CopyChar
  */
void LCD_4_Char_Postion(LCD_4_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 CopyChar);

/**
  * @brief  : Write String in first address in Lcd 4 Bit Mode
  * @param  : CopyLCD
  * @param  : CopySTR
  */
void LCD_4_Str_Write(LCD_4_MODE CopyLCD , u8 *CopySTR);

/**
  * @brief  : Write String in CopyRow in CopyCoulmn on Lcd 4 Bit Mode
  * @param  : CopyLCD
  * @param  : CopyRow
  * @param  : CopyCoulmn
  * @param  : CopySTR
  */
void LCD_4_STR_Postion(LCD_4_MODE CopyLCD , u8 CopyRow , u8 CopyCoulmn , u8 *CopySTR);

#endif
/********** SECTION : Functions Declarations Convert **********/

/**
  * @brief  : Conversion Number To String And Store String In CopySTR (Array)
  * @param  : CopyValueu8
  * @param  : CopySTR
  */
void Convert_u8_to_String(u8 CopyValueu8 , u8 *CopySTR);

/**
  * @brief  : Conversion Number To String And Store String In CopySTR (Array)
  * @param  : CopyValueu16
  * @param  : CopySTR
  */
void Convert_u16_to_String(u16 CopyValueu16 , u8 *CopySTR);

/**
  * @brief  : Conversion Number To String And Store String In CopySTR (Array)
  * @param  : CopyValueu32
  * @param  : CopySTR
  */
void Convert_u32_to_String(u32 CopyValueu32 , u8 *CopySTR);

#endif /* HALL_LCD_LCD_INIT_H_ */
