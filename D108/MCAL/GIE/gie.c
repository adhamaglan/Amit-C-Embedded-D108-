/*
 * gie.c
 *
 * Created: 9/4/2026 8:30:33 PM
 *  Author: adham
 */ 

#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../regdef.h"
#include "gie.h"



void GIE_voidEnableGlobalInterrupt(void)
{
	// SET_BIT(SREG_REG,7);
	__asm("SEI");
}



void GIE_voidDisableGlobalInterrupt(void)
{
	// CLR_BIT(SREG_REG,7);
	__asm("CLI");
}