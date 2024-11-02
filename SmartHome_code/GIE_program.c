/*
 * GIE_program.c
 *
 *  Created on: 26 Oct 2022
 *      Author: kareem
 */

#include "STD_TYPES.h"
#include "Macros.h"
#include "GIE_register.h"
#include "GIE_interface.h"

//Global Interrupt Enable
//Enable
void GIE_voidEnable(void)
{
    SET_BIT(SREG,SREG_I);
}

//Disable
void GIE_voidDisable(void)
{
    CLR_BIT(SREG,SREG_I);
}

