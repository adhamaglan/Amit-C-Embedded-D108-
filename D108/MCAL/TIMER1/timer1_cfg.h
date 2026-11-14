/*
 * timer1_cfg.h
 *
 * Created: 11/14/2026 12:42:32 PM
 *  Author: adham
 */ 

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_



// Channel A (OC1A - PD5) Compare Output Options
#define TIMER1_CH_A_NON_PWM_MODE            NON_PWM_DISCONNECTED
/*
    options:
    NON_PWM_DISCONNECTED
    NON_PWM_TOG
    NON_PWM_CLR
    NON_PWM_SET
*/

#define TIMER1_CH_A_FAST_PWM_MODE           FAST_PWM_NON_INVERTED
/*
    options:
    FAST_PWM_DISCONNECTED
    FAST_PWM_NON_INVERTED
    FAST_PWM_INVERTED
*/

#define TIMER1_CH_A_PHASE_CORRECT_MODE      PHASE_CORRECT_PWM_NON_INVERTED
/*
    options:
    PHASE_CORRECT_PWM_DISCONNECTED
    PHASE_CORRECT_PWM_NON_INVERTED
    PHASE_CORRECT_PWM_INVERTED
*/


//------------------------------------------------------------------------------//


// Channel B (OC1B - PD4) Compare Output Options
#define TIMER1_CH_B_NON_PWM_MODE            NON_PWM_DISCONNECTED
/*
    options:
    NON_PWM_DISCONNECTED
    NON_PWM_TOG
    NON_PWM_CLR
    NON_PWM_SET
*/

#define TIMER1_CH_B_FAST_PWM_MODE           FAST_PWM_NON_INVERTED
/*
    options:
    FAST_PWM_DISCONNECTED
    FAST_PWM_NON_INVERTED
    FAST_PWM_INVERTED
*/

#define TIMER1_CH_B_PHASE_CORRECT_MODE      PHASE_CORRECT_PWM_NON_INVERTED
/*
    options:
    PHASE_CORRECT_PWM_DISCONNECTED
    PHASE_CORRECT_PWM_NON_INVERTED
    PHASE_CORRECT_PWM_INVERTED
*/



#endif /* TIMER1_CFG_H_ */