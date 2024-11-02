/*
 * main.c
 *
 *  Created on: 26 Nov 2022
 *      Author: kareem
 */

#include "STD_TYPES.h"
#include "Macros.h"
#include <util/delay.h>
#include <avr/eeprom.h>
#include "Dio.h"
#include "Lcd.h"
#include "USART_interface.h"
#include "GIE_interface.h"
#include "APPuser_interface.h"
#include "app2_interface.h"
int main()
{
    u8 i;

    APP_userNumber_t User_Number=0;
    u8 PassTrys=0;
    APP_PassStaute_t Pass_State=0;
    /*pin rx input*/
    Dio_SetPinMode(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT_FLOATING);
    /*pin Tx output*/
    Dio_SetPinMode(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
    /*intion usart*/
    USART_voidInit();
    if ('W'!=eeprom_read_byte(250))
    {
    	/*eeprom not initialized*/
        eeprom_write_byte(250,'W');
        APP_voidAllPassesInit();
        APP_voidAllUserNamesInit();
    }

    option_voidoptionInit();

    Lcd_Init();


    while (1)
    {
    	Lcd_DisplayClear();
        Lcd_DisplayString((u8*)"Welcome");
    	PassTrys=0;
    	/*Take user name and password*/
        do
        {
            if (PassTrys!=0)
            { 
                USART_u8SendString((u8*)"\nWrong try again");
                USART_u8SendString((u8*)"\nremine :");
                USART_voidSendData(3-PassTrys+'0');
                USART_u8SendString((u8*)" Trys");
            }
            USART_u8SendString((u8*)"\nEnter user name:");
            Pass_State = APP1_u8ReseveNameAndCheck(&User_Number);
            if (Pass_State==PASS_IS_CORRECT)
            {
                USART_u8SendString((u8*)"\nEnter the password:");
                Pass_State = APP_u8ReseveUserPasswordAndCheck(User_Number);
            }
            PassTrys++;
        }while((PassTrys<3)&&(Pass_State!=PASS_IS_CORRECT));
        /*Options*/
        if (Pass_State==PASS_IS_CORRECT)
        {
        	Lcd_DisplayClear();
        	Lcd_DisplayString((u8*)"correct pass");
            option_voidChooseOptione();
        }
        else
        {
            for ( i = 0; i < 1000; i++)
            {
                USART_u8SendString((u8*)"wait remain");
                if (i>=100)
                {
                    USART_voidSendData((i/100)+'0');
                }
                if (i>=10)
                {
                    USART_voidSendData(((i%100)/10)+'0');
                }
                USART_voidSendData(((i%100)%10)+'0');
                USART_u8SendString((u8*)"for 1000");
                _delay_ms(1000);
            }
        }
    }    
    while (1);
}
