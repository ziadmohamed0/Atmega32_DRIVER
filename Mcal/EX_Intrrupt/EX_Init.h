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

/* -------------------- Section : ISR Macros Like Functions -------------------- */
#define ISR(vector)            \
    void vector (void)  __attribute__ ((signal,used,externally_visible)); \
    void vector (void)

/* -------------------- Section : External Interrupt Vectors -------------------- */
#define INT0_VECTR    __vector_1
#define INT1_VECTR    __vector_2
#define INT2_VECTR    __vector_3

/* -------------------- Section : Functions -------------------- */
void (*ISR_FUN_INT0)(void);
void (*ISR_FUN_INT1)(void);
void (*ISR_FUN_INT2)(void);
/**
  * @brief  : Initialization External Interrupt
  * @param  : CopyNumEXI
  * @param  : CopyDirIn
  */
void EXI_Init(EX_Interrupt_Num CopyNumEXI , EX_Interrupt_Dir CopyDirIn);


#endif /* MCAL_EX_INIT_H_ */
