#include "adc.h"
#include <stdint.h>
#include <avr/io.h>

void ADC_Init(void)
{
	
	ADMUX |= (0x1U << REFS0);	//AVCC with external capacitor at AREF pin
	ADMUX |= (0U << ADLAR);		//ADC Data Register is right adjusted
	ADMUX |= (0x0U << MUX0);	//Single ended input, channel: ADC0
	
	ADCSRA |= (1U << ADEN);		//Enables ADC module
	//ADCSRA |= (1U << ADATE);	//Auto trigger mode: ON
	ADCSRA |= (1U << ADIE);		//ADC interrupt: ON
	ADCSRA |= (0x6 << ADPS0);	//Division factor: 64, ADC clock = 12MHz/64 = 187.5KHz
}

void ADC_StartConversion(void)
{
	ADCSRA |= (1U<<ADSC);
}