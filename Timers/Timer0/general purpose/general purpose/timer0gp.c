#include "timer0gp.h"
#include <avr/io.h>


void Timer0_Init(void)
{
	TCCR0 &=~ (1U<<WGM01) | (1U<<WGM01) | (1U<<COM00) | (1U<<COM01);	//Normal mode operation
	TIMSK |= (1U<<TOIE0);	//timer 0 interrupt enable on timer overflow
}

void Timer0_Start(void)
{
	TCNT0 = -27;
	TCCR0 &=~ (1U<<CS00) | (1U<<CS01);
	TCCR0 |= (1U<<CS02);
}