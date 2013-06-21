

#include <avr/io.h>

#include <util/delay.h>


void main(void)
{

DDRB=0x01;  //   also DDRB = 1 << PORTB0;

PORTB  ^= ( 1 << PINB0); // toggle leds

DDRB = 1 << PINB2;  // set pinb2 as output

DDRB &= ~(1<<PINB1);   //  set pinb1 as input

PORTB = 1 << PINB1; // set pinb1 as high ( as, if switch is pressed the pinb register holds value o at 1st pin)

int pressed = 0;           // variable 1

int pressed_confidence = 0; // variable 2

int released_confidence = 0;  // variable 3

while(1)

{

if (bit_is_clear(PINB,1))    //  the fn sees if the value at pinb eg is 0 at position 1
  {
    pressed_confidence++;
		if( pressed_confidence > 500)
	{
		if(pressed == 0)  // logic is that the pressed will be equal to one only after it is equal to zero
			{
				PORTB ^= (1 << PINB0);
					PORTB ^= (1 << PINB2);
						pressed = 1;
			}
	pressed_confidence = 0;

	}
  }
		
	else
	{	
	 released_confidence ++;
	 if(released_confidence > 500)
		{
			pressed = 0;
		}
	}

  }

 }


