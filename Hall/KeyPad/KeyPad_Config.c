/*
 * KeyPad_Config.c
 *
 *  Created on: Apr 7, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "KeyPad_Config.h"

/********** SECTION : KeyPad Configurations **********/

u8 Pattern[NO_ROW][NO_COL]={
							    {'7','8','9','/'},
		                        {'4','5','6','*'},
					            {'1','2','3','-'},
					            {'AC','0','=','+'}
												   };


u8 Row_Pin[NO_ROW]={PortC_p0,PortC_p1,PortC_p2,PortC_p3};
u8 Col_Pin[NO_COL]={PortC_p4,PortC_p5,PortC_p6,PortC_p7};
