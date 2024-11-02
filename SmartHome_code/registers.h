/*
 * registers.h
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmad
 */

#ifndef INC_REGISTERS_H_
#define INC_REGISTERS_H_

/******************************************************************
 * Dio Registers
 *****************************************************************/
#define PORTA	                        *((volatile u8*)0x3B)
#define DDRA	                        *((volatile u8*)0x3A)
#define PINA	                        *((volatile u8*)0x39)
#define PORTB	                        *((volatile u8*)0x38)
#define DDRB	                        *((volatile u8*)0x37)
#define PINB	                        *((volatile u8*)0x36)
#define PORTC	                        *((volatile u8*)0x35)
#define DDRC	                        *((volatile u8*)0x34)
#define PINC	                        *((volatile u8*)0x33)
#define PORTD	                        *((volatile u8*)0x32)
#define DDRD	                        *((volatile u8*)0x31)
#define PIND	                        *((volatile u8*)0x30)




/******************************************************************
 * TIMER Registers
 *****************************************************************/

//1
#define TCCR1A                       *((volatile u8*)0x4F)
#define TCCR1B                       *((volatile u8*)0x4E)
#define ICR1H                        *((volatile u8*)0x47)
#define ICR1L                        *((volatile u8*)0x46)
#define ICR1                         *((volatile u16*)0x46)
#define OCR1AH                       *((volatile u8*)0x4B)
#define OCR1AL                       *((volatile u8*)0x4A)
#define OCR1A                        *((volatile u16*)0x4A)




#endif /* INC_REGISTERS_H_ */
