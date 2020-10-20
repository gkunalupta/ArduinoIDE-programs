#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
//#include "uarts.h"
#include<stdlib.h>
#include<SoftwareSerial.h>
uint32_t a,b,c,bx,cx;                 //range 0-65535 


static inline void initTimer1_328p(void) 
{
  /* Set up Timer1 (16bit) to give a pulse every 20ms */
  /* Use Fast PWM mode, counter max in ICR1 */
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);
  TCCR1B |= (1 << CS11);  /* /1 prescaling -- counting in microseconds */
  ICR1 = 40000;                                    /* TOP value = 20ms */
  TCCR1A |= (1 << COM1A1)|(1<<COM1B1);              /* Direct output on PB1 / OC1A */
  DDRB |= (1 << PB2)|(1<<PB1);                            /* set pin for output */
  //OCR1B=2000;   //pb2-10
  OCR1A=4000;    //pb1-9
}
void setup()
{
  Serial.begin(9600);
  initTimer1_328p();
  Serial.println("dfks");
}
void loop()
{
}
