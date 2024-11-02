/*
 * APPuser_program.c
 *
 *  Created on: 30 Aug 2023
 *      Author: kareem
 */
/*****************************LIBARRAY********************************************/
#include "STD_TYPES.h"
#include "Macros.h"
/*****************************MCAL**********************************************/
#include <avr/eeprom.h>
#include <util/delay.h>
#include "GIE_interface.h"
#include "USART_interface.h"
#include "Lcd.h"
/*****************************APPuser*********************************************/
#include "APPuser_interface.h"
#include "APPuser_privet.h"


/****************************************************
 * @fn APP1_u8ReseveNameAndCheck
 * @brief the function receive the name throw USART,Put in buffer array and check it
 * @param[out] UserNamber :pointer to variable put the user number in this variable by uesing this pointer
 * @retval name state wither the name is correct or not
 */
APP_PassStaute_t APP1_u8ReseveNameAndCheck(u8 * UserNamber)
{
    APP_PassStaute_t Output=PASS_IS_CORRECT;
    u8 temp=0,i,j,NumOfLetters,NameArry[NUMBER_OF_NAME_LETTERS]={0,0,0,0,0,0,0,0,0,0};
    /*Resef Name*/
    for ( i = 0; i < NUMBER_OF_NAME_LETTERS; i++)
    {
        temp=USART_u8Receive();
        if (Blutooth_NULL_Char==temp)
        {
            break;
        }
        NameArry[i]=temp;
    }
    /*Check*/
    if (i<10)
    {
        NumOfLetters = i;
       for ( i = 0; i < MAX_NUMBER_OF_USERS; i++)
       {
        for ( j = 0; j < NumOfLetters; j++)
        {
            if (NameArry[j]!=eeprom_read_byte((u8*)STATIC_NAME_ADDRESSES_OFFSET+i*NUMBER_OF_NAME_LETTERS+j))
            {
                /*error in user name*/
                break;
            }
            _delay_ms(10);
        }
        if (j==NumOfLetters)
        {
            /*User name is found*/
            *UserNamber = i;
            break;
        }
       }
       if (i==MAX_NUMBER_OF_USERS)
       {
        /*User name not found*/
        Output=PASS_IS_NOT_CORRECT;
       }
       
    }
    else
    {
        Output=PASS_IS_NOT_CORRECT;
    }
    return Output;
}
/****************************************************
 * @fn APP_u8ReseveUserPasswordAndCheck
 * @brief the function receive the password throw USART,Put in buffer array and check it
 * @param[in] Copy_u8UserNumber :the number of the user
 * @retval Password state wither the password is correct or not
 */
APP_PassStaute_t APP_u8ReseveUserPasswordAndCheck(APP_userNumber_t Copy_u8UserNumber)
{
    APP_PassStaute_t Output=PASS_IS_CORRECT;
    u8 temp=0,i,NumOfLetters,NameArry[NUMBER_OF_PASS_LETTERS]={0,0,0,0,0,0,0,0,0,0};
    /*Resef Name*/
    for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        temp=USART_u8Receive();
        if (Blutooth_NULL_Char==temp)
        {
            break;
        }
        NameArry[i]=temp;
    }
    /*Check*/
    if (i<10)
    {
        NumOfLetters = i;
        for ( i = 0; i < NumOfLetters; i++)
        {
            if (NameArry[i]!=eeprom_read_byte((u8*)STATIC_PASS_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_NAME_LETTERS+i))
            {
                /*error in user name*/
                break;
            }
        }
        if (i==NumOfLetters)
        {
            /*User name is found*/
            Output=PASS_IS_CORRECT;
        }
        else
        {
            /*User name not found*/
            Output=PASS_IS_NOT_CORRECT;
        }
       
    }
    else
    {
        Output=PASS_IS_NOT_CORRECT;
    }
    return Output;
}
/****************************************************
 * @fn APP_voidReseveUserNameAndWrite
 * @brief the function receive the new name throw USART and Put in buffer array the store in EEPROM
 * @param[in] Copy_u8UserNumber :the number of the user
 * @retval No return value
 */
void APP_voidReseveUserNameAndWrite(APP_userNumber_t Copy_u8UserNumber)
{
    u8 temp=0,i;
    /*Resef Name*/
    for ( i = 0; i < NUMBER_OF_NAME_LETTERS; i++)
    {
        temp=USART_u8Receive();
        if (Blutooth_NULL_Char==temp)
        {
            break;
        }
        eeprom_write_byte((u8*)STATIC_NAME_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_NAME_LETTERS+i,temp);
    }
    for ( ; i < NUMBER_OF_NAME_LETTERS; i++)
    {
        eeprom_write_byte((u8*)STATIC_NAME_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_NAME_LETTERS+i,0);
    }
}
/****************************************************
 * @fn APP_voidReseverUserPassAndWrite
 * @brief the function receive the new password throw USART and Put in buffer array the store in EEPROM
 * @param[in] Copy_u8UserNumber :the number of the user
 * @retval No return value
 */
