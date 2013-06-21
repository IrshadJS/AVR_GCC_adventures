// led flasher with button //

/* led flashes for 5 times after the button is pressed 5 times */

#include<avr/io.h>

#include<util/delay.h>

void main(void)

{

DDRB |= 1<<7 | 1 <<6;

DDRB &= ~(1<<0);

PORTB |= 1<<0;PORTB ^= 1<<7;

int pressed = 0;

int pressed_confidence = 0;

int released_confidence = 0;

int count=0;

for(;;)

{

if(bit_is_clear(PINB,0))

{

pressed_confidence++;

if(pressed_confidence > 400)

{

if(pressed == 0)

{

pressed =1;

pressed_confidence = 0;

count++;

//


}

}

}

else 

{

released_confidence++;

if(released_confidence >400)

{

if( pressed ==1 )
{

pressed =0;

released_confidence = 0;

}

}

}

if(count >= 5)

{

 for(int i=0;i<6;i++)
 
 {
   _delay_ms(1000);
   
    PORTB ^= 1<<7 | 1<<6;
   
   _delay_ms(1000);
   
   count =0;
  }
 
 }
 
 }
 
 }