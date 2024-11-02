/*
 * USART_program.c
 *
 *  Created on: 26 Nov 2022
 *      Author: kareem
 */


#include "STD_TYPES.h"
#include "Macros.h"
#include "GIE_interface.h"
#include "USART_interface.h"
#include "USART_register.h"
#include "USART_config.h"
#include "USART_privet.h"

void USART_voidInit(void)
{
    /*data size bit 2 to 8 bit mode*/
    CLR_BIT(UCSRB,UCSRB_UCSZ2);


    UCSRC = 134;

    /*sety baud rate value */
    UBRRL = 51;

    //RECEIVE ENABLE
    SET_BIT(UCSRB,UCSRB_RXEN);
    //Transimission ENABLE
    SET_BIT(UCSRB,UCSRB_TXEN);
}
 
void USART_voidSendData(u8 Copy_u8Data)
{

    while (GET_BIT(UCSRA,UCSRA_UDRE) == 0);
    
    UDR =   Copy_u8Data;        
    
}

u8 USART_u8Receive(void)
{
    while (GET_BIT(UCSRA,UCSRA_RXC) == 0);
     
    return UDR;
}
void USART_u8SendString(u8 *str)
{
    while (*str != 0)
    {
    	USART_voidSendData(*str);
        str++;
    }
}


