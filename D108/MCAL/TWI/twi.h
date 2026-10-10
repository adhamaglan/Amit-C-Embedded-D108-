/*
 * twi.h
 *
 * Created: 10/3/2026 7:07:55 PM
 *  Author: adham
 */ 


#ifndef TWI_H_
#define TWI_H_



typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
}TWI_ErrStatus;

void TWI_MasterInit(void);
u8 TWI_u8SendStartCondition(void);
u8 TWI_u8SendRepStartCondition(void);
u8 TWI_u8SendStopCondition(void);
u8 TWI_u8MasterSendSlaveAddWithRead(u8 Copy_u8SLA);
u8 TWI_u8MasterSendSlaveAddWithWrite(u8 Copy_u8SLA);
u8 TWI_u8MasterSendData(u8 Copy_u8Data);
u8 TWI_u8MasterReceiveDataWithACK(u8* Copy_u8Data);
u8 TWI_u8MasterReceiveDataWithNACK(u8* Copy_u8Data);

void TWI_SlaveInit(u8 Copy_u8SLA);
u8 TWI_u8SlaveSendDataByte(u8 Copy_u8Data);
u8 TWI_u8SlaveReceiveDataByte(u8* Copy_u8Data);



#endif /* TWI_H_ */