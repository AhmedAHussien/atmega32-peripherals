/*
 * PWM.c
 *
 * Created: 11-Dec-18 3:18:46 AM
 * Author : aidsg
 */ 

#define F_CPU 12000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "pwm.h"



int main(void)
{
	uint8_t counter = 0;
	uint8_t countup_flag = 1;
	Timer0_PWM_Init();
	Timer0_PWM_SetDutyCycle(0);
	Timer0_PWM_Start();
    while (1) 
    {
		if(countup_flag == 1)
		{
			counter ++;
			Timer0_PWM_SetDutyCycle(counter);
			if(counter == 100)
			{
				countup_flag = 0;
			}
			else
			{
				;
			}
		}
		else
		{
			counter --;
			Timer0_PWM_SetDutyCycle(counter);
			if(counter == 0)
			{
				countup_flag = 1;
			}
			else
			{
				;
			}
		}
		_delay_ms(100);
		
    }
}

