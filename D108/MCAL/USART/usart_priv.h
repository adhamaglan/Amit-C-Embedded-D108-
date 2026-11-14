/*
 * usart_priv.h
 *
 * Created: 10/31/2026 1:41:38 AM
 *  Author: adham
 */ 


#ifndef USART_PRIV_H_
#define USART_PRIV_H_



// Speed Modes
#define USART_NORMAL_SPEED          0
#define USART_DOUBLE_SPEED          1

// Parity Options
#define USART_PARITY_DISABLE        0
#define USART_PARITY_EVEN           1
#define USART_PARITY_ODD            2

// Stop Bits Options
#define USART_STOP_1_BIT            0
#define USART_STOP_2_BITS           1

// Data Size Options
#define USART_DATA_5_BITS           0
#define USART_DATA_6_BITS           1
#define USART_DATA_7_BITS           2
#define USART_DATA_8_BITS           3

// Interrupt Control Options
#define USART_INTERRUPT_DISABLE     0
#define USART_INTERRUPT_ENABLE      1



#endif /* USART_PRIV_H_ */