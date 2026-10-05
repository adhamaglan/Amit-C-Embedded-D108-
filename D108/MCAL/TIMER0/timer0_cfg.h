/*
 * timer0_config.h
 *
 * Created: 9/19/2026 7:43:17 PM
 *  Author: adham
 */ 


#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_



#define NON_PWM_MODE					NON_PWM_TOG
/*
	options:
	NON_PWM_TOG
	NON_PWM_CLR
	NON_PWM_SET
*/
#define FAST_PWM_MODE					FAST_PWM_NON_INVERTED
/*
	options:
	FAST_PWM_NON_INVERTED
	FAST_PWM_INVERTED
*/
#define PHASE_CORRECT_FAST_PWM_MODE		PHASE_CORRECT_PWM_NON_INVERTED
/*
	options:
	PHASE_CORRECT_PWM_NON_INVERTED	0	(Clear OC0 when Up-Counting, Set OC0 when Down-Counting)
	PHASE_CORRECT_PWM_INVERTED
*/



#endif /* TIMER0_CFG_H_ */