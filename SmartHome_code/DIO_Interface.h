/*
 * DIO_Interface.h
 *
 *  Created on: 16 Mar 2023
 *      Author: Re Go
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


void DIO_VoidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinDiriction);
void DIO_VoidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8PortDirection);

void DIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue);
void DIO_VoidSetPortValue( u8 Copy_u8Port , u8 Copy_u8PortValue);

u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin);

/*Macros will be used instead of magic numbers */
#define DIO_u8PORTA         0
#define DIO_u8PORTB         1
#define DIO_u8PORTC         2
#define DIO_u8PORTD         3

#define DIO_u8PIN0          0
#define DIO_u8PIN1          1
#define DIO_u8PIN2          2
#define DIO_u8PIN3          3
#define DIO_u8PIN4          4
#define DIO_u8PIN5          5
#define DIO_u8PIN6          6
#define DIO_u8PIN7          7

#define DIO_u8PIN_INPUT     0
#define DIO_u8PIN_OUTPUT    1

#define DIO_u8PORT_INPUT    0X00
#define DIO_u8PORT_OUTPUT   0XFF

#define DIO_u8PIN_LOW       0
#define DIO_u8PIN_HIGH      1

#define DIO_u8PORT_LOW      0X00
#define DIO_u8PORT_HIGH     0XFF


#endif /* DIO_INTERFACE_H_ */
