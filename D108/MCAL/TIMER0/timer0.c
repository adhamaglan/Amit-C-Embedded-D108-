/*
 * timer0.c
 *
 * Created: 9/12/2026 8:43:10 PM
 *  Author: adham
 */ 

#include "../../service/bit_math.h"
#include "../../service/std_types.h"
#include "../regdef.h"
#include "timer0_priv.h"
#include "timer0_cfg.h"
#include "timer0.h"

void (*TIMER0_OVF_ptr)(void)=NULL;
void (*TIMER0_OCR_ptr)(void)=NULL;

void TIMER0_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode)
{
	// select pre-scaler by changing only first 3 LSB bits 
	TCCR0_REG=(TCCR0_REG & 0xF8)|(Copy_u8Prescaler & 0x07);
	switch(Copy_u8Mode)
	{
		case TIMER0_NORMAL :
		CLR_BIT(TCCR0_REG,TCCR0_WGM00);
		CLR_BIT(TCCR0_REG,TCCR0_WGM01);
		// enable Timer0 OVF interrupt
		SET_BIT(TIMSK_REG,TIMSK_TOIE0);
		break;
		case TIMER0_PWM :
		SET_BIT(TCCR0_REG,TCCR0_WGM00);
		CLR_BIT(TCCR0_REG,TCCR0_WGM01);
		#if	PHASE_CORRECT_FAST_PWM_MODE == PHASE_CORRECT_PWM_NON_INVERTED
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		#elif PHASE_CORRECT_FAST_PWM_MODE == PHASE_CORRECT_PWM_INVERTED
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		#endif
		break;
		case TIMER0_CTC :
		CLR_BIT(TCCR0_REG,TCCR0_WGM00);
		SET_BIT(TCCR0_REG,TCCR0_WGM01);
		#if NON_PWM_MODE == NON_PWM_TOG
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		CLR_BIT(TCCR0_REG,TCCR0_COM01);
		#elif NON_PWM_MODE == NON_PWM_CLR
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		#elif NON_PWM_MODE == NON_PWM_SET
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		#endif
		// enable Timer0 OCR interrupt
		SET_BIT(TIMSK_REG,TIMSK_OCIE0);
		break;
		case TIMER0_FAST_PWM :
		SET_BIT(TCCR0_REG,TCCR0_WGM00);
		SET_BIT(TCCR0_REG,TCCR0_WGM01);
		#if FAST_PWM_MODE == FAST_PWM_NON_INVERTED
		CLR_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		#elif FAST_PWM_MODE == FAST_PWM_INVERTED
		SET_BIT(TCCR0_REG,TCCR0_COM00);
		SET_BIT(TCCR0_REG,TCCR0_COM01);
		#endif
		break;
	}
}



void TIMER0_voidSetPreloadVal(u8 Copy_u8Val)
{
	// set pre-load to TCNT0_REG
	TCNT0_REG = Copy_u8Val;
}



void TIMER0_voidSetOCRVal(u8 Copy_u8Val)
{
	// set value to OCR0_REG
	OCR0_REG = Copy_u8Val;
}



void TIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle)
{
	if(Copy_u8DutyCycle>=0 && Copy_u8DutyCycle<=100)
	{
		// multiplying 256 by duty cycle percentage and set value to OCR0_REG
		OCR0_REG = (u8)(((u16)Copy_u8DutyCycle*255)/100);
	}
}



void TIMER0_voidSetCallBackOVF(void(*Copy_ptrvoidCallBackFunc)(void))
{
	TIMER0_OVF_ptr=Copy_ptrvoidCallBackFunc;
}
void __vector_11() __attribute__((signal));
void __vector_11()
{
	if(TIMER0_OVF_ptr!=NULL)
	{
		TIMER0_OVF_ptr();
	}
}



void TIMER0_voidSetCallBackOCR(void (*Copy_ptrvoidCallBackFunc)(void))
{
	TIMER0_OCR_ptr=Copy_ptrvoidCallBackFunc;
}
void __vector_10() __attribute__((signal));
void __vector_10()
{
	if(TIMER0_OCR_ptr!=NULL)
	{
		TIMER0_OCR_ptr();
	}
}