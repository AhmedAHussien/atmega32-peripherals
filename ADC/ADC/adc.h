#ifndef _ADC_H
#define _ADC_H

/*
 * Initializes ADC
 * Input parameters : none
 * Returns : none
 */

void ADC_Init(void);



/*
 * Starts conversion when not in auto trigger mode
 * Input parameters : none
 * Returns : none
 */

void ADC_StartConversion(void);


#endif