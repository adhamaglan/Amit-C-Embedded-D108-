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
#include "HAL/CLCD/CLCD_config.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/KPAD/KPAD_config.h"
#include "HAL/KPAD/KPAD_int.h"
#include "MCAL/EXTI/exti.h"
#include "MCAL/GIE/gie.h"

void Int0 ()
{
	CLCD_voidSendString("Int0 Fired");
	_delay_ms(1000);
	CLCD_voidClearScreen();
}

void Int1 ()
{
	CLCD_voidSendString("Int1 Fired");
	_delay_ms(1000);
	CLCD_voidClearScreen();
}

void Int2 ()
{
	CLCD_voidSendString("Int2 Fired");
	_delay_ms(1000);
	CLCD_voidClearScreen();
}


int main(void)
{
	CLCD_voidInit();
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);
	DIO_voidEnablePullUp(DIO_PORTD,DIO_PIN2);
	DIO_voidEnablePullUp(DIO_PORTD,DIO_PIN3);
	DIO_voidEnablePullUp(DIO_PORTB,DIO_PIN2);
	EXTI_voidEnableInt(EXTI_INT0);
	EXTI_voidEnableInt(EXTI_INT1);
	EXTI_voidEnableInt(EXTI_INT2);
	EXTI_INT0_CallBack(Int0);
	EXTI_INT1_CallBack(Int1);
	EXTI_INT2_CallBack(Int2);
	EXTI_voidSetSenseControl(EXTI_INT0,EXTI_FALLING);
	EXTI_voidSetSenseControl(EXTI_INT1,EXTI_FALLING);
	EXTI_voidSetSenseControl(EXTI_INT2,EXTI_FALLING);
	GIE_voidEnableGlobalInterrupt();
	
	while (1)
	{

	}
	
	
}
