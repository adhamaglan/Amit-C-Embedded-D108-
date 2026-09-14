/*
 * adc.c
 *
 * Created: 9/11/2026 7:47:56 PM
 *  Author: adham
 */ 
#include "../../service/bit_math.h"
#include "../../service/std_types.h"
#include "../regdef.h"
#include "adc.h"

void ADC_voidInit()
{
	// select AVCC
	SET_BIT(ADMUX_REG,ADMUX_REFS0);
	CLR_BIT(ADMUX_REG,ADMUX_REFS1);
	
	// select pre-scaler 128
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS0);
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS1);
	SET_BIT(ADCSRA_REG,ADCSRA_ADPS2);
	
	// enable ADC
	SET_BIT(ADCSRA_REG,ADCSRA_ADEN);
}
u16	 ADC_u16ReadValue(u8 Copy_u8Channel)
{
	u16 Local_u16Result=0;
	
	// select channel (while preserving first 3 bits)
	ADMUX_REG=(ADMUX_REG & 0xE0)|(Copy_u8Channel & 0x1F);
	
	// clear flag ADIF
	SET_BIT(ADCSRA_REG,ADCSRA_ADIF);
	
	// start conversion
	SET_BIT(ADCSRA_REG,ADCSRA_ADSC);
	
	// Wait on flag
	while(GET_BIT(ADCSRA_REG, ADCSRA_ADIF)==0);
	
	// return digital val (read ADCL first then combine with ADCH)
	Local_u16Result=ADCL_REG;
	Local_u16Result|=((u16)ADCH_REG<<8);

	return Local_u16Result;
}