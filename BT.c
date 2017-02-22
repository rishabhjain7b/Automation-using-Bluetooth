/*
 * BT.c
 *
 * Created: 14-06-2016 11:57:34
 *  Author: RISHABH JAIN
 */ 


#include <avr/io.h>
#include <util/delay.h>
//#include "uart.h"
//#define F_CPU 12000000


char uart_rec()
{
	UCSRB|=(1<<RXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=77;
	
	while((UCSRA & (1<<RXC))==0);
	return UDR;
}


void main()
{
	DDRB=0xFF;
	char x;
    while(1)
    {
        x=uart_rec();
		if(x=='1')
		PORTB|=(1<<PB2);
		_delay_ms(10);
		if(x=='2')
		PORTB|=(1<<PB3);
		_delay_ms(10);
		if(x=='3')
		PORTB|=(1<<PB4);
		_delay_ms(10);
		if(x=='4')
		PORTB&=~((1<<PB2)|(1<<PB3)|(1<<PB4));
		_delay_ms(10);
    }
}