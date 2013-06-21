/*
 * USART.c
   use web for ubrr val generation
   
   http://www.josephn.net/avr/avr_ubrr_calculator
   
   The following algortihm focuses on Communicating bytes between pc and uc in the form of frames
   
   stop bit,parity,baud rate ,ubrr value have to be set and calibrated for the perfect working of the code
   
 * Created: 6/14/2013 10:10:23 PM
 
 *  Author: Jahira Sheik
 
 */ 

#include <avr/io.h>

#include <inttypes.h>

void usartinit(uint16_t ubrrval)
{
	
	UBRRL = ubrrval;
	UBRRH = ubrrval >> 8; // the right shift is done so that the higher byte of the 16 bit value is shifted to UBBRH
	
	UCSRC = (1<<URSEL)|(3<<UCSZ0); // Stop bit is 1 , Parity is none , asynchronous mode, 1byte or 8 bit
	UCSRB = (1<<TXEN)|(1<<RXEN); // transmission and reception enabled
	
}

int usartreadchar() // INT !!
{
	
	while(!(UCSRA&(1<<RXC))) // wait till the receiver is ready (indicated by receiver buffer)
	{
	}
	return UDR;		// Return the value from UDR register
	}


void usartwritechar(char data)
{
	while(!(UCSRA&(1<<UDRE))) // Wait till the Write buffer is full and ready to transmit
	{
	}		
	UDR=data; // the char is written into the UDR regidster
	
}
void main()
{
	char data;
	
	usartinit(47); // UBRR value value is calculated from the website indicated above
	
    while(1)
    {
        data=usartreadchar();
		usartwritechar('[');
		usartwritechar(data);
		usartwritechar(']');
		
		}
}