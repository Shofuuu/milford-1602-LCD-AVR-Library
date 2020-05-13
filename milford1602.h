/*
 * milford1602.h
 *
 * Created: 5/13/2020 7:41:03 PM
 * Author : Muhammad Shofuwan Anwar
 */ 

#include <avr/io.h>

static void lcd_init(){
	unsigned char ubrr0 = ((F_CPU)/(9600*16UL)-1);
	
	UBRR0L = (ubrr0);
	UBRR0H = (ubrr0>>8);
	
	UCSR0B |= (1<<TXEN0);
	UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);
}

static void lcd_put(unsigned char c){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}

static void lcd_puts(char* s){
	while(*s){
		lcd_put(*s);
		s++;
	}
}

static void lcd_gotoxy(unsigned char px, unsigned char py){
	lcd_put(254);
	
	if(py == 0)
		lcd_put(128 + px);
	else
		lcd_put(192 + px);
}

static void lcd_clear(){
	lcd_put(254);
	lcd_put(1);
}

static void lcd_new_char(unsigned char c[8], unsigned char addr){
	if(addr > 8)
		addr = 7;
	
	lcd_put(254);
	lcd_put(64 + (8*addr));
	for(int x=0;x<8;x++)
		lcd_put(c[x]);
}

static void lcd_show_char(unsigned char addr){
	lcd_put(254);
	lcd_put(addr);
}
