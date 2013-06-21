/*
ADC functions datasheet page 216 and  214 with lcd library from extreme electronics included...


 * Created: 6/8/2013 7:21:53 PM
 *  Author: Jahira Sheik
 */ 

#include <avr/io.h>

#include <util/delay.h>

//#include <stdlib.h>

#include <avr/interrupt.h>

#include "lcd.h"

int main(void)
{
	//LCDClear();
	
	LCDInit(LS_NONE);  // three arguments available are blink,underline and none...
	
		
	LCDWriteStringXY(0,0,"X");   // Row and column and message
	
	LCDWriteStringXY(0,1,"Y");
	
	sei();							// Enable global interrupts


    ADMUX |= 1<<REFS0;              // Sets the device to use avcc as refernce for adc conversion

    ADCSRA |= 1 << ADEN | 1 <<ADPS2 | 1<<ADIE | 1<<ADSC;   // ADC enabled , Clock prescalar to 16 , ADC interrupt enabled , ADC conversion started......

	while(1)
    {
        
    }
}

ISR (ADC_vect)
{

uint8_t theLow = ADCL;

uint16_t theTenBitResult = ADCH<<8 | theLow;


switch (ADMUX)

{

case 0x40:

LCDWriteIntXY(4,0, theTenBitResult, 4);

ADMUX = 0x41;

break;

case 0x41:

LCDWriteIntXY(4,1, theTenBitResult, 4);

ADMUX = 0x40;

break;

default:

//Default code

break;

}
 ADCSRA |= 1<<ADSC;
}