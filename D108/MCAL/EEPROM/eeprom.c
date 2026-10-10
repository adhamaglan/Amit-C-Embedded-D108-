/*
 * eeprom.c
 *
 * Created: 10/9/2026 7:05:00 PM
 *  Author: adham
 */ 
#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../regdef.h"
#include "eeprom.h"



void EEPROM_voidWriteDataByte(u16 Copy_u16adress, u8 Copy_u8data)
{
	// Wait until previous EEPROM write operation completes
	while (GET_BIT(EECR_REG, EECR_EEWE) != 0);
	// Load address and data into internal EEPROM registers
	EEAR_REG = Copy_u16adress;
	EEDR_REG = Copy_u8data;
	// Set Master Write Enable FIRST
	SET_BIT(EECR_REG, EECR_EEMWE);
	// Trigger Write Enable within 4 clock cycles
	SET_BIT(EECR_REG, EECR_EEWE);
}



u8 EEPROM_voidReadDataByte(u16 Copy_u16adress)
{
	// Wait until any ongoing write operation completes
	while (GET_BIT(EECR_REG, EECR_EEWE) != 0);
	// Load target memory address
	EEAR_REG = Copy_u16adress;
	// Enable Read (EERE)
	SET_BIT(EECR_REG, EECR_EERE);
	// Return data from EEPROM Data Register
	return EEDR_REG;
}