/******************************
 * Author: Robert Mushrall III
 * Start date: 21 October 2016
 * Last Rev: 21 October 2016
 * Desc: Main program for
 * 		 atmel RTOS
 * ****************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "serialcom.h"	// Serial communication
#include "gsh.h"		// Shell

#define F_CPU 16000000
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU/(USART_BAUDRATE*16UL)))-1)

int8_t main(void){
	// Definitely want these
	sei();
	// Enables the LED for my keepalive
	DDRB = 1<<5;
	serialSetup(BAUD_PRESCALE);

	clearGshBuffer();	// Ensure command is cleared

	while(1){
		// Keepalive
		PORTB = PINB >> 2;
	}
}

// Interface through serial connection
ISR(USART_RX_vect){
	PINB = 1<<5;
	_delay_ms(100);
	serialReceive();
}
