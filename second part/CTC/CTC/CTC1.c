/*
 * CTC.c
 
 * Created: 6/7/2013
 
 *  Author: Jahira Sheik
 
 The algorithm sets the CTC feature ON by enabling the bit of WGM12 and with a prescalar value of 256 leads to a
 
 value of 14745600/256 = 57600, which when divided by 7 gives 8229.
 
 thus bit 6 of PORTB flashes for 1/7 of every second and bit 7 of PORTB flashes every second !!
 
 The scope of this algorithm in maintaining Longer time with firmwares is possible
 
 the register tccr1b is used to utilize the features of CTC etc
 
 register tccr0 is used to set the pwm functions
 
 */ 

#include <avr/io.h>

#include <util/delay.h>


int main(void)
{
	int count = 0;
	TCCR1B |= 1<<WGM12 | 1<<CS12;   // CTC enabled // prescalar of 256 //
	OCR1A = 8229;                    // OUTPUT COMPARE register , this is always compared with contents of tcnt1 by harware !
	DDRB |= 1<<7 | 1<<6;
	DDRB &= ~(1<<0);
	while(1)
    {
		if(TIFR & 1<<OCF1A)   // when the contents of tcnt1 matches ocr1a , OUTPUT COMPARE FLAG is set in the tifr register.
		{
			PORTB ^= 1<<6;TIFR = 1<<OCF1A;count++;  // the flag of tifr register is cleared by setting the flag bit to 1 !! weird !!
		}
		if(count>=7)
		{
		PORTB ^= 1<<7;
		count=0;
		}
	}
}	


