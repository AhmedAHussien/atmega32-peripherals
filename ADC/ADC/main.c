/*
 * ADC.c
 *
 * Created: 09-Dec-18 10:54:33 PM
 * Author : Ahmed
 */ 
#define F_CPU 12000000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "adc.h"
#include <util/delay.h>

volatile uint16_t g_adc_data = 0;

int main(void)
{
	LCD_Init();
	ADC_Init();
	
	DDRD = 0xFF;
	sei();
    while (1) 
    {
		ADC_StartConversion();

		while((ADCSRA & (1U<<ADSC)) == (1U<<ADSC));
		g_adc_data = (ADCL | (uint16_t)(ADCH << 8));
		
		if(g_adc_data < 341)
		{
			PORTD = (1U<<7);
		}
		else if((g_adc_data >= 341) && (g_adc_data < 682))
		{
			PORTD = (1U<<7) | (1U<<6);
		}
		else
		{
			PORTD = (1U<<7) | (1U<<6) | (1U<<5);
		}
		LCD_WriteNewLine("ADC result");
		LCD_GoTo(0,1);
		LCD_WriteChar((g_adc_data / 1000) + 0x30);
		LCD_WriteChar((g_adc_data / 100) % 10);
		LCD_WriteChar((g_adc_data / 10) % 10);
		LCD_WriteChar((g_adc_data % 10));
		_delay_ms(550);	


    }
}

ISR(ADC_vect)
{
	g_adc_data = ((uint16_t)(ADCH << 8) | ADCL);
}
