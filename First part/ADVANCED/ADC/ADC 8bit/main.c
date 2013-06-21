//Simple ADC function on pin A0

#include<avr/io.h>

#include<stdlib.h>

#include<avr/interrupt.h>

#include "MrLCD.h"

void main ( void)

{

sei();


ADMUX |= 1<<ADLAR | 1 << REFS0;

ADCSRA |= 1 << ADEN | 1 <<ADPS2 | 1<<ADIE | 1<<ADSC;


while(1)

{}

}

ISR (ADC_vect)

{

char adcresult[4];
itoa(ADCH,adcresult,10);
GotoMrLCDsLocation(1,1);
Send_A_String(adcresult);
Send_A_String("");
ADCSRA |= 1<< ADSC;

}