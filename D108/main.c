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
#include "MCAL/EXTI/exti.h"
#include "MCAL/GIE/gie.h"
#include "MCAL/ADC/adc.h"
#include "MCAL/TIMER0/timer0.h"
#include "MCAL/USART/usart.h"
#include "MCAL/SPI/spi.h"
#include "MCAL/TWI/twi.h"
#include "MCAL/EEPROM/eeprom.h"
#include "MCAL/TIMER1/timer1.h"
#include "HAL/CLCD/CLCD_int.h"
#include "HAL/KPAD/KPAD_int.h"
#include "HAL/EEPROM_EXT/eeprom_ext.h"
#include "HAL/DCMOTOR/dcmotor.h"

int main(void)
{

	while (1)
	{

	}

	return 0;
}