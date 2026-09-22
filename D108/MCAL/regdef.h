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
#define	ADMUX_ADLAR		5
#define	ADMUX_REFS0		6
#define ADMUX_REFS1		7
#define ADCSRA_REG	*((volatile u8*)(0x26))
#define	ADCSRA_ADPS0	0
#define	ADCSRA_ADPS1	1
#define ADCSRA_ADPS2	2
#define	ADCSRA_ADIE		3
#define	ADCSRA_ADIF		4
#define	ADCSRA_ADATE	5
#define	ADCSRA_ADSC		6
#define ADCSRA_ADEN		7
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



#endif /* REGDEF_H_ */