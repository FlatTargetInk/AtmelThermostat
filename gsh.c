/**********************************************
 * Author: Robert Mushrall III
 * Start Date: 07 October 2016
 * Last Rev: 07 October 2016
 * Desc: Gun Shell, light weight shell
 * 		 implementation for the atmel
 * *******************************************/

#include <avr/io.h>
#include "gsh.h"
#include "serialcom.h"

char cmdBuffer[CMDLEN];
uint8_t cursor = 0;

int8_t clearGshBuffer(){
	uint8_t i;
	for(i = 0; i < CMDLEN; i++)
		cmdBuffer[i] = '\0';
	cursor = 0;
	return 1;
}

int8_t addGshChar(char in){
	if(cursor == CMDLEN)
		return -1;	// Buffer full
	if(!validateChar(in))
		return -2;	// Illegal character
	cmdBuffer[cursor++] = in;
	return 1;
}

int8_t addGshString(uint8_t n, char* in){
	uint8_t i;
	int8_t status;
	for(i = 0; i < n; i++)
		status = addGshChar(in[i]);
	return status;
}

int8_t executeGshBuffer(){
	serialSend(cursor,cmdBuffer);
	serialSend(2,"\r\n");
	clearGshBuffer();
	return 1;
}

int8_t validateChar(char in){
	if(in > 31 && in != 127)
		return 1;
	return 0;
}
