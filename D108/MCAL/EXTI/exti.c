/*
 * exti.c
 *
 * Created: 9/5/2026 6:03:13 PM
 *  Author: adham
 */ 


#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../regdef.h"
#include "exti.h"

void (*INT0_ptr)(void)=NULL;
void (*INT1_ptr)(void)=NULL;
void (*INT2_ptr)(void)=NULL;

void EXTI_voidEnableInt(u8 Copy_u8Int)
{
	if (Copy_u8Int <= EXTI_INT2)
	{
		switch (Copy_u8Int)
		{
			case EXTI_INT0: SET_BIT(GICR_REG, GICR_INT0); break;
			case EXTI_INT1: SET_BIT(GICR_REG, GICR_INT1); break;
			case EXTI_INT2: SET_BIT(GICR_REG, GICR_INT2); break;
			default: break; // error Invalid IntID
		}
	}
	else
	{
		// error Invalid IntID
	}
}



void EXTI_voidDisableInt(u8 Copy_u8Int)
{
	if (Copy_u8Int <= EXTI_INT2)
	{
		switch (Copy_u8Int)
		{
			case EXTI_INT0: CLR_BIT(GICR_REG, GICR_INT0); break;
			case EXTI_INT1: CLR_BIT(GICR_REG, GICR_INT1); break;
			case EXTI_INT2: CLR_BIT(GICR_REG, GICR_INT2); break;
			default: break; // error Invalid IntID
		}
	}
	else
	{
		// error Invalid IntID
	}
}



void EXTI_voidSetSenseControl(u8 Copy_u8Int,u8 Copy_u8SC)
{
	if ((Copy_u8Int <= EXTI_INT2)&&(Copy_u8SC <= EXTI_RISING))
	{
		switch (Copy_u8Int)
		{
			case EXTI_INT0:
			{
				switch (Copy_u8SC)
				{
					case EXTI_LOW:
						CLR_BIT(MCUCR_REG,MCUCR_ISC00);
						CLR_BIT(MCUCR_REG,MCUCR_ISC01);
						break;
					case EXTI_ANY_CHANGE:
						SET_BIT(MCUCR_REG,MCUCR_ISC00);
						CLR_BIT(MCUCR_REG,MCUCR_ISC01);
						break;
					case EXTI_FALLING:
						CLR_BIT(MCUCR_REG,MCUCR_ISC00);
						SET_BIT(MCUCR_REG,MCUCR_ISC01);
						break;
					case EXTI_RISING:
						SET_BIT(MCUCR_REG,MCUCR_ISC00);
						SET_BIT(MCUCR_REG,MCUCR_ISC01);
						break;
				}
			break;
			}
			case EXTI_INT1:
				switch (Copy_u8SC)
				{
					case EXTI_LOW:
						CLR_BIT(MCUCR_REG,MCUCR_ISC10);
						CLR_BIT(MCUCR_REG,MCUCR_ISC11);
						break;
					case EXTI_ANY_CHANGE:
						SET_BIT(MCUCR_REG,MCUCR_ISC10);
						CLR_BIT(MCUCR_REG,MCUCR_ISC11);
						break;
					case EXTI_FALLING:
						CLR_BIT(MCUCR_REG,MCUCR_ISC10);
						SET_BIT(MCUCR_REG,MCUCR_ISC11);
						break;
					case EXTI_RISING:
						SET_BIT(MCUCR_REG,MCUCR_ISC10);
						SET_BIT(MCUCR_REG,MCUCR_ISC11);
						break;
				}
			break;	
			case EXTI_INT2:
				if(Copy_u8SC == EXTI_RISING)
				{
					SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
				}
				else if(Copy_u8SC == EXTI_FALLING)
				{
					CLR_BIT(MCUCSR_REG,MCUCSR_ISC2);
				}
				else
				{
					// error
				}
			break;
		}
	}
	else
	{
		// error Invalid IntID or Sense Control
	}
}



void EXTI_INT0_CallBack(void(*fun)(void))
{
	INT0_ptr=fun;
}
void __vector_1() __attribute__((signal));
void __vector_1()
{
	if(INT0_ptr!=NULL)
	{
		INT0_ptr();
	}
}


void EXTI_INT1_CallBack(void(*fun)(void))
{
	INT1_ptr=fun;
}
void __vector_2() __attribute__((signal));
void __vector_2()
{
	if(INT1_ptr!=NULL)
	{
		INT1_ptr();
	}
}


void EXTI_INT2_CallBack(void(*fun)(void))
{
	INT2_ptr=fun;
}
void __vector_3() __attribute__((signal));
void __vector_3()
{
	if(INT2_ptr!=NULL)
	{
		INT2_ptr();
	}
}
