/*
 * eeprom.h
 *
 * Created: 10/9/2026 7:05:15 PM
 *  Author: adham
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_



void EEPROM_voidWriteDataByte(u16 Copy_u16adress, u8 Copy_u8data);
u8	 EEPROM_voidReadDataByte(u16 Copy_u16adress);



#endif /* EEPROM_H_ */