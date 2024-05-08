/*
 * EX_Reg.h
 *
 *  Created on: May 3, 2024
 *      Author: ziad
 */

#ifndef MCAL_EX_INTRRUPT_EX_REG_H_
#define MCAL_EX_INTRRUPT_EX_REG_H_

/* -------------------- Section : Macros Registers -------------------- */
#define MCUCR    *((volatile u8 *) 0x55)
#define MCUCSR   *((volatile u8 *) 0x54)
#define GICR     *((volatile u8 *) 0x5B)
#define GIFR     *((volatile u8 *) 0x5A)
#define SREG     *((volatile u8 *) 0x5F)

/* -------------------- Section : Macros Pins -------------------- */
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3


#define MCUCSR_ISC2   6

#define GICR_INT0   6
#define GICR_INT1   7
#define GICR_INT2   5


#define SREG_GIE   7


#endif /* MCAL_EX_INTRRUPT_EX_REG_H_ */
