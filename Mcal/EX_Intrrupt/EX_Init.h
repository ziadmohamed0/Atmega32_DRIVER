/*
 * EX_Init.h
 *
 *  Created on: May 3, 2024
 *      Author: ziad
 */

#ifndef MCAL_EX_INIT_H_
#define MCAL_EX_INIT_H_

/* -------------------- Section : Includes -------------------- */
#include "EX_Config.h"

/* -------------------- Section : Macros Like Functions -------------------- */
#define ISR(vector)            \
    void vector (void)  __attribute__ ((signal,used, externally_visible)); \
    void vector (void)

/* -------------------- Section : Macros Vectors -------------------- */
#define INT0_VECTR    __vector_1
#define INT1_VECTR    __vector_2
#define INT2_VECTR    __vector_3

/* -------------------- Section : Functions -------------------- */
void EXI_Init(EX_Interrupt_Num CopyNumEXI , EX_Interrupt_Dir CopyDirIn);


#endif /* MCAL_EX_INIT_H_ */
