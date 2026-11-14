/*
 * dcmotor_cfg.h
 *
 * Created: 11/14/2026 1:59:35 PM
 *  Author: adham
 */ 


#ifndef DCMOTOR_CFG_H_
#define DCMOTOR_CFG_H_

/* ==================== Right Motor Configuration (EN 1 -> PD4 / OC1B) ==================== */
#define DCMOTOR_RIGHT_IN1_PORT      DCMOTOR_PORTB
#define DCMOTOR_RIGHT_IN1_PIN       4

#define DCMOTOR_RIGHT_IN2_PORT      DCMOTOR_PORTB
#define DCMOTOR_RIGHT_IN2_PIN       5

#define DCMOTOR_RIGHT_PWM_CHANNEL   DCMOTOR_PWM_OC1B

/* ==================== Left Motor Configuration (EN 2 -> PD5 / OC1A) ===================== */
#define DCMOTOR_LEFT_IN1_PORT       DCMOTOR_PORTB
#define DCMOTOR_LEFT_IN1_PIN        6

#define DCMOTOR_LEFT_IN2_PORT       DCMOTOR_PORTB
#define DCMOTOR_LEFT_IN2_PIN        7

#define DCMOTOR_LEFT_PWM_CHANNEL    DCMOTOR_PWM_OC1A

// PWM Frequency = 16 MHz / (8 * (999 + 1)) = 2 kHz
#define DCMOTOR_PWM_TOP_VAL         999

#endif /* DCMOTOR_CFG_H_ */