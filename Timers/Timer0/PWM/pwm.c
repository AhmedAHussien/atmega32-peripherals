#include "pwm.h"
#include <stdint.h>
#include <avr/io.h>


void Timer0_PWM_Init(void)
{
	DDRB |= (1U<<3);
	OCR0 = 0x00;
	TCCR0 |= (1U<<WGM00) | (1U<<WGM01) | (1U<<COM01);
}

void Timer0_PWM_Start(void)
{
	TCCR0 &=~ (1U<<CS01);
	TCCR0 |= (1U<<CS02) | (1U<<CS00);
}

void Timer0_PWM_Stop(void)
{
	TCCR0 &=~ (1U<<CS02) | (1U<<CS01) | (1U<<CS00);
}

uint8_t Timer0_PWM_SetDutyCycle(uint8_t dutycycle)
{
	if(dutycycle <= 100)
	{
		OCR0 = dutycycle * 255 / 100;
		return SUCCESS;
	}
	else
	{
		return FAIL;
	}
}