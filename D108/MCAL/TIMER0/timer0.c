/*
 * timer0.c
 *
 * Created: 9/12/2026 8:43:10 PM
 *  Author: adham
 */ 

#include "../../service/bit_math.h"
#include "../../service/std_types.h"
#include "../regdef.h"
#include "timer0.h"

void (*TIMER0_OVF_ptr)(void)=NULL;

void TIMER0_voidInit(u8 Copy_u8Prescaler)
{
	// select pre-scaler by changing only first 3 LSB bits 
	TCCR0_REG=(TCCR0_REG & 0xF8)|(Copy_u8Prescaler & 0x07);
	// enable interrupt
	SET_BIT(TIMSK_REG,TIMSK_TOIE0);
}



void TIMER0_voidSetPreloadVal(u8 Copy_u8Val)
{
	// set pre load to TCNT0_REG
	TCNT0_REG = Copy_u8Val;
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