/*
 * =====================================================================================
 *
 *       Filename:  thermostat.c
 *
 *    Description:  Thermostat operations, using a thermistor
 *
 *        Version:  1.0
 *        Created:  10/15/2016 12:16:07 PM
 *       Revision:  none
 *       Compiler:  avr-gcc
 *
 *         Author:  Robert Mushrall III
 *   Organization:  
 *
 * =====================================================================================
 */

#include <avr/io.h>
#include "thermostat.h"
#include "serialcom.h"

int8_t getTemp(){
    serialSend(36,"You have reached the thermostat!!!\r\n");
    return 1;
}