void APP_voidReseverUserPassAndWrite(APP_userNumber_t Copy_u8UserNumber)
{
    u8 temp=0,i;
    /*Resef Name*/
    for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        temp=USART_u8Receive();
        if (Blutooth_NULL_Char==temp)
        {
            break;
        }
        eeprom_write_byte((u8*)STATIC_PASS_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_PASS_LETTERS+i,temp);
    }
    for ( ; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        eeprom_write_byte((u8*)STATIC_PASS_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_PASS_LETTERS+i,0);
    }
}
/****************************************************
 * @fn APP_voidAllPassesInit
 * @brief the function store in the initialization passwords EEPROM
 * @retval No return value
 */
void APP_voidAllPassesInit(void)
{
    u8 temp,i,Copy_u8UserNumber,Arry[5]="1234";
    /*Resef Name*/
    for (Copy_u8UserNumber = 0; Copy_u8UserNumber < 10; Copy_u8UserNumber++)
    {
        for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
        {
            temp=Arry[i];
            if ('\0'==temp)
            {
                break;
            }
            eeprom_write_byte((u8*)STATIC_PASS_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_PASS_LETTERS+i,temp);
        }
        for ( ; i < NUMBER_OF_PASS_LETTERS; i++)
        {
            eeprom_write_byte((u8*)STATIC_PASS_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_PASS_LETTERS+i,0);
        }
    }
}
/****************************************************
 * @fn APP_voidAllUserNamesInit
 * @brief the function store in the initialization user names EEPROM
 * @retval No return value
 */
void APP_voidAllUserNamesInit(void)
{
    u8 temp,i,Copy_u8UserNumber,Arry[5]="user";
    /*Resef Name*/
    for (Copy_u8UserNumber = 0; Copy_u8UserNumber < 10; Copy_u8UserNumber++)
    {
        for ( i = 0; i < NUMBER_OF_NAME_LETTERS; i++)
        {
            temp=Arry[i];
            if ('\0'==temp)
            {
                break;
            }
            eeprom_write_byte((u8*)STATIC_NAME_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_NAME_LETTERS+i,temp);
        }
        for ( ; i < NUMBER_OF_NAME_LETTERS; i++)
        {
            eeprom_write_byte((u8*)STATIC_NAME_ADDRESSES_OFFSET+Copy_u8UserNumber*NUMBER_OF_NAME_LETTERS+i,0);
        }
    }
}


















/************************************************************************************************
void APP_voidWriteUserPassword(APP_userNumber_t Copy_u8UserNumber,u8* pvUserPassword)
{
    u8 i,postionOffset=STATIC_PASS_ADDRESSES_OFFSET + (NUMBER_OF_PASS_LETTERS*Copy_u8UserNumber);
    GIE_voidDisable();
    for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        EEPROM_voidWriteData(postionOffset+i,pvUserPassword[i]);
    }
    GIE_voidEnable();
}

APP_PassStaute_t APP_u8CheckUserPassword(APP_userNumber_t Copy_u8UserNumber,u8* pvUserPassword)
{
    u8 i,postionOffset=STATIC_PASS_ADDRESSES_OFFSET + (NUMBER_OF_PASS_LETTERS*Copy_u8UserNumber);
    APP_PassStaute_t Output=PASS_IS_CORRECT;
    for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        if (pvUserPassword[i]!=EEPROM_u8ReadData(postionOffset+i))
        {
            Output=PASS_IS_NOT_CORRECT;
        }
    }
    return Output;
}


void APP_voidWriteUserName(APP_userNumber_t Copy_u8UserNumber,u8* pvUserName)
{
    u8 i,postionOffset=STATIC_NAME_ADDRESSES_OFFSET + (NUMBER_OF_NAME_LETTERS*Copy_u8UserNumber);
    GIE_voidDisable();
    for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        EEPROM_voidWriteData(postionOffset+i,pvUserName[i]);
    }
    GIE_voidEnable();
}

APP_PassStaute_t APP_u8CheckUserName(APP_userNumber_t Copy_u8UserNumber,u8* pvUserName)
{
    u8 i,postionOffset=STATIC_NAME_ADDRESSES_OFFSET + (NUMBER_OF_NAME_LETTERS*Copy_u8UserNumber);
    APP_PassStaute_t Output=PASS_IS_CORRECT;
    for ( i = 0; i < NUMBER_OF_PASS_LETTERS; i++)
    {
        if (pvUserName[i]!=EEPROM_u8ReadData(postionOffset+i))
        {
            Output=PASS_IS_NOT_CORRECT;
        }
    }
    return Output;
}
*/
