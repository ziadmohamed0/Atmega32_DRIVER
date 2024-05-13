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


u8 Row_Pin[NO_ROW]={PortB_p0,PortB_p1,PortB_p2,PortB_p3};
u8 Col_Pin[NO_COL]={PortB_p4,PortB_p5,PortB_p6,PortB_p7};
