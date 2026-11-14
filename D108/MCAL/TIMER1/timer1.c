/*
 * timer1.c
 *
 * Created: 11/14/2026 12:41:20 PM
 *  Author: adham
 */ 

#include "../../service/bit_math.h"
#include "../../service/std_types.h"
#include "../regdef.h"
#include "timer1_priv.h"
#include "timer1_cfg.h"
#include "timer1.h"

static u8 Global_u8Timer1Mode = TIMER1_NORMAL;

void (*TIMER1_OVF_ptr)(void)   = NULL;
void (*TIMER1_COMPA_ptr)(void) = NULL;
void (*TIMER1_COMPB_ptr)(void) = NULL;
void (*TIMER1_ICU_ptr)(void)   = NULL;



// Helper to apply Compare Output Mode bits for Non-PWM, Fast PWM, and Phase Correct PWM
static void TIMER1_voidConfigComparePins(u8 Copy_u8IsPwm, u8 Copy_u8IsFastPwm)
{
	if (Copy_u8IsPwm == 0)
	{
		// Channel A Non-PWM
		#if TIMER1_CH_A_NON_PWM_MODE == NON_PWM_DISCONNECTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_NON_PWM_MODE == NON_PWM_TOG
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_NON_PWM_MODE == NON_PWM_CLR
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_NON_PWM_MODE == NON_PWM_SET
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#endif

		// Channel B Non-PWM
		#if TIMER1_CH_B_NON_PWM_MODE == NON_PWM_DISCONNECTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_NON_PWM_MODE == NON_PWM_TOG
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_NON_PWM_MODE == NON_PWM_CLR
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_NON_PWM_MODE == NON_PWM_SET
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#endif
	}
	else if (Copy_u8IsFastPwm == 1)
	{
		// Channel A Fast PWM
		#if TIMER1_CH_A_FAST_PWM_MODE == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_FAST_PWM_MODE == FAST_PWM_NON_INVERTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_FAST_PWM_MODE == FAST_PWM_INVERTED
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#endif

		// Channel B Fast PWM
		#if TIMER1_CH_B_FAST_PWM_MODE == FAST_PWM_DISCONNECTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_FAST_PWM_MODE == FAST_PWM_NON_INVERTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_FAST_PWM_MODE == FAST_PWM_INVERTED
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#endif
	}
	else
	{
		// Channel A Phase Correct PWM
		#if TIMER1_CH_A_PHASE_CORRECT_MODE == PHASE_CORRECT_PWM_DISCONNECTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_PHASE_CORRECT_MODE == PHASE_CORRECT_PWM_NON_INVERTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#elif TIMER1_CH_A_PHASE_CORRECT_MODE == PHASE_CORRECT_PWM_INVERTED
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1A1);
		#endif

		// Channel B Phase Correct PWM
		#if TIMER1_CH_B_PHASE_CORRECT_MODE == PHASE_CORRECT_PWM_DISCONNECTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_PHASE_CORRECT_MODE == PHASE_CORRECT_PWM_NON_INVERTED
		CLR_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#elif TIMER1_CH_B_PHASE_CORRECT_MODE == PHASE_CORRECT_PWM_INVERTED
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B0);
		SET_BIT(TCCR1A_REG, TCCR1A_COM1B1);
		#endif
	}
}



void TIMER1_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode)
{
	Global_u8Timer1Mode = Copy_u8Mode;

	switch (Copy_u8Mode)
	{
		case TIMER1_NORMAL:
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM11);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(0, 0);
		SET_BIT(TIMSK_REG, TIMSK_TOIE1);
		break;

		case TIMER1_PWM_PHASE_CORRECT_8BIT:
		SET_BIT(TCCR1A_REG, TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM11);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(1, 0);
		break;

		case TIMER1_PWM_PHASE_CORRECT_10BIT:
		SET_BIT(TCCR1A_REG, TCCR1A_WGM10);
		SET_BIT(TCCR1A_REG, TCCR1A_WGM11);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(1, 0);
		break;

		case TIMER1_CTC_OCR1A:
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(0, 0);
		SET_BIT(TIMSK_REG, TIMSK_OCIE1A);
		break;

		case TIMER1_FAST_PWM_8BIT:
		SET_BIT(TCCR1A_REG, TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(1, 1);
		break;

		case TIMER1_FAST_PWM_10BIT:
		SET_BIT(TCCR1A_REG, TCCR1A_WGM10);
		SET_BIT(TCCR1A_REG, TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM12);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(1, 1);
		break;

		case TIMER1_PWM_PHASE_CORRECT_ICR1:
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM10);
		SET_BIT(TCCR1A_REG, TCCR1A_WGM11);
		CLR_BIT(TCCR1B_REG, TCCR1B_WGM12);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(1, 0);
		break;

		case TIMER1_CTC_ICR1:
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM10);
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM12);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(0, 0);
		SET_BIT(TIMSK_REG, TIMSK_TICIE1);
		break;

		case TIMER1_FAST_PWM_ICR1:
		CLR_BIT(TCCR1A_REG, TCCR1A_WGM10);
		SET_BIT(TCCR1A_REG, TCCR1A_WGM11);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM12);
		SET_BIT(TCCR1B_REG, TCCR1B_WGM13);
		TIMER1_voidConfigComparePins(1, 1);
		break;
	}

	// Select prescaler by modifying only the 3 LSB bits
	TCCR1B_REG = (TCCR1B_REG & 0xF8) | (Copy_u8Prescaler & 0x07);
}



