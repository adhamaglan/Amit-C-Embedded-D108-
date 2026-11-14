/*
 * timer1_priv.h
 *
 * Created: 11/14/2026 12:42:45 PM
 *  Author: adham
 */ 


#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_

#define NON_PWM_DISCONNECTED            0
#define NON_PWM_TOG                     1
#define NON_PWM_CLR                     2
#define NON_PWM_SET                     3

#define FAST_PWM_DISCONNECTED           0
#define FAST_PWM_NON_INVERTED           1
#define FAST_PWM_INVERTED               2

#define PHASE_CORRECT_PWM_DISCONNECTED  0
#define PHASE_CORRECT_PWM_NON_INVERTED  1   // Clear OC1x when Up-Counting, Set OC1x when Down-Counting
#define PHASE_CORRECT_PWM_INVERTED      2   // Set OC1x when Up-Counting, Clear OC1x when Down-Counting

#endif /* TIMER1_PRIV_H_ */