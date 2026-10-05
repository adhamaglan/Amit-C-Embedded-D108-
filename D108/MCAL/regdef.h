/*
 * regdef.h
 *
 * Created: 8/15/2026 8:03:46 PM
 *  Author: adham
 */ 


#ifndef REGDEF_H_
#define REGDEF_H_



//	Status register
#define SREG_REG   *((volatile u8*)(0x5F))		
// ---------------------------------------

//	Timer Interrupt Registers
#define TIMSK_REG   *((volatile u8*)(0x59))		// Interrupt Mask Register (Enables Timer Interrupts)
#define TIMSK_TOIE0 0							// Timer0 Overflow Interrupt Enable Bit
#define TIMSK_OCIE0 1							// Timer0 OCR Interrupt Enable Bit
#define TIFR_REG    *((volatile u8*)(0x58))		// Interrupt Flag Register (gets cleared automatically if GIE and TIMSK are enabled)
#define TIFR_TOV0   0							// Timer0 Overflow Flag Bit
#define TIFR_OCF0   1							// Timer0 OCR Flag Bit
// ---------------------------------------

//	External interrupt registers
#define GICR_REG   *((volatile u8*)(0x5B))		//	General Interrupt Control Register
#define GICR_INT2   5
#define GICR_INT0   6
#define GICR_INT1   7
#define GIFR_REG   *((volatile u8*)(0x5A))		//  General Interrupt Flag Register
#define GIFR_INTF2  5
#define GIFR_INTF0  6
#define GIFR_INTF1  7
#define MCUCR_REG  *((volatile u8*)(0x55))		//	MCU control register
#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3
#define MCUCSR_REG *((volatile u8*)(0x54))		//	MCU control and status register
#define MCUCSR_ISC2	6		
// ---------------------------------------

//	Direct Input/Output registers
#define PORTA_REG  *((volatile u8*)(0x3B))
#define DDRA_REG   *((volatile u8*)(0x3A))
#define PINA_REG   *((volatile u8*)(0x39))

#define PORTB_REG  *((volatile u8*)(0x38))
#define DDRB_REG   *((volatile u8*)(0x37))
#define PINB_REG   *((volatile u8*)(0x36))

#define PORTC_REG  *((volatile u8*)(0x35))
#define DDRC_REG   *((volatile u8*)(0x34))
#define PINC_REG   *((volatile u8*)(0x33))

#define PORTD_REG  *((volatile u8*)(0x32))
#define DDRD_REG   *((volatile u8*)(0x31))
#define PIND_REG   *((volatile u8*)(0x30))
// ---------------------------------------

//	Analogue to Digital Converter registers
#define ADMUX_REG	*((volatile u8*)(0x27))
#define	ADMUX_ADLAR	5
#define	ADMUX_REFS0	6
#define ADMUX_REFS1	7
#define ADCSRA_REG	*((volatile u8*)(0x26))
#define	ADCSRA_ADPS0 0
#define	ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2
#define	ADCSRA_ADIE	 3
#define	ADCSRA_ADIF	 4
#define	ADCSRA_ADATE 5
#define	ADCSRA_ADSC	 6
#define ADCSRA_ADEN	 7
#define ADCH_REG	*((volatile u8*)(0x25))
#define ADCL_REG	*((volatile u8*)(0x24))
#define ADC_REG		*((volatile u8*)(0x24))
// ---------------------------------------

//	Timer 0 registers
#define TCCR0_REG	*((volatile u8*)(0x53))		//	Timer/Counter Control Register
#define TCCR0_COM00 4							//	Timer0 Compare Output Mode 00
#define	TCCR0_COM01 5							//	Timer0 Compare Output Mode 01
#define TCCR0_WGM01 3							//	Timer0 Waveform generation mode 01
#define TCCR0_WGM00 6							//	Timer0 Waveform generation mode 00
#define	TCCR0_FOC0  7							//	Timer0 Force Output Compare
#define TCNT0_REG	*((volatile u8*)(0x52))		//	Timer/Counter Register
#define OCR0_REG	*((volatile u8*)(0x5C))		//	Output Compare Register
// ---------------------------------------

