/*
 * dcmotor.c
 *
 * Created: 11/14/2026 1:59:02 PM
 *  Author: adham
 */ 

#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../../MCAL/regdef.h"
#include "../../MCAL/TIMER1/timer1.h"
#include "dcmotor_priv.h"
#include "dcmotor_cfg.h"
#include "dcmotor.h"

// helper to configure a GPIO pin as output
static void DCMOTOR_voidSetPinDirOut(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
		case DCMOTOR_PORTA: SET_BIT(DDRA_REG, Copy_u8Pin); break;
		case DCMOTOR_PORTB: SET_BIT(DDRB_REG, Copy_u8Pin); break;
		case DCMOTOR_PORTC: SET_BIT(DDRC_REG, Copy_u8Pin); break;
		case DCMOTOR_PORTD: SET_BIT(DDRD_REG, Copy_u8Pin); break;
	}
}



// helper to write logic HIGH (1) or LOW (0) to a GPIO pin
static void DCMOTOR_voidWritePin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val)
{
	if (Copy_u8Val == 1)
	{
		switch (Copy_u8Port)
		{
			case DCMOTOR_PORTA: SET_BIT(PORTA_REG, Copy_u8Pin); break;
			case DCMOTOR_PORTB: SET_BIT(PORTB_REG, Copy_u8Pin); break;
			case DCMOTOR_PORTC: SET_BIT(PORTC_REG, Copy_u8Pin); break;
			case DCMOTOR_PORTD: SET_BIT(PORTD_REG, Copy_u8Pin); break;
		}
	}
	else
	{
		switch (Copy_u8Port)
		{
			case DCMOTOR_PORTA: CLR_BIT(PORTA_REG, Copy_u8Pin); break;
			case DCMOTOR_PORTB: CLR_BIT(PORTB_REG, Copy_u8Pin); break;
			case DCMOTOR_PORTC: CLR_BIT(PORTC_REG, Copy_u8Pin); break;
			case DCMOTOR_PORTD: CLR_BIT(PORTD_REG, Copy_u8Pin); break;
		}
	}
}



void DCMOTOR_voidInit(void)
{
	// Configure Right Motor direction pins as outputs & start LOW
	DCMOTOR_voidSetPinDirOut(DCMOTOR_RIGHT_IN1_PORT, DCMOTOR_RIGHT_IN1_PIN);
	DCMOTOR_voidSetPinDirOut(DCMOTOR_RIGHT_IN2_PORT, DCMOTOR_RIGHT_IN2_PIN);
	DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN1_PORT, DCMOTOR_RIGHT_IN1_PIN, 0);
	DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN2_PORT, DCMOTOR_RIGHT_IN2_PIN, 0);

	// Configure Left Motor direction pins as outputs & start LOW
	DCMOTOR_voidSetPinDirOut(DCMOTOR_LEFT_IN1_PORT, DCMOTOR_LEFT_IN1_PIN);
	DCMOTOR_voidSetPinDirOut(DCMOTOR_LEFT_IN2_PORT, DCMOTOR_LEFT_IN2_PIN);
	DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN1_PORT, DCMOTOR_LEFT_IN1_PIN, 0);
	DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN2_PORT, DCMOTOR_LEFT_IN2_PIN, 0);

	// Set OC1B (PD4) and OC1A (PD5) as outputs for L293D EN1 & EN2
	SET_BIT(DDRD_REG, 4);
	SET_BIT(DDRD_REG, 5);

	// Initialize Timer1 in Fast PWM (ICR1 TOP) at 2 kHz with 0% initial duty
	TIMER1_voidInit(TIMER1_DIV_BY_8, TIMER1_FAST_PWM_ICR1);
	TIMER1_voidSetICR1Val(DCMOTOR_PWM_TOP_VAL);
	TIMER1_voidSetDutyCycleA(0);
	TIMER1_voidSetDutyCycleB(0);
}



