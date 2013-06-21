// multiple adc channels usage 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.c"

int main(void)
{

LCDInit(LS_ULINE);

LCDWriteString("X:");

LCDWriteStringXY(0,1,"Y:");


ADCSRA |= 1<<ADPS2;

ADMUX |= 1<<REFS0 ;

ADCSRA |= 1<<ADIE;

ADCSRA |= 1<<ADEN;

sei();

ADCSRA |= 1<<ADSC;

while (1)
{

}

}
ISR(ADC_vect)
{

switch (ADMUX)

{

case 0x40:

LCDWriteIntXY(4, 1, theTenBitResult, 4);

ADMUX = 0x41;

break;

case 0x41:

LCDWriteIntXY(4, 2, theTenBitResult, 4);

ADMUX = 0x40;

break;

default:

//Default code

break;

} ADCSRA |= 1<<ADSC;

}