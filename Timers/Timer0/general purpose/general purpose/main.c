/*
 * general purpose.c
 *
 * Created: 10-Dec-18 10:10:07 PM
 * Author : aidsg
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "timer0gp.h"

volatile uint8_t counter = 0;

int main(void)
{
	Timer0_Init();
	DDRD |= (1U<<7) | (1U<<6) | (1U<<5);
	sei();
	Timer0_Start();
    while (1) 
    {
		if(counter == 184)
		{
			TCNT0 = -27;
			counter = 0;
			PORTD ^= (1U<<7) | (1U<<6) | (1U<<5);
		}
		else
		{
			;	//do nothing
		}
    }
}


ISR(TIMER0_OVF_vect)
{
	counter++;
}
