/*
 * Lcd_cfg.h
 *
 *  Created on: Sep 2, 2022
 *      Author: ahmad
 */

#ifndef INC_LCD_CFG_H_
#define INC_LCD_CFG_H_
/*********** LCD NUMBER_DATA_PINS ***********/
#define LCD_8_BINS 0
#define LCD_4_BINS 1
#define LCD_BATA_BINS LCD_8_BINS

/************* LCD Control Pins *************/
#define LCD_PIN_RS DIO_PORTB,DIO_PIN0
#define LCD_PIN_RW DIO_PORTB,DIO_PIN1
#define LCD_PIN_EN DIO_PORTB,DIO_PIN2

/************* LCD Data Pins *************/
#if ( LCD_BATA_BINS == LCD_8_BINS)
    #define LCD_PIN_D0 DIO_PORTA,DIO_PIN0
    #define LCD_PIN_D1 DIO_PORTA,DIO_PIN1
    #define LCD_PIN_D2 DIO_PORTA,DIO_PIN2
    #define LCD_PIN_D3 DIO_PORTA,DIO_PIN3
#endif
#define LCD_PIN_D4 DIO_PORTA,DIO_PIN4
#define LCD_PIN_D5 DIO_PORTA,DIO_PIN5
#define LCD_PIN_D6 DIO_PORTA,DIO_PIN6
#define LCD_PIN_D7 DIO_PORTA,DIO_PIN7

/************* LCD Display Control *************/
#define LCD_DISPLAY_STATUS  LCD_DISPLAY_ON
#define LCD_CURSOR_STATUS   LCD_CURSOR_OFF
#define LCD_LINE_STATUS     LCD_TWO_LINES
#define LCD_FONT_STATUS     LCD_FONT_5X7


#endif /* INC_LCD_CFG_H_ */
