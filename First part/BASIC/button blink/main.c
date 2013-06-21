#include <avr/io.h>

#include <util/delay.h>

void main(void)
{
DDRB=0x01;  //   also DDRB = 1 << PORTB0;

DDRB &= ~(1<<PINB1);   //  set pinb1 as input

PORTB = 1 << PINB1; // set pinb1 as high ( as, if switch is pressed the pinb register holds value o at 1st pin)

while(1)

{

PORTB ^= ~(0x01);         // also  PORTB  ^= 1<<PINB0;  // also PORTB &= ~(1 << PINB0)


if (bit_is_clear(PINB,1) )     //  the fn sees if the value at pinb eg is 0 at position 1
{
_delay_ms(10);             // toggle speed 10 ms
}
else
{
_delay_ms(100);   // toggle speed 100 ms
}

}

}
