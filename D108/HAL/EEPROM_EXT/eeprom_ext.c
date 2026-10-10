/*
 * eeprom_ext.c
 *
 * Created: 10/10/2026 1:40:08 PM
 *  Author: adham
 */ 
#define F_CPU 16000000ul

#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../../MCAL/TWI/twi.h"
#include "eeprom_ext.h"
#include <util/delay.h>



void EEPROM_EXT_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket;

	// AT24C16: 0x50 base + 3-bit page selection (Bits 8..10 of address)
	Local_u8AddressPacket = 0x50 | ((Copy_u16LocationAddress >> 8) & 0x07);
	// Send start condition
	TWI_u8SendStartCondition();
	// Send slave address with write request
	TWI_u8MasterSendSlaveAddWithWrite(Local_u8AddressPacket);
	// Send lower 8 bits of memory word address
	TWI_u8MasterSendData((u8)Copy_u16LocationAddress);
	// Send the data byte
	TWI_u8MasterSendData(Copy_u8DataByte);
	// Send stop condition
	TWI_u8SendStopCondition();
	// Delay until the write cycle is finished
	_delay_ms(10);
}



u8   EEPROM_EXT_u8ReadDataByte(u16 Copy_u16LocationAddress)
{
	u8 Local_u8AddressPacket;
	u8 Local_u8DataByte = 0;
	
	// AT24C16: 0x50 base + 3-bit page selection (Bits 8..10 of address)
	Local_u8AddressPacket = 0x50 | ((Copy_u16LocationAddress >> 8) & 0x07);
	// Send start condition
	TWI_u8SendStartCondition();
	// Send Dummy write sequence
	TWI_u8MasterSendSlaveAddWithWrite(Local_u8AddressPacket);
	// Send lower 8 bits of memory word address
	TWI_u8MasterSendData((u8)Copy_u16LocationAddress);
	// Send Repeated start to switch to read mode
	TWI_u8SendRepStartCondition();
	// Send slave address with read request
	TWI_u8MasterSendSlaveAddWithRead(Local_u8AddressPacket);
	// Read data byte and return NACK
	TWI_u8MasterReceiveDataWithNACK(&Local_u8DataByte);
	// Send stop condition
	TWI_u8SendStopCondition();

	return Local_u8DataByte;
}