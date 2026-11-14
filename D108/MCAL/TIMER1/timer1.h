/*
 * timer1.h
 *
 * Created: 11/14/2026 12:42:19 PM
 *  Author: adham
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

// Clock Pre-scaler Options (CS12:0)
#define TIMER1_DISABLE                  0
#define TIMER1_DIV_BY_1                 1
#define TIMER1_DIV_BY_8                 2
#define TIMER1_DIV_BY_64                3
#define TIMER1_DIV_BY_256               4
#define TIMER1_DIV_BY_1024              5
#define TIMER1_EXT_FALLING              6
#define TIMER1_EXT_RISING               7

// Waveform Generation Modes
#define TIMER1_NORMAL                   0   // TOP = 0xFFFF
#define TIMER1_PWM_PHASE_CORRECT_8BIT   1   // TOP = 0x00FF
#define TIMER1_PWM_PHASE_CORRECT_10BIT  2   // TOP = 0x03FF
#define TIMER1_CTC_OCR1A                3   // TOP = OCR1A
#define TIMER1_FAST_PWM_8BIT            4   // TOP = 0x00FF
#define TIMER1_FAST_PWM_10BIT           5   // TOP = 0x03FF
#define TIMER1_PWM_PHASE_CORRECT_ICR1   6   // TOP = ICR1
#define TIMER1_CTC_ICR1                 7   // TOP = ICR1
#define TIMER1_FAST_PWM_ICR1            8   // TOP = ICR1

// Input Capture Unit (ICU) Edge Options
#define TIMER1_ICU_FALLING_EDGE         0
#define TIMER1_ICU_RISING_EDGE          1

// Initialization & Counter Control
void TIMER1_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode);
void TIMER1_voidSetPreloadVal(u16 Copy_u16Val);
u16  TIMER1_u16GetTimerVal(void);

// Compare & TOP Register Setters
void TIMER1_voidSetOCR1AVal(u16 Copy_u16Val);
void TIMER1_voidSetOCR1BVal(u16 Copy_u16Val);
void TIMER1_voidSetICR1Val(u16 Copy_u16Val);

// PWM Duty Cycle Helpers (0 - 100%)
void TIMER1_voidSetDutyCycleA(u8 Copy_u8DutyCycle);
void TIMER1_voidSetDutyCycleB(u8 Copy_u8DutyCycle);

// Input Capture Unit (ICU) APIs
void TIMER1_voidICUInit(u8 Copy_u8Edge);
void TIMER1_voidICUSetEdge(u8 Copy_u8Edge);
u16  TIMER1_u16GetICR1Val(void);
void TIMER1_voidICUEnableInterrupt(void);
void TIMER1_voidICUDisableInterrupt(void);

// Interrupt Callbacks
void TIMER1_voidSetCallBackOVF(void (*Copy_ptrvoidCallBackFunc)(void));
void TIMER1_voidSetCallBackCOMPA(void (*Copy_ptrvoidCallBackFunc)(void));
void TIMER1_voidSetCallBackCOMPB(void (*Copy_ptrvoidCallBackFunc)(void));
void TIMER1_voidSetCallBackICU(void (*Copy_ptrvoidCallBackFunc)(void));

#endif /* TIMER1_H_ */