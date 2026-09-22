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
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


u8 freq_arr[12];
u8 duty_arr[12];
volatile u16 rising_edge=0,rising_edge2=0,falling_edge=0,temp=0;
volatile u8 counter=0, data=0;
u16 high=0, low=0, cycle=0;
u32 freq, duty;

int main(void)
{
	CLCD_voidInit();
	CLCD_voidClearScreen();
	CLCD_voidSetCursorPos(0,0);
	CLCD_voidSendString("Freq: ");
	CLCD_voidSetCursorPos(0,1);
	CLCD_voidSendString("Duty: ");
	TCCR1A=0;
	TCCR1B=0x44;
	TIMSK=1<<5;
	sei();
	while (1)
	{
		if(data)
		{
			high=falling_edge-rising_edge;
			low=rising_edge2-falling_edge;
			cycle = high+low;
			
			freq=62500ul/(rising_edge2-rising_edge);
			sprintf(freq_arr,"%-6lu hz",freq);
			CLCD_voidSetCursorPos(7,0);
			CLCD_voidSendString(freq_arr);
			
			duty= (high*100UL)/cycle;
			sprintf(duty_arr,"%-2lu %%",duty);
			CLCD_voidSetCursorPos(7,1);
			CLCD_voidSendString(duty_arr);
			data=0;
			counter=0;
		}
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(counter==0)
	{
		temp=ICR1;
		rising_edge=temp;
		counter++;
		TCCR1B=0x04; // 0b00000100 falling edge
		TIFR = (1 << ICF1);
	}else if(counter==1)
	{
		temp=ICR1;
		falling_edge=temp;
		counter++;
		TCCR1B=0x44; //0b01000100 rising edge
		TIFR = (1 << ICF1);
	}else if(counter==2)
	{
		temp=ICR1;
		rising_edge2=temp;
		counter++;	// on hold (no new data introduced till older data gets calculated)
		data=1;
	}
}