/*
 * USART_interface.h
 *
 *  Created on: 26 Nov 2022
 *      Author: kareem
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
 
void USART_voidSendData(u8 Copy_u8Data);

u8 USART_u8Receive(void);
void USART_u8SendString(u8 *str);

#endif /* USART_INTERFACE_H_ */
