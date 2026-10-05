/*
 * uart.h
 *
 * Created: 9/25/2026 8:20:17 PM
 *  Author: adham
 */ 


#ifndef USART_H_
#define USART_H_



void UART_voidInit(void);
void UART_voidSend(u8 Copy_u8data);
u8	 UART_u8Receive(void);
void UART_voidSendString(const u8 *Copy_u8Str);



#endif /* USART_H_ */