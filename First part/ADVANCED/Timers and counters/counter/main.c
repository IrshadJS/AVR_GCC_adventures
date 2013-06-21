

#include <avr/io.h>

#include <util/delay.h>


void main(void)
{

DDRB = 0xff;  // all pins at port b are outputs

DDRD = 0xff; // all pins at port d are outputs

int LEDnumber[2]; // two arrays

TCCR1B = 1 << CS10 | 1 << CS11 ; // timer counter control register // prescale 1 // prescale 64

while(1)

{

if (TCNT1>2232)  // timer counter register stores the value of counter  // 1000000hz/64prescale = 15625/7= 2232 //

{

TCNT1 = 0;

PORTB = 1 << LEDnumber[0];  // light leds in increasing order

LEDnumber[0]++;              // array increment(Post)

if ( LEDnumber[0] >6)
{

LEDnumber[0]=0;

PORTD = 1 << LEDnumber[1];

LEDnumber[1]++;

if ( LEDnumber[1] > 6) LEDnumber[1]=0;

}

}

}

}