/*
 * Timer1_program.c
 *
 *  Created on: 6 Apr 2023
 *      Author: Re Go
 */
#include "STD_TYPES.h"
#include "Macros.h"
#include "Timer1_config.h"
#include "Timer1_interface.h"
#include "Timer1_register.h"


void (*TIMER1_pvGlobalCallBack)(void) = NULL;

void TIMER1_voidInit(void)
{
	/*choose fast PWM mode with top val ICR1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/*clear in top set on compare*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	/*Prescaler 8*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	
	//Disablr all of Interrupts
    CLR_BIT(TIMSK,TIMSK_TICIE1);
    CLR_BIT(TIMSK,TIMSK_TOIE1);
    CLR_BIT(TIMSK,TIMSK_OCIE1A);
    CLR_BIT(TIMSK,TIMSK_OCIE1B);
}

void TIMER1_voidSetTopVal(u16 Copy_u16CompVal)
{
	/*top value*/
	ICR1 = Copy_u16CompVal ;
}

void TIMER1_voidSetCompareMatchVal(u16 Copy_u16CompVal)
{
	OCR1A = Copy_u16CompVal;
}
u8 TIMER1_u8returnCompareMatchVal()
{
	return OCR1A ;
}

/*ICU PART**/

void ICU_voidICUInit(void)
{
	/*enable noise canceller*/
	SET_BIT(TCCR1B,TCCR1B_ICNC1);
	/*trigger edge rising edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	/*enable interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

u8 ICU_u8EdgeSelect(u8 copy_u8Edge)
{
	u8 local_u8ErrorStatus;
	switch(copy_u8Edge)
	{
	case ICU_RISING_EDGE : SET_BIT(TCCR1B,TCCR1B_ICES1); break;
	case ICU_FALLING_EDGE : CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	default : local_u8ErrorStatus = NOT_OK;
	}
	return local_u8ErrorStatus;
}

u16 ICU_u16ICURead(void)
{
	return ICR1;
}

void ICU_voidInterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_voidInterruptDisable()
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
void TIMER1_voidSetCallBack(void (*Copy_pvUserFunc) (void))
{
	if(Copy_pvUserFunc != NULL)
	{
		TIMER1_pvGlobalCallBack = Copy_pvUserFunc;
	}
	else
	{
		/*do nothing*/
	}
}



