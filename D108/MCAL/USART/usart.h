/*
 * uart.h
 *
 * Created: 9/25/2026 8:20:17 PM
 *  Author: adham
 */ 


#ifndef USART_H_
#define USART_H_



void UART_voidInit(void);
void UART_voidSetBaudRate(u32 Copy_u32BaudRate);

void UART_voidSend(u8 Copy_u8Data);
u8   UART_u8Receive(void);
u8   UART_u8ReceiveNonBlocking(u8 *Copy_pu8Data);
void UART_voidSendString(const u8 *Copy_pu8Str);
void UART_voidSendNumber(s16 Copy_s16Number);



#endif /* USART_H_ */