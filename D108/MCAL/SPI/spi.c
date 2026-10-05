/*
 * spi.c
 *
 * Created: 9/26/2026 8:26:59 PM
 *  Author: adham
 */ 
#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../DIO/dio.h"
#include "../regdef.h"
#include "spi.h"



void SPI_voidMasterInit(void)
{
	// Configure Port B SPI Pin Directions
	DIO_voidSetPinDir(SPI_PORT, SPI_SPI_MOSI_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(SPI_PORT, SPI_SPI_SCK_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(SPI_PORT, SPI_SPI_SS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(SPI_PORT, SPI_SPI_MISO_PIN, DIO_PIN_INPUT);
	// Configure to master 
	SET_BIT(SPCR_REG,SPCR_MSTR);
	// select pre-scaler 128
	SET_BIT(SPCR_REG,SPCR_SPR0);
	SET_BIT(SPCR_REG,SPCR_SPR1);
	CLR_BIT(SPSR_REG,SPSR_SPI2X);
	// enable SPI
	SET_BIT(SPCR_REG,SPCR_SPE);
}



u8	 SPI_u8MasterSend(u8 Copy_u8data)
{
	// put data in data reg
	SPDR_REG=Copy_u8data;
	// wait on flag
	while (GET_BIT(SPSR_REG,SPSR_SPIF)==0);
	return SPDR_REG;
}



void SPI_voidSlaveInit(void)
{
	// Configure Port B SPI Pin Directions
	DIO_voidSetPinDir(DIO_PORTB, SPI_SPI_MOSI_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTB, SPI_SPI_SCK_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTB, SPI_SPI_SS_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDir(DIO_PORTB, SPI_SPI_MISO_PIN, DIO_PIN_OUTPUT);
	// Configure to slave
	CLR_BIT(SPCR_REG,SPCR_MSTR);
	// enable SPI
	SET_BIT(SPCR_REG,SPCR_SPE);
}



u8	 SPI_u8SlaveSend(u8 Copy_u8data)
{
	SPDR_REG=Copy_u8data;
	// wait on flag
	while (GET_BIT(SPSR_REG,SPSR_SPIF)==0);
	// return data
	return SPDR_REG;
}


