/*
 * uart.c
 *
 * Created: 04-05-2016 13:29:14
 *  Author: RISHABH JAIN
 */ 


#include <avr/io.h>
#include "uart.h"

char uart_rec()
{
	UCSRB|=(1<<RXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=77;
	
    while((UCSRA & (1<<RXC))==0);
	return UDR;
}

void uart_trx(unsigned char ch)
{
	UCSRB|=(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL=51;
	while((UCSRA & (1<<UDRE))==0);
	UDR=ch;
}
