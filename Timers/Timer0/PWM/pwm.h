#ifndef _PWM_H_
#define _PWM_H_

#include <stdint.h>

#define SUCCESS		(1)
#define FAIL		(0)

/*
 * Initializes PWM
 * Arguments: none
 * Returns: none
 */
void Timer0_PWM_Init(void);

/*
 * Starts PWM
 * Arguments: none
 * Returns: none
 */
void Timer0_PWM_Start(void);

/*
 * Stops PWM
 * Arguments: none
 * Returns: none
 */
void Timer0_PWM_Stop(void);


/*
 * Sets PWM duty cycle
 * Arguments: uint8_t dutycycle - duty cycle for the PWM ranges from 0 to 100
 * Returns: SUCCESS - when duty cycle is set successfully
			FAIL - when input parameters are incorrect
 */
uint8_t Timer0_PWM_SetDutyCycle(uint8_t dutycyle);


#endif