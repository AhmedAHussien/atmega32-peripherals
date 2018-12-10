#ifndef _TIMER0GP_H_
#define _TIMER0GP_H_

/*
 * Initializes timer0
 * Input parameters : none
 * Returns : none
 */
void Timer0_Init(void);


/*
 * Starts timer0 at TCNT0 = -27
 * Input parameters : none
 * Returns : none
 */
void Timer0_Start(void);


#endif