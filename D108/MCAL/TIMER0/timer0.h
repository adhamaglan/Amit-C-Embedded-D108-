/*
 * timer0.h
 *
 * Created: 9/12/2026 8:43:00 PM
 *  Author: adham
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#define TIMER0_DISABLE			0
#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			2
#define TIMER0_DIV_BY_64		3
#define TIMER0_DIV_BY_256		4
#define TIMER0_DIV_BY_1024		5
#define TIMER0_EXT_FALLING		6
#define TIMER0_EXT_RISING		7

#define TIMER0_NORMAL			0
#define TIMER0_CTC				1
#define TIMER0_PWM				2
#define TIMER0_FAST_PWM			3


void TIMER0_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode);
void TIMER0_voidSetPreloadVal(u8 Copy_u8Val);
void TIMER0_voidSetOCRVal(u8 Copy_u8Val);
void TIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle); // takes duty cycle percentage 
void TIMER0_voidSetCallBackOCR(void (*Copy_ptrvoidCallBackFunc)(void));
void TIMER0_voidSetCallBackOVF(void (*Copy_ptrvoidCallBackFunc)(void));


#endif /* TIMER0_H_ */