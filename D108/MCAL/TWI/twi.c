/*
 * twi.c
 *
 * Created: 10/3/2026 7:07:22 PM
 *  Author: adham
 */ 

#include "../../service/bit_math.h"
#include "../../service/std_types.h"
#include "../regdef.h"
#include "twi_priv.h"
#include "twi_cfg.h"
#include "twi.h"



void TWI_MasterInit(void)
{
	// Calculate Bit Rate Generator value (TWBR)
#if TWI_PRESCALER == TWI_PRESCALER_1
	TWBR_REG = (u8)(((F_CPU / SCL_FREQUENCY) - 16U) / 2U);
#elif TWI_PRESCALER == TWI_PRESCALER_4
	TWBR_REG = (u8)(((F_CPU / SCL_FREQUENCY) - 16U) / 8U);
#elif TWI_PRESCALER == TWI_PRESCALER_16
	TWBR_REG = (u8)(((F_CPU / SCL_FREQUENCY) - 16U) / 32U);
#elif TWI_PRESCALER == TWI_PRESCALER_64
	TWBR_REG = (u8)(((F_CPU / SCL_FREQUENCY) - 16U) / 128U);
#endif
	// Setting the Pre-Scaler
	TWSR_REG = (TWSR_REG & 0xF8) | TWI_PRESCALER;
	// enable Acknowledge bit
	SET_BIT(TWCR_REG,TWCR_TWEA);
	// enable TWI
	SET_BIT(TWCR_REG,TWCR_TWEN);
}



