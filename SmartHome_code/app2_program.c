/*
 * program.c
 *
 *  Created on: 14 Sep 2023
 *      Author: Re Go
 */
#include "STD_TYPES.h"
#include "Macros.h"
//#include <avr/delay.h>
#include "USART_interface.h"
#include "app2_config.h"
#include "DIO_Interface.h"
#include "Lcd.h"
#include "smart_door_interface.h"
#include "smart_door_config.h"
#include "Timer1_interface.h"
#include "app2_interface.h"
#include "app2_config.h"
#include "APPuser_interface.h"
void option_voidChooseOptione(void)
{
	u8 Unused,Local_u8option = 0;
	u8 Local_u8ResevedVal = 0 ;
	do
	{
		USART_u8SendString("\noption is: ");
		//Lcd_DisplayString("pleas choice option");
		USART_u8SendString("\n1-lighting system    2-air condition system ");
		USART_u8SendString("\n3-door system     4-change user name and password \n5-exit ");
		USART_u8SendString("\nPlease Choose your option: ");
		Local_u8option = USART_u8Receive();
		switch(Local_u8option)
		{
			case option1 :
				USART_u8SendString("\nlighting system on");
				USART_u8SendString("\noption is: ");
				USART_u8SendString("\n1-master    2-living");
				USART_u8SendString("\n3-bathroom   4-kitchen\n5-Main Options");
				USART_u8SendString("\nPlease Choose your option: ");
				Local_u8ResevedVal = USART_u8Receive();
				switch(Local_u8ResevedVal)
				{
					case master :
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,master_pinLight,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,master_pinLight,DIO_u8PIN_LOW);
						}
						break;
					case living :
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,living_pinLight,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,living_pinLight,DIO_u8PIN_LOW);
						}
						break;
					case bathroom:
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,bathroom_pinLight,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,bathroom_pinLight,DIO_u8PIN_LOW);
						}
						break;
					case kithen:
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,kithn_pinLight,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,kithn_pinLight,DIO_u8PIN_LOW);
						}
						break;
					case MainOpionts:
						break;
				}
				break;
			case option2 :
				USART_u8SendString("\nair system on");
				USART_u8SendString("\noption is: ");
				USART_u8SendString("\n1-master    2-living");
				USART_u8SendString("\n3-bathroom   4-kitchen\n5-Main Options");
				USART_u8SendString("\nchoose your room pleas:");
				Local_u8ResevedVal = USART_u8Receive();
				switch(Local_u8ResevedVal)
				{
					case master :
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,master_pinair,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,master_pinair,DIO_u8PIN_LOW);
						}
						break;
					case living :
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,living_pinair,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,living_pinair,DIO_u8PIN_LOW);
						}break;
					case bathroom:
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,bathroom_pinair,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,bathroom_pinair,DIO_u8PIN_LOW);
						}
						break;
					case kithen:
						USART_u8SendString("\n1-ON   0-Off");
						Local_u8ResevedVal = USART_u8Receive();
						/*on*/if(Local_u8ResevedVal == on)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,kithn_pinair,DIO_u8PIN_HIGH);
						}
						/*off*/else if(Local_u8ResevedVal==off)
						{
							DIO_VoidSetPinValue(airligtingsystem_port,kithn_pinair,DIO_u8PIN_LOW);
						}
						break;
					case MainOpionts:
						break;
				}
				break;
			case option3:
				USART_u8SendString("\nOptions : ");
				USART_u8SendString("1-Open   0-Close");
				USART_u8SendString("\nEnter the state:");
				Local_u8ResevedVal = USART_u8Receive();
				/*open*/if(Local_u8ResevedVal == on)
				{
					DOOR_voidOpenDoor();
					USART_u8SendString("\nThe door is opened now");
				}
				/*Close*/else if(Local_u8ResevedVal==off)
				{
					DOOR_voidCloseDoor();
					USART_u8SendString("\nThe door is closed now");
				}
				break;
			case option4:
				USART_u8SendString("\nEnter the user number form 0 to 9 :");
				Local_u8ResevedVal = USART_u8Receive()-'0';
				if(Local_u8ResevedVal<=9)
				{
					USART_u8SendString("\nEnter the new name :");
					APP_voidReseveUserNameAndWrite(Local_u8ResevedVal);
					USART_u8SendString("\nEnter the new Password :");
					APP_voidReseverUserPassAndWrite(Local_u8ResevedVal);
				}
				else
				{
					USART_u8SendString("\nInvalid user number :");
				}
				break;
			case option5:
				break;
		}
	}while(Local_u8option != option5);
}
void option_voidoptionInit(void)
{
	DIO_VoidSetPinDirection(airligtingsystem_port,master_pinLight,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,living_pinLight,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,kithn_pinLight,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,bathroom_pinLight,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,master_pinair,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,living_pinair,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,kithn_pinair,DIO_u8PIN_OUTPUT);
	DIO_VoidSetPinDirection(airligtingsystem_port,bathroom_pinair,DIO_u8PIN_OUTPUT);
	DOOR_voidDOORInit();
	DOOR_voidOpenDoor();/*Initial the door state*/
}
