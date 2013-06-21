/* 

A program to demonstrate the use of seven segment displays.

Hardware:
A single seven segment display connected to PORTD as

a->PD7
b->PD6
c->PD5
d->PD4

e->PD3
f->PD2
g->PD1
DP->PD0

*/

#include <avr/io.h>
#include <util/delay.h>

//Configurations

//**************
// Here you may cange the port in which you have connected the display
#define SEVEN_SEGMENT_PORT PORTD
#define SEVEN_SEGMENT_DDR DDRD


void SevenSegment(uint8_t n,uint8_t dp)
{
/*
This function writes a digit given by n to the display

the decimal point is displayed if dp=1

Note:
n must be less than 9
*/
   if(n<10)
   {
      switch (n)
      {
         case 0:
         SEVEN_SEGMENT_PORT=0b00000011;
         break;

         case 1:
         SEVEN_SEGMENT_PORT=0b10011111;
         break;

         case 2:
         SEVEN_SEGMENT_PORT=0b00100101;
         break;

         case 3:
         SEVEN_SEGMENT_PORT=0b00001101;
         break;

         case 4:
         SEVEN_SEGMENT_PORT=0b10011001;
         break;

         case 5:
         SEVEN_SEGMENT_PORT=0b01001001;
         break;

         case 6:
         SEVEN_SEGMENT_PORT=0b01000001;
         break;

         case 7:
         SEVEN_SEGMENT_PORT=0b00011111;
         break;

         case 8:
         SEVEN_SEGMENT_PORT=0b00000001;
         break;

         case 9:
         SEVEN_SEGMENT_PORT=0b00001001;
         break;
      }
      if(dp)
      {
         //if decimal point should be displayed

         //make 0th bit Low
         SEVEN_SEGMENT_PORT&=0b11111110;
      }
   }
   else
   {
      //This symbol on display tells that n was greater than 9
      //so display can't handle it

      SEVEN_SEGMENT_PORT=0b11111101;
   }
}


void Wait()
{
// An approx one second delay for  14.745600 Mhz CPU clock 
   uint8_t i;
   for(i=0;i<59;i++)
   {
      _delay_loop_2(0);
   }
}


void main()
{
   //Setup
   SEVEN_SEGMENT_DDR=0xFF;    //All output
   SEVEN_SEGMENT_PORT=0xFF;   //All segments off

   uint8_t count=0;

   while(1)
   {
      SevenSegment(count,0);

      count++;
      if(count==10)
      {
         count=0;
      }

      Wait();
   }
}