u8 TWI_u8SendStartCondition(void)
{
	u8 Local_u8ErrStatus = NoError;
	// Clear TWINT flag bit, Set TWSTA, Send START condition, and ensure TWEN is set
	TWCR_REG = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	// Wait until TWINT flag is set
	while(GET_BIT(TWCR_REG,TWCR_TWINT)==0);
	// check the operation status
	if((TWSR_REG & 0xF8) != START_ACK)
	{
		Local_u8ErrStatus = StartConditionErr;
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8SendRepStartCondition(void)
{
	u8 Local_u8ErrStatus = NoError;
	// Clear TWINT flag bit, Set TWSTA, Send START condition, and ensure TWEN is set
	TWCR_REG = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);
	// Wait until TWINT flag is set
	while(GET_BIT(TWCR_REG,TWCR_TWINT)==0);
	// check the operation status
	if((TWSR_REG & 0xF8) != REP_START_ACK)
	{
		Local_u8ErrStatus = RepeatedStartError;
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8SendStopCondition(void)
{
	u8 Local_u8ErrStatus = NoError;
	// Clear TWINT flag bit, Set TWSTA, Send START condition, and ensure TWEN is set
	TWCR_REG = (1 << TWCR_TWINT) | (1 << TWCR_TWSTO) | (1 << TWCR_TWEN);
	return Local_u8ErrStatus;
}



u8 TWI_u8MasterSendSlaveAddWithRead(u8 Copy_u8SLA)
{
	u8 Local_u8ErrStatus = NoError;
	// Left shifting slave address to write the Read command on bit 0
	TWDR_REG = (Copy_u8SLA << 1U) | 1U;
	// Clear TWINT flag and enable TWI to start transmission
	TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN);
	// Wait until TWINT flag is set
	while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
	// check the operation status
	if ((TWSR_REG & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_u8ErrStatus = SlaveAddressWithReadErr;
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8MasterSendSlaveAddWithWrite(u8 Copy_u8SLA)
{
	u8 Local_u8ErrStatus = NoError;
	// Left shifting slave address to write the Write command on bit 0
	TWDR_REG = (Copy_u8SLA << 1U);
	// Clear TWINT flag and enable TWI to start transmission
	TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN);
	// Wait until TWINT flag is set
	while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
	// check the operation status
	if ((TWSR_REG & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_u8ErrStatus = SlaveAddressWithWriteErr;
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8MasterSendData(u8 Copy_u8Data)
{
	u8 Local_u8ErrStatus = NoError;
	// Write data on the Data Reg TWDR
	TWDR_REG = Copy_u8Data;
	// Clear TWINT flag and enable TWI to start transmission
	TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN);
	// Wait until TWINT flag is set
	while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
	// check the operation status
	if ((TWSR_REG & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_u8ErrStatus = MasterWriteByteErr;
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8MasterReceiveDataWithACK(u8* Copy_u8Data)
{
	u8 Local_u8ErrStatus = NoError;
	if (Copy_u8Data != NULL)
	{
		// Clear TWINT flag, enable TWI, and set TWEA to send ACK after receiving
		TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN) | (1U << TWCR_TWEA);
		// Wait until TWINT flag is set
		while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
		// check the operation status
		if ((TWSR_REG & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
		{
			Local_u8ErrStatus = MasterReadByteErr;
		}
		else
		{
			*Copy_u8Data = TWDR_REG;
		}
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8MasterReceiveDataWithNACK(u8* Copy_u8Data)
{
	u8 Local_u8ErrStatus = NoError;
	if (Copy_u8Data != NULL)
	{
		// Clear TWINT flag, enable TWI
		TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN);
		// Wait until TWINT flag is set
		while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
		// check the operation status
		if ((TWSR_REG & 0xF8) != MSTR_RD_BYTE_WITH_NACK)
		{
			Local_u8ErrStatus = MasterReadByteErr;
		}
		else
		{
			*Copy_u8Data = TWDR_REG;
		}
	}
	return Local_u8ErrStatus;
}



void TWI_SlaveInit(u8 Copy_u8SLA)
{
	// Set the Slave Address in TWAR register (Bits 7 --> 1)
	TWAR_REG = (Copy_u8SLA << 1U);
	// Enable TWI and Set TWEA to send ACK bit
	TWCR_REG = (1U << TWCR_TWEN) | (1U << TWCR_TWEA);
}



u8 TWI_u8SlaveSendDataByte(u8 Copy_u8Data)
{
	u8 Local_u8ErrStatus = NoError;
	// Clear TWINT flag, enable TWI, and set TWEA to send ACK to listen on the bus
	TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN) | (1U << TWCR_TWEA);
	// Wait until Master addresses this Slave with Read request
	while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
	// Check if Master addressed the Read request
	if ((TWSR_REG & 0xF8) == SLAVE_ADD_RCVD_RD_REQ)
	{
		// Load data byte into TWDR register
		TWDR_REG = Copy_u8Data;
		// Clear TWINT flag to start transmitting data byte
		TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN) | (1U << TWCR_TWEA);
		// Wait until byte transmission completes
		while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
		// Check if data was transmission successfully
		if ((TWSR_REG & 0xF8) != SLAVE_BYTE_TRANSMITTED)
		{
			Local_u8ErrStatus = MasterReadByteErr;
		}
	}
	else
	{
		Local_u8ErrStatus = SlaveAddressWithReadErr;
	}
	return Local_u8ErrStatus;
}



u8 TWI_u8SlaveReceiveDataByte(u8* Copy_u8Data)
{
	u8 Local_u8ErrStatus = NoError;
	if (Copy_u8Data != NULL)
	{
		// Clear TWINT flag, enable TWI, and set TWEA to send ACK to listen on the bus
		TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN) | (1U << TWCR_TWEA);
		// Wait until Master addresses this Slave with Write request
		while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
		// Check if Master addressed the Write request
		if ((TWSR_REG & 0xF8) == SLAVE_ADD_RCVD_WR_REQ)
		{
			// Clear TWINT flag and keep TWEA set to receive incoming byte
			TWCR_REG = (1U << TWCR_TWINT) | (1U << TWCR_TWEN) | (1U << TWCR_TWEA);
			// Wait till Data is received
			while (GET_BIT(TWCR_REG, TWCR_TWINT) == 0U);
			// Check if data was received successfully
			if ((TWSR_REG & 0xF8) == SLAVE_DATA_RECEIVED)
			{
				*Copy_u8Data = TWDR_REG;
			}
			else
			{
				Local_u8ErrStatus = MasterWriteByteErr;
			}
		}
		else
		{
			Local_u8ErrStatus = SlaveAddressWithWriteErr;
		}
	}
	return Local_u8ErrStatus;
}