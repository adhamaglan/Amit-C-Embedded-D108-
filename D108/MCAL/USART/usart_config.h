/*
 * usart_config.h
 *
 * Created: 10/31/2026 1:41:17 AM
 *  Author: adham
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_



// Select Oscillator Frequency in Hz
#define USART_F_CPU               16000000UL

// Default Baud Rate
#define USART_DEFAULT_BAUD_RATE   9600UL

/* 
 * Select Speed Mode:
 * 1. USART_NORMAL_SPEED
 * 2. USART_DOUBLE_SPEED
 */
#define USART_SPEED_MODE          USART_NORMAL_SPEED

/* 
 * Select Parity Mode:
 * 1. USART_PARITY_DISABLE
 * 2. USART_PARITY_EVEN
 * 3. USART_PARITY_ODD
 */
#define USART_PARITY_MODE         USART_PARITY_DISABLE

/* 
 * Select Stop Bits:
 * 1. USART_STOP_1_BIT
 * 2. USART_STOP_2_BITS
 */
#define USART_STOP_BITS           USART_STOP_1_BIT

/* 
 * Select Data Size:
 * 1. USART_DATA_5_BITS
 * 2. USART_DATA_6_BITS
 * 3. USART_DATA_7_BITS
 * 4. USART_DATA_8_BITS
 */
#define USART_DATA_SIZE           USART_DATA_8_BITS

/* 
 * Interrupt Enables:
 * 1. USART_INTERRUPT_DISABLE
 * 2. USART_INTERRUPT_ENABLE
 */
#define USART_RX_INTERRUPT        USART_INTERRUPT_DISABLE
#define USART_TX_INTERRUPT        USART_INTERRUPT_DISABLE
#define USART_UDRE_INTERRUPT      USART_INTERRUPT_DISABLE



#endif /* USART_CONFIG_H_ */