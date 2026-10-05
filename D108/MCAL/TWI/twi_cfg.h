/*
 * twi_config.h
 *
 * Created: 10/5/2026 12:39:34 PM
 *  Author: adham
 */ 


#ifndef TWI_CFG_H_
#define TWI_CFG_H_

#ifndef F_CPU
#define	F_CPU	16000000UL
#endif

// setting the clock freq for 400Khz
#define SCL_FREQUENCY		400000UL


#define TWI_PRESCALER		TWI_PRESCALER_1
/*	
	Options:
	TWI_PRESCALER_1
	TWI_PRESCALER_4
	TWI_PRESCALER_16
	TWI_PRESCALER_64
*/


#endif /* TWI_CONFIG_H_ */