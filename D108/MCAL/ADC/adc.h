/*
 * adc.h
 *
 * Created: 9/11/2026 7:48:03 PM
 *  Author: adham
 */ 


#ifndef ADC_H_
#define ADC_H_



#define ADC_CHANNEL_0	0
#define ADC_CHANNEL_1	1
#define ADC_CHANNEL_2	2
#define ADC_CHANNEL_3	3
#define ADC_CHANNEL_4	4
#define ADC_CHANNEL_5	5
#define ADC_CHANNEL_6	6
#define ADC_CHANNEL_7	7
#define ADC_CHANNEL_8	8

void ADC_voidInit();
u16	 ADC_u16ReadValue(u8 Copy_u8Channel);



#endif /* ADC_H_ */