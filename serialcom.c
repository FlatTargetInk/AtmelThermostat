/******************************
 * Author: Robert Mushrall III
 * Start Date: 21 October 2016
 * Last Rev: 21 October 2016
 * Desc: Base serial functions
 * ***************************/

#include <avr/io.h>
#include "serialcom.h"
#include "gsh.h"

int8_t serialSetup(uint16_t baud_prescale){
	// Setup serial status and control register
	UCSR0B |= (1<<RXEN0)	// Receive enable
			| (1<<TXEN0)	// Transmit enable
			| (1<<RXCIE0);	// Receive interrupt enable

	UCSR0C |= (1<<UCSZ00) 	// Don't question it.
			| (1<<UCSZ01);	// Don't question it.

	UBRR0H = (baud_prescale >> 8);
	UBRR0L = baud_prescale;
	return 1;
}

void serialReceive(){
	char received_byte[1];
	while((UCSR0A & (1 << RXC0)) == 0);
	received_byte[0] = UDR0;
	switch(received_byte[0]){
		case '\r':
			serialSend(2,"\n\r");
			executeGshBuffer();
			break;
		default:
			if(addGshChar(received_byte[0]) > 0)
				serialSend(1,received_byte);
			break;
	}
}

int8_t serialSend(uint8_t n, char* string){
	for(int i = 0; i < n; i++){
		// Waiting for USART to be ready...
		while((UCSR0A & (1 << UDRE0)) == 0);
		UDR0 = string[i];
	}
	return 1;
}
