/*
 * CTC.c
 *
 * Created: 6/7/2013 11:12:53 PM
 *  Author: Jahira Sheik
 */ 

#include <avr/io.h>
#include <util/delay.h>

void sleep ( uint8_t ms ) 
{ 
    for ( ; ms> 0;ms -- ) _delay_ms ( 1 ) ;
 }
int main(void)
{
	int count = 0;
	int time1=0;
	TCCR1B |= 1<<WGM12 | 1<<CS12;
	OCR1A = 57600;
	DDRB |= 1<<7 | 1<<6;
	DDRB &= ~(1<<0);
	PORTB ^= 1<<6;
    while(1)
    {
		if(TIFR & 1<<OCF1A)
		{
			count++;
			TIFR = 1<<OCF1A;
		}
		if(count>=2)
		{
			time1++;
			PORTB ^= 1<<6|1<<7;
			count=0;
		}		
			else if(time1 >=2)
			{
				for(int i =30;i>0;i--)
				{
			  sleep(50);
			   PORTB ^= 1<<6|1<<7;
			  sleep(50);
			  PORTB ^= 1<<6|1<<7;
				time1=0;
				}	
		}			
						
			}
	}
	


