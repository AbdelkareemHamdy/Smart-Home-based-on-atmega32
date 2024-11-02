/*
 * smart_door_program.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Re Go
 */
#include "STD_TYPES.h"
#include "Macros.h"
#include "Timer1_interface.h"
#include "DIO_Interface.h"
#include "smart_door_config.h"
#include "smart_door_interface.h"
#include "smart_door_private.h"

void DOOR_voidDOORInit(void)
{
	TIMER1_voidInit();
	/*fixed top value to give u 20ms periodic time */
	TIMER1_voidSetTopVal(20000);
	DIO_VoidSetPinDirection(DOOR_PORT,DOOR_PIN,DIO_u8PIN_OUTPUT);
}
void DOOR_voidOpenDoor(void)
{

	TIMER1_voidSetCompareMatchVal(open);
}

void DOOR_voidCloseDoor(void)
{

	TIMER1_voidSetCompareMatchVal(close);

}


