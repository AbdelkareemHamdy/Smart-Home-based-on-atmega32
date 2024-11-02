/*
 * DIO_Program.c
 *
 *  Created on: 16 Mar 2023
 *      Author: Re Go
 */
#include "STD_TYPES.h"
#include "Macros.h"
#include "DIO_config.h"
#include "DIO_register.h"
#include "DIO_Interface.h"
#include "DIO_private.h"


void DIO_VoidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin, u8 Copy_u8PinDiriction)
{
	if( Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8PinDiriction == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin);break;
			}
		}
		else if(Copy_u8PinDiriction == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin);break;
			case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin);break;
			}
		}
	}
}
void DIO_VoidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8PortDirection)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : DDRA = Copy_u8PortDirection;break;
	case DIO_u8PORTB : DDRB = Copy_u8PortDirection;break;
	case DIO_u8PORTC : DDRC = Copy_u8PortDirection;break;
	case DIO_u8PORTD : DDRD = Copy_u8PortDirection;break;
	}
}

void DIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PinValue)
{
	if( Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8PinValue == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
			}
		}
		else if(Copy_u8PinValue == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
			}
		}
	}
}


void DIO_VoidSetPortValue( u8 Copy_u8Port , u8 Copy_u8PortValue)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : PORTA = Copy_u8PortValue; break;
	case DIO_u8PORTB : PORTB = Copy_u8PortValue; break;
	case DIO_u8PORTC : PORTC = Copy_u8PortValue; break;
	case DIO_u8PORTD : PORTD = Copy_u8PortValue; break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin)
{
	u8 Local_u8PinVal=NULL;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : Local_u8PinVal = GET_BIT(PINA,Copy_u8Pin);break;
	case DIO_u8PORTB : Local_u8PinVal = GET_BIT(PINB,Copy_u8Pin);break;
	case DIO_u8PORTC : Local_u8PinVal = GET_BIT(PINC,Copy_u8Pin);break;
	case DIO_u8PORTD : Local_u8PinVal = GET_BIT(PIND,Copy_u8Pin);break;
	};
	return Local_u8PinVal;

}

