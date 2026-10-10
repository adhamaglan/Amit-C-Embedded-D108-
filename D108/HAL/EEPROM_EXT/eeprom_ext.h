/*
 * eeprom_ext.h
 *
 * Created: 10/10/2026 1:40:16 PM
 *  Author: adham
 */ 


#ifndef EEPROM_EXT_H_
#define EEPROM_EXT_H_



void EEPROM_EXT_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);
u8   EEPROM_EXT_u8ReadDataByte(u16 Copy_u16LocationAddress);



#endif /* EEPROM_EXT_H_ */