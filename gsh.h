/***************************************
 * Author: Robert Mushrall III
 * Start Date: 07 October 2016
 * Last Rev: 07 October 2016
 * Desc: Specification for Gun Shell,
 * 		 a lightweight shell
 * 		 implementation for the atmel
 * ************************************/

#ifndef GUNSHELL
#define GUNSHELL

#ifndef CMDLEN
#define CMDLEN 64
#endif

int8_t clearGshBuffer();
int8_t addGshChar(char);
int8_t addGshString(uint8_t, char*);	// Change this when strings are implemented properly
int8_t executeGshBuffer();
int8_t validateChar(char);

#endif