void DCMOTOR_voidSetSpeed(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent)
{
	u8 Local_u8Channel = (Copy_u8MotorId == DCMOTOR_RIGHT)
	? DCMOTOR_RIGHT_PWM_CHANNEL
	: DCMOTOR_LEFT_PWM_CHANNEL;

	if (Local_u8Channel == DCMOTOR_PWM_OC1A)
	{
		TIMER1_voidSetDutyCycleA(Copy_u8SpeedPercent);
	}
	else if (Local_u8Channel == DCMOTOR_PWM_OC1B)
	{
		TIMER1_voidSetDutyCycleB(Copy_u8SpeedPercent);
	}
}



void DCMOTOR_voidRotateCW(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent)
{
	if (Copy_u8MotorId == DCMOTOR_RIGHT)
	{
		DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN1_PORT, DCMOTOR_RIGHT_IN1_PIN, 1);
		DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN2_PORT, DCMOTOR_RIGHT_IN2_PIN, 0);
	}
	else if (Copy_u8MotorId == DCMOTOR_LEFT)
	{
		DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN1_PORT, DCMOTOR_LEFT_IN1_PIN, 1);
		DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN2_PORT, DCMOTOR_LEFT_IN2_PIN, 0);
	}
	DCMOTOR_voidSetSpeed(Copy_u8MotorId, Copy_u8SpeedPercent);
}



void DCMOTOR_voidRotateCCW(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent)
{
	if (Copy_u8MotorId == DCMOTOR_RIGHT)
	{
		DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN1_PORT, DCMOTOR_RIGHT_IN1_PIN, 0);
		DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN2_PORT, DCMOTOR_RIGHT_IN2_PIN, 1);
	}
	else if (Copy_u8MotorId == DCMOTOR_LEFT)
	{
		DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN1_PORT, DCMOTOR_LEFT_IN1_PIN, 0);
		DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN2_PORT, DCMOTOR_LEFT_IN2_PIN, 1);
	}
	DCMOTOR_voidSetSpeed(Copy_u8MotorId, Copy_u8SpeedPercent);
}



void DCMOTOR_voidStop(u8 Copy_u8MotorId)
{
	DCMOTOR_voidSetSpeed(Copy_u8MotorId, 0);

	if (Copy_u8MotorId == DCMOTOR_RIGHT)
	{
		DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN1_PORT, DCMOTOR_RIGHT_IN1_PIN, 0);
		DCMOTOR_voidWritePin(DCMOTOR_RIGHT_IN2_PORT, DCMOTOR_RIGHT_IN2_PIN, 0);
	}
	else if (Copy_u8MotorId == DCMOTOR_LEFT)
	{
		DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN1_PORT, DCMOTOR_LEFT_IN1_PIN, 0);
		DCMOTOR_voidWritePin(DCMOTOR_LEFT_IN2_PORT, DCMOTOR_LEFT_IN2_PIN, 0);
	}
}



/* ==================== 2-Wheel Differential Drive Helpers ==================== */

void DCMOTOR_voidMoveForward(u8 Copy_u8SpeedPercent)
{
	DCMOTOR_voidRotateCW(DCMOTOR_RIGHT, Copy_u8SpeedPercent);
	DCMOTOR_voidRotateCW(DCMOTOR_LEFT, Copy_u8SpeedPercent);
}



void DCMOTOR_voidMoveBackward(u8 Copy_u8SpeedPercent)
{
	DCMOTOR_voidRotateCCW(DCMOTOR_RIGHT, Copy_u8SpeedPercent);
	DCMOTOR_voidRotateCCW(DCMOTOR_LEFT, Copy_u8SpeedPercent);
}



void DCMOTOR_voidTurnRight(u8 Copy_u8SpeedPercent)
{
	DCMOTOR_voidRotateCCW(DCMOTOR_RIGHT, Copy_u8SpeedPercent);
	DCMOTOR_voidRotateCW(DCMOTOR_LEFT, Copy_u8SpeedPercent);
}



void DCMOTOR_voidTurnLeft(u8 Copy_u8SpeedPercent)
{
	DCMOTOR_voidRotateCW(DCMOTOR_RIGHT, Copy_u8SpeedPercent);
	DCMOTOR_voidRotateCCW(DCMOTOR_LEFT, Copy_u8SpeedPercent);
}



void DCMOTOR_voidStopAll(void)
{
	DCMOTOR_voidStop(DCMOTOR_RIGHT);
	DCMOTOR_voidStop(DCMOTOR_LEFT);
}