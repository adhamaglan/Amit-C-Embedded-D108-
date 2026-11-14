/*
 * usart.c
 *
 * Created: 10/31/2026
 * Author: adham
 */

#include "../../service/std_types.h"
#include "../../service/bit_math.h"
#include "../regdef.h"
#include "usart_priv.h"
#include "usart_config.h"
#include "usart.h"



void UART_voidInit(void)
{
    u8 Local_u8UcsrcVal = 0;

    // 1. Set URSEL to access UCSRC register
    SET_BIT(Local_u8UcsrcVal, UCSRC_URSEL);

    // 2. Configure Speed Mode
#if USART_SPEED_MODE == USART_DOUBLE_SPEED
    SET_BIT(UCSRA_REG, UCSRA_U2X);
#else
    CLR_BIT(UCSRA_REG, UCSRA_U2X);
#endif

    // 3. Configure Parity Mode
#if USART_PARITY_MODE == USART_PARITY_EVEN
    SET_BIT(Local_u8UcsrcVal, UCSRC_UPM1);
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UPM0);
#elif USART_PARITY_MODE == USART_PARITY_ODD
    SET_BIT(Local_u8UcsrcVal, UCSRC_UPM1);
    SET_BIT(Local_u8UcsrcVal, UCSRC_UPM0);
#else
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UPM1);
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UPM0);
#endif

    // 4. Configure Stop Bits
#if USART_STOP_BITS == USART_STOP_2_BITS
    SET_BIT(Local_u8UcsrcVal, UCSRC_USBS);
#else
    CLR_BIT(Local_u8UcsrcVal, UCSRC_USBS);
#endif

    // 5. Configure Data Bits
#if USART_DATA_SIZE == USART_DATA_5_BITS
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UCSZ0);
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UCSZ1);
    CLR_BIT(UCSRB_REG, UCSRB_UCSZ2);
#elif USART_DATA_SIZE == USART_DATA_6_BITS
    SET_BIT(Local_u8UcsrcVal, UCSRC_UCSZ0);
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UCSZ1);
    CLR_BIT(UCSRB_REG, UCSRB_UCSZ2);
#elif USART_DATA_SIZE == USART_DATA_7_BITS
    CLR_BIT(Local_u8UcsrcVal, UCSRC_UCSZ0);
    SET_BIT(Local_u8UcsrcVal, UCSRC_UCSZ1);
    CLR_BIT(UCSRB_REG, UCSRB_UCSZ2);
#else // 8 Bits Default
    SET_BIT(Local_u8UcsrcVal, UCSRC_UCSZ0);
    SET_BIT(Local_u8UcsrcVal, UCSRC_UCSZ1);
    CLR_BIT(UCSRB_REG, UCSRB_UCSZ2);
#endif

    // Apply configuration to UCSRC register
    UCSRC_REG = Local_u8UcsrcVal;

    // 6. Set initial default baud rate
    UART_voidSetBaudRate(USART_DEFAULT_BAUD_RATE);

    // 7. Enable Interrupts if configured
#if USART_RX_INTERRUPT == USART_INTERRUPT_ENABLE
    SET_BIT(UCSRB_REG, UCSRB_RXCIE);
#endif

#if USART_TX_INTERRUPT == USART_INTERRUPT_ENABLE
    SET_BIT(UCSRB_REG, UCSRB_TXCIE);
#endif

#if USART_UDRE_INTERRUPT == USART_INTERRUPT_ENABLE
    SET_BIT(UCSRB_REG, UCSRB_UDRIE);
#endif

    // 8. Enable Transmitter and Receiver
    SET_BIT(UCSRB_REG, UCSRB_TXEN);
    SET_BIT(UCSRB_REG, UCSRB_RXEN);
}



void UART_voidSetBaudRate(u32 Copy_u32BaudRate)
{
    u16 Local_u16UbrrVal = 0;

#if USART_SPEED_MODE == USART_DOUBLE_SPEED
    Local_u16UbrrVal = (u16)((USART_F_CPU / (8UL * Copy_u32BaudRate)) - 1);
#else
    Local_u16UbrrVal = (u16)((USART_F_CPU / (16UL * Copy_u32BaudRate)) - 1);
#endif

    // Write upper 4 bits of UBRR to UBRRH (URSEL must be 0)
    UBRRH_REG = (u8)(Local_u16UbrrVal >> 8);
    // Write lower 8 bits to UBRRL
    UBRRL_REG = (u8)(Local_u16UbrrVal);
}



void UART_voidSend(u8 Copy_u8Data)
{
    while (GET_BIT(UCSRA_REG, UCSRA_UDRE) == 0);
    UDR_REG = Copy_u8Data;
}



u8 UART_u8Receive(void)
{
    while (GET_BIT(UCSRA_REG, UCSRA_RXC) == 0);
    return UDR_REG;
}



u8 UART_u8ReceiveNonBlocking(u8 *Copy_pu8Data)
{
    u8 Local_u8ErrorState = 0;

    if (GET_BIT(UCSRA_REG, UCSRA_RXC) == 1)
    {
        *Copy_pu8Data = UDR_REG;
        Local_u8ErrorState = 1; // Byte received successfully
    }
    else
    {
        Local_u8ErrorState = 0; // No byte in buffer
    }

    return Local_u8ErrorState;
}



void UART_voidSendString(const u8 *Copy_pu8Str)
{
    u8 Local_u8Index = 0;
    while (Copy_pu8Str[Local_u8Index] != '\0')
    {
        UART_voidSend(Copy_pu8Str[Local_u8Index]);
        Local_u8Index++;
    }
}



void UART_voidSendNumber(s16 Copy_s16Number)
{
	u8 Local_u8Digits[10];
	s8 Local_s8Index = 0;

	if (Copy_s16Number == 0)
	{
		UART_voidSend('0');
		return;
	}

	if (Copy_s16Number < 0)
	{
		UART_voidSend('-');
		Copy_s16Number = -Copy_s16Number;
	}

	while (Copy_s16Number > 0)
	{
		Local_u8Digits[Local_s8Index] = (Copy_s16Number % 10) + '0';
		Copy_s16Number /= 10;
		Local_s8Index++;
	}

	while (--Local_s8Index >= 0)
	{
		UART_voidSend(Local_u8Digits[Local_s8Index]);
	}
}