void TIMER1_voidSetPreloadVal(u16 Copy_u16Val)
{
	TCNT1_REG = Copy_u16Val;
}



u16 TIMER1_u16GetTimerVal(void)
{
	return TCNT1_REG;
}



void TIMER1_voidSetOCR1AVal(u16 Copy_u16Val)
{
	OCR1A_REG = Copy_u16Val;
}



void TIMER1_voidSetOCR1BVal(u16 Copy_u16Val)
{
	OCR1B_REG = Copy_u16Val;
}



void TIMER1_voidSetICR1Val(u16 Copy_u16Val)
{
	ICR1_REG = Copy_u16Val;
}



void TIMER1_voidSetDutyCycleA(u8 Copy_u8DutyCycle)
{
	u16 Local_u16TopVal = 65535;

	if (Copy_u8DutyCycle <= 100)
	{
		if (Global_u8Timer1Mode == TIMER1_FAST_PWM_ICR1 || Global_u8Timer1Mode == TIMER1_PWM_PHASE_CORRECT_ICR1)
		{
			Local_u16TopVal = ICR1_REG;
		}
		else if (Global_u8Timer1Mode == TIMER1_FAST_PWM_8BIT || Global_u8Timer1Mode == TIMER1_PWM_PHASE_CORRECT_8BIT)
		{
			Local_u16TopVal = 255;
		}
		else if (Global_u8Timer1Mode == TIMER1_FAST_PWM_10BIT || Global_u8Timer1Mode == TIMER1_PWM_PHASE_CORRECT_10BIT)
		{
			Local_u16TopVal = 1023;
		}

		OCR1A_REG = (u16)(((u32)Copy_u8DutyCycle * Local_u16TopVal) / 100);
	}
}



void TIMER1_voidSetDutyCycleB(u8 Copy_u8DutyCycle)
{
	u16 Local_u16TopVal = 65535;

	if (Copy_u8DutyCycle <= 100)
	{
		if (Global_u8Timer1Mode == TIMER1_FAST_PWM_ICR1 || Global_u8Timer1Mode == TIMER1_PWM_PHASE_CORRECT_ICR1)
		{
			Local_u16TopVal = ICR1_REG;
		}
		else if (Global_u8Timer1Mode == TIMER1_FAST_PWM_8BIT || Global_u8Timer1Mode == TIMER1_PWM_PHASE_CORRECT_8BIT)
		{
			Local_u16TopVal = 255;
		}
		else if (Global_u8Timer1Mode == TIMER1_FAST_PWM_10BIT || Global_u8Timer1Mode == TIMER1_PWM_PHASE_CORRECT_10BIT)
		{
			Local_u16TopVal = 1023;
		}

		OCR1B_REG = (u16)(((u32)Copy_u8DutyCycle * Local_u16TopVal) / 100);
	}
}



/* ==================== Input Capture Unit (ICU) ==================== */

void TIMER1_voidICUInit(u8 Copy_u8Edge)
{
	TIMER1_voidICUSetEdge(Copy_u8Edge);
	SET_BIT(TIMSK_REG, TIMSK_TICIE1);
}



void TIMER1_voidICUSetEdge(u8 Copy_u8Edge)
{
	if (Copy_u8Edge == TIMER1_ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B_REG, TCCR1B_ICES1);
	}
	else
	{
		CLR_BIT(TCCR1B_REG, TCCR1B_ICES1);
	}
	// Clear ICF1 flag (write 1 to clear) to prevent false edge triggers
	SET_BIT(TIFR_REG, TIFR_ICF1);
}



u16 TIMER1_u16GetICR1Val(void)
{
	return ICR1_REG;
}



void TIMER1_voidICUEnableInterrupt(void)
{
	SET_BIT(TIMSK_REG, TIMSK_TICIE1);
}



void TIMER1_voidICUDisableInterrupt(void)
{
	CLR_BIT(TIMSK_REG, TIMSK_TICIE1);
}



/* ==================== Interrupt Service Routines ==================== */

void TIMER1_voidSetCallBackICU(void (*Copy_ptrvoidCallBackFunc)(void))
{
	TIMER1_ICU_ptr = Copy_ptrvoidCallBackFunc;
}
void __vector_6() __attribute__((signal));
void __vector_6()
{
	if (TIMER1_ICU_ptr != NULL)
	{
		TIMER1_ICU_ptr();
	}
}



void TIMER1_voidSetCallBackCOMPA(void (*Copy_ptrvoidCallBackFunc)(void))
{
	TIMER1_COMPA_ptr = Copy_ptrvoidCallBackFunc;
}
void __vector_7() __attribute__((signal));
void __vector_7()
{
	if (TIMER1_COMPA_ptr != NULL)
	{
		TIMER1_COMPA_ptr();
	}
}



void TIMER1_voidSetCallBackCOMPB(void (*Copy_ptrvoidCallBackFunc)(void))
{
	TIMER1_COMPB_ptr = Copy_ptrvoidCallBackFunc;
}
void __vector_8() __attribute__((signal));
void __vector_8()
{
	if (TIMER1_COMPB_ptr != NULL)
	{
		TIMER1_COMPB_ptr();
	}
}



void TIMER1_voidSetCallBackOVF(void (*Copy_ptrvoidCallBackFunc)(void))
{
	TIMER1_OVF_ptr = Copy_ptrvoidCallBackFunc;
}
void __vector_9() __attribute__((signal));
void __vector_9()
{
	if (TIMER1_OVF_ptr != NULL)
	{
		TIMER1_OVF_ptr();
	}
}