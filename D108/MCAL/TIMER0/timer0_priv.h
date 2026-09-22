/*
 * timer0_priv.h
 *
 * Created: 9/19/2026 8:21:50 PM
 *  Author: adham
 */ 


#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_



#define NON_PWM_TOG						0
#define NON_PWM_CLR						1
#define NON_PWM_SET						2

#define FAST_PWM_NON_INVERTED			0
#define FAST_PWM_INVERTED				1

#define PHASE_CORRECT_PWM_NON_INVERTED	0	//	Clear OC0 when Up-Counting, Set OC0 when Down-Counting
#define PHASE_CORRECT_PWM_INVERTED		1	//	Set OC0 when Up-Counting, Clear OC0 when Down-Counting



#endif /* TIMER0_PRIV_H_ */