// CTC Mode using Interrupts 

#include <avr/io.h>

#include <avr/interrupt.h>

int main (void)

{

  DDRB = 1 << PINB0; // or DDRB |= 1 << 0;
  
  sei(); // global interrupt enable
  
  TCCR1B = 1<<CS10 | 1 <<CS11 | 1<<WGM12;  // waveform generation mode
  
  TIMSK1 = 1 << OCIE1A;  // timer interrupt  mask register // output compare interrupt enable channel a 
  
  OCR1A = 15624;  //output compare  register
  
  while(1)
  {}
  
 }
  
  ISR(TIMER1_COMPA_vect)
  {
  PORTB ^= 1<< PINB0;
  }
  
  