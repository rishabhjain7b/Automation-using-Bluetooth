/*
 * uart.h
 *
 * Created: 04-05-2016 13:29:38
 *  Author: RISHABH JAIN
 */ 


#ifndef UART_H_
#define UART_H_
#include<util/delay.h>
#include <avr/io.h>
char uart_rec();
void uart_trx(unsigned char ch);
#endif /* UART_H_ */