//	USART registers
#define UDR_REG		*((volatile u8*)(0x2C))		//	USART Data Register
#define UCSRA_REG	*((volatile u8*)(0x2B))		//	USART Control and Status Register A
#define UCSRA_MPCM	0
#define UCSRA_U2X	1
#define UCSRA_PE	2							//  Bit is set in case of Parity Error
#define UCSRA_DOR	3							//  Bit is set in case of Data OverRun
#define UCSRA_FE	4							//  Bit is set in case of Frame Error
#define UCSRA_UDRE	5							//  USART Data Register Empty flag
#define UCSRA_TXC	6							//  USART Transmit Complete flag
#define UCSRA_RXC	7							//  USART Receive Complete flag
#define UCSRB_REG	*((volatile u8*)(0x2A))		//	USART Control and Status Register B
#define UCSRB_TXB8	0
#define UCSRB_RXB8	1
#define UCSRB_UCSZ2	2							//  Character Size bit 2
#define UCSRB_TXEN	3							//  Transmitter Enable
#define UCSRB_RXEN	4							//  Receiver Enable
#define UCSRB_UDRIE	5							
#define UCSRB_TXCIE	6
#define UCSRB_RXCIE	7
#define UCSRC_REG	*((volatile u8*)(0x40))		//	USART Control and Status Register C
#define UCSRC_UCPOL	0
#define UCSRC_UCSZ0	1							//  Character Size bit 0
#define UCSRC_UCSZ1	2							//  Character Size bit 1
#define UCSRC_USBS	3							//  Stop Bit Select (0 = 1-bit, 1 = 2-bit)
#define UCSRC_UPM0	4							//  Parity Mode Bit 1
#define UCSRC_UPM1	5							//  Parity Mode Bit 1
#define UCSRC_UMSEL 6							//  USART Mode Select (0 = Asynchronous, 1 = Synchronous)
#define UCSRC_URSEL 7							//  Register Select (1 = UCSRC, 0 = UBRRH)
#define UBRRH_REG	*((volatile u8*)(0x40))
#define UBRRL_REG	*((volatile u8*)(0x29))		
// ---------------------------------------

//	SPI registers
#define SPCR_REG	*((volatile u8*)(0x2D))		//	SPI Control Register
#define SPCR_SPR0	0							//	SPI Clock Rate Select 0
#define SPCR_SPR1	1							//	SPI Clock Rate Select 1 
#define SPCR_CPHA	2							//	Clock Phase
#define SPCR_CPOL	3							//	Clock Polarity
#define SPCR_MSTR	4							//	Master/Slave Select
#define SPCR_DORD	5							//	Data Order
#define SPCR_SPE	6							//	SPI Enable
#define SPCR_SPIE	7							//	SPI Interrupt Enable
#define SPSR_REG	*((volatile u8*)(0x2E))		//	SPI Status Register
#define SPSR_SPI2X	0							//	Double SPI Speed Bit
#define SPSR_WCOL	6							//	Write COLlision Flag
#define SPSR_SPIF	7							//	SPI Interrupt Flag
#define SPDR_REG	*((volatile u8*)(0x2F))		//	SPI Data Register
// ---------------------------------------

//	I2C registers
#define TWBR_REG	*((volatile u8*)(0x20))		//	TWI Bit Rate Register 
#define TWCR_REG	*((volatile u8*)(0x56))		//	TWI Control Register
#define TWCR_TWIE	0							//	TWI Interrupt Enable
#define TWCR_TWEN	2							//	TWI Enable Bit
#define TWCR_TWWC	3							//	TWI Write Collision Flag
#define TWCR_TWSTO	4							//	TWI STOP Condition Bit
#define TWCR_TWSTA	5							//	TWI START Condition Bit
#define TWCR_TWEA	6							//	TWI Enable Acknowledge Bit
#define TWCR_TWINT	7							//	TWI Interrupt Flag
#define TWSR_REG	*((volatile u8*)(0x21))		//	TWI Status Register
#define TWSR_TWPS0	0							//	TWI Pre-scaler Bit 0
#define TWSR_TWPS1	1							//	TWI Pre-scaler Bit 1
#define TWSR_TWS3	3							//	TWI Status 3
#define TWSR_TWS4	4							//	TWI Status 4
#define TWSR_TWS5	5							//	TWI Status 5
#define TWSR_TWS6	6							//	TWI Status 6
#define TWSR_TWS7	7							//	TWI Status 7
#define TWDR_REG	*((volatile u8*)(0x23))		//	TWI Data Register
#define TWAR_REG	*((volatile u8*)(0x22))		//	TWI (Slave) Address 
#define TWAR_TWGCE	0							//	TWI General Call Recognition Enable Bit
// ---------------------------------------



#endif /* REGDEF_H_ */