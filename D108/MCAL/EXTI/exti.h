/*
 * exti_int.h
 *
 * Created: 9/5/2026 6:02:47 PM
 *  Author: adham
 */ 


#ifndef EXTI_INT_H_
#define EXTI_INT_H_



#define EXTI_INT0	0
#define EXTI_INT1	1
#define EXTI_INT2	2

#define EXTI_LOW			0
#define EXTI_ANY_CHANGE		1
#define EXTI_FALLING		2
#define EXTI_RISING			3

void EXTI_voidEnableInt(u8 Copy_u8Int);
void EXTI_voidDisableInt(u8 Copy_u8Int);
void EXTI_voidSetSenseControl(u8 Copy_u8Int,u8 Copy_u8SC);

void EXTI_INT0_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
void EXTI_INT1_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
void EXTI_INT2_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));



#endif /* EXTI_INT_H_ */