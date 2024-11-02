/*
 * Timer1_interface.h
 *
 *  Created on: 6 Apr 2023
 *      Author: Re Go
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_
#define ICU_RISING_EDGE 1
#define ICU_FALLING_EDGE 2



void TIMER1_voidInit(void);

void TIMER1_voidSetTopVal(u16 Copy_u16CompVal);

void TIMER1_voidSetCompareMatchVal(u16 Copy_u16CompVal);

u8 TIMER1_u8returnCompareMatchVal();
/*ICU PART**/
void ICU_voidICUInit(void);
void TIMER1_voidSetCallBack(void (*Copy_pvUserFunc) (void));


u8 ICU_u8EdgeSelect(u8 copy_u8Edge);

u16 ICU_u16ICURead(void);

void ICU_voidInterruptEnable(void);

void ICU_voidInterruptDisable();







#endif /* TIMER1_INTERFACE_H_ */
