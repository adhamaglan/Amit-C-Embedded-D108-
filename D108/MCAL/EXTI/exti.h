/*
 * exti_int.h
 *
 * Created: 9/5/2026 6:02:47 PM
 *  Author: adham
 */ 


#ifndef EXTI_INT_H_
#define EXTI_INT_H_



#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

#define MCUCSR_ISC2	6

#define GICR_INT2   5
#define GICR_INT0   6
#define GICR_INT1   7

#define GIFR_INTF2  5
#define GIFR_INTF0  6
#define GIFR_INTF1  7

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

void EXTI_INT0_CallBack(void(*fun)(void));
void EXTI_INT1_CallBack(void(*fun)(void));
void EXTI_INT2_CallBack(void(*fun)(void));



#endif /* EXTI_INT_H_ */