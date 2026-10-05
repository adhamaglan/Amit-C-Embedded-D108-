/*
 * spi.h
 *
 * Created: 9/26/2026 8:26:51 PM
 *  Author: adham
 */ 


#ifndef SPI_H_
#define SPI_H_



#define SPI_PORT			DIO_PORTB

#define SPI_SPI_SS_PIN		DIO_PIN4
#define SPI_SPI_MOSI_PIN	DIO_PIN5
#define SPI_SPI_MISO_PIN	DIO_PIN6
#define SPI_SPI_SCK_PIN		DIO_PIN7



void SPI_voidMasterInit(void);
u8	 SPI_u8MasterSend(u8 Copy_u8data);

void SPI_voidSlaveInit(void);
u8	 SPI_u8SlaveSend(u8 Copy_u8data);



#endif /* SPI_H_ */