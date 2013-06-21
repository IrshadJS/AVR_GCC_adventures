/*
 * 1_chnl_PWM_fast.c
 * Created: 6/8/2013 2:47:22 AM
 *  Author: Jahira Sheik
 
 The algorithm discusses the possibilities of channel 0 PWM utilizing the 8 bit timer tccr0
 the ocr0 holds the duty cycle ,which is generally called as PWM signal
 
 */ 

#include <avr/io.h>

#include <util/delay.h>

void sleep (uint8_t y)
{
	for(;y>0;y--)_delay_ms(1);
}
void inititlaize_pwm()
{
	TCCR0 |= 1<<WGM00 | 1<<WGM01 | 1<<CS00 | 1<<COM01; // cs00 sets no clk prescaling // com01 indicates non inverted pwm // wgm 00 and 01 
														// indicates that the current set mode is of the fast pwm mode
	
}
void set_pwm_cycle(uint8_t x)
{
	
	OCR0 = x;  // the reg holds the duty cycle
}
int main(void)
{
	inititlaize_pwm();  // PWM initialized
	DDRB |= 1<<3; // 0c0/ pin b3 of PORTB as output
	
	    while(1)
    {
        for(int i=0;i<=255;i++) // Brightness increase
		{
			set_pwm_cycle(i);
			sleep(10);
		}
		for(int j=255;j>0;j--)	//Brightness decrease
		{
			set_pwm_cycle(j);
			sleep(10);
		}
	}
}