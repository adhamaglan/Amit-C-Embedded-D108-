/*
 * uart.c
 *
 * Created: 9/25/2026 8:20:11 PM
 *  Author: adham
 */ 
# include "../../service/std_types.h"
# include "../../service/bit_math.h"
# include "../regdef.h"
# include "usart.h"



void UART_voidInit(void)
{
	// 1. Select baud rate 9600 (UBRR = 103 for 16MHz)
	UBRRH_REG=0;
	UBRRL_REG=103;
	// 2. Enable send and receive
	SET_BIT(UCSRB_REG,UCSRB_TXEN);
	SET_BIT(UCSRB_REG,UCSRB_RXEN);
	// 3. Select format: 8-bit data, 1 stop bit, no parity	// UCSRC_URSEL bit MUST be set to 1 to target UCSRC instead of UBRRH
	UCSRC_REG=0b10000110;
	CLR_BIT(UCSRB_REG,UCSRB_UCSZ2);
}



void UART_voidSend(u8 Copy_u8Data)
{
	// Wait on UDRE flag (Data Register Empty) to become 1
	while (GET_BIT(UCSRA_REG,UCSRA_UDRE)==0);
	// Put data in data register
	UDR_REG = Copy_u8Data;
}



u8 UART_u8Receive(void)
{
	// Wait on RXC flag (Receive Complete) to become 1
	while (GET_BIT(UCSRA_REG,UCSRA_RXC)==0);
	// Return received data from UDR register
	return UDR_REG;
}



void UART_voidSendString(const u8 *Copy_u8Str)
{
	u8 Local_u8Index = 0;
	while (Copy_u8Str[Local_u8Index] != '\0')
	{
		UART_voidSend(Copy_u8Str[Local_u8Index]);
		Local_u8Index++;
	}
}