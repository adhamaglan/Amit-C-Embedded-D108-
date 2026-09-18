/*
 * D108.c
 *
 * Created: 8/15/2026 6:57:42 PM
 * Author : adham
 */ 
#define F_CPU 16000000ul

#include <util/delay.h>
#include "service/std_types.h"
#include "service/bit_math.h"
#include "MCAL/regdef.h"
#include "MCAL/DIO/dio.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/KPAD/KPAD_int.h"
#include "MCAL/EXTI/exti.h"
#include "MCAL/GIE/gie.h"
#include "MCAL/ADC/adc.h"
#include "MCAL/TIMER0/timer0.h"

//	blinking led every 1 second
void TogPin()
{
	static u8 counter=0;
	counter++;
	if(counter==125){
		DIO_voidTogPinVal(DIO_PORTB,DIO_PIN4);
		counter=0;
	}
}

int main(void)
{
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	TIMER0_voidInit(TIMER0_DIV_BY_1024,TIMER0_CTC);
	TIMER0_voidSetOCRVal(124);
	GIE_voidEnableGlobalInterrupt();
	TIMER0_voidSetCallBackOCR(TogPin);
	while (1)
	{
		
	}
}