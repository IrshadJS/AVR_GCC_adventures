#include <avr/io.h>
#include <avr/delay.h>
void main(void)
{
DDRB=0x01; //   also DDRB = 1 << PORTB0; // initialise pin b0 as output
while(1)
{

PORTB=0x01;         // also  PORTB  ^= 1<<PINB0;  // also PORTB &= ~(1 << PINB0)
_delay_ms(100);

PORTB=0;               // turn off 5v at pin b0
_delay_ms(100);


}
}
