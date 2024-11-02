/*
 * APPuser_interface.h
 *
 *  Created on: 30 Aug 2023
 *      Author: kareem
 */

#ifndef APPUSER_INTERFACE_H_
#define APPUSER_INTERFACE_H_
typedef enum
{
    USER_1=0U,
    USER_2,
    USER_3,
    USER_4,
    USER_5,
    USER_6,
    USER_7,
    USER_8,
    USER_9,
    USER_10,
}APP_userNumber_t;
typedef enum
{
    PASS_IS_NOT_CORRECT=0U,
    PASS_IS_CORRECT,
}APP_PassStaute_t;

APP_PassStaute_t APP1_u8ReseveNameAndCheck(u8 * UserNamber);
APP_PassStaute_t APP_u8ReseveUserPasswordAndCheck(APP_userNumber_t Copy_u8UserNumber);
void APP_voidReseveUserNameAndWrite(APP_userNumber_t Copy_u8UserNumber);
void APP_voidReseverUserPassAndWrite(APP_userNumber_t Copy_u8UserNumber);
void APP_voidAllPassesInit(void);
void APP_voidAllUserNamesInit(void);
#endif /* APPUSER_INTERFACE_H_ */
