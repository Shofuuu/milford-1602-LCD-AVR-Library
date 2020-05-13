/*
 * milford_lcd_uart.c
 *
 * Created: 5/13/2020 7:41:03 PM
 * Author : shofuwan
 */ 

#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include "milford1602.h"

int main(void){
	lcd_init();
	
    while(1){
		lcd_gotoxy(0,0);
		lcd_puts("Milford1602");
		lcd_gotoxy(0,1);
		lcd_puts("UART LCD");
    }
}

