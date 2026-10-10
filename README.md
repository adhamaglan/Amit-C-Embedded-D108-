# D108 - AVR Microcontroller Driver Workspace

A highly modular firmware application built for AVR architecture (e.g., ATmega32) using **Atmel Studio 7.0**. This repository implements a layered software architecture featuring custom hardware abstraction drivers for Character LCDs (CLCD) and Keypads (KPAD).

## Software Architecture

The codebase follows an industry-standard layered design pattern to maximize code reusability and hardware independence.

## 🛠️ How to Build and Run

### Using Microchip Studio / Atmel Studio 7.0
1. **Clone this repository to your local computer:**
```bash
git clone https://github.com/adhamaglan/Amit-C-Embedded-D108-.git
```

2. **Launch Microchip Studio (Atmel Studio 7.0).**

3. **Select File > Open > Project/Solution... and open the project solution file (`.atsln`).**

4. **Build solution and burn the `.hex` file on your `ATmega32` chip**

## 📂 Repository Structure

<details open>
<summary><b>📦 Project Root Workspace</b></summary>

* 📄 **`main.c`** — Application entry point.

<blockquote>

### 📑 Layered Architecture Breakdown

<details>
<summary>📂 <b>MCAL</b> (Microcontroller Abstraction Layer)</summary>

* 📄 **`regdef.h`** — Direct volatile memory-mapped register pointer definitions for AVR (Atmega32).
<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>DIO/</b> (Digital Input/Output Driver)</summary>

* 📄 `dio.c` — Implementation of pin/port controls ( direction, value, etc... ).
* 📄 `dio.h` — Pin/Port directions and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>GIE/</b> (Global Interrupt Enable Driver)</summary>

* 📄 `gie.c` — Implementation of global Interrupt Enable functions.
* 📄 `gie.h` — global Interrupt Enable functions declarations.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>EXTI/</b> (External Interrupts Driver)</summary>

* 📄 `exti.c` — Implementation of interrupts control, sense control, call-back functions.
* 📄 `exti.h` — External interrupts functions declarations and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>ADC/</b> (Analogue to digital converter Driver)</summary>

* 📄 `adc.c` — Implementation of Analogue to digital converter functions.
* 📄 `adc.h` — Analogue to digital converter functions declarations and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>TIMER0/</b> (Timer/Counter 0 Driver)</summary>

* 📄 `timer0.c` — Implementation of Timer0 functions.
* 📄 `timer0.h` — Timer0 functions declarations and macro definitions.
* 📄 `timer0_cfg.h` — Timer0 Modes configurations.
* 📄 `timer0_priv.h` — Timer0 private macros.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>USART/</b> (Universal Synchronous/Asynchronous Receiver/Transmitter Driver)</summary>

* 📄 `usart.c` — Implementation of usart functions.
* 📄 `usart.h` — usart functions declarations.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>SPI/</b> (Serial Peripheral Interface Driver)</summary>

* 📄 `spi.c` — Implementation of spi functions.
* 📄 `spi.h` — spi functions declarations and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>TWI (I2C)/</b> (Two-Wire Interface Driver)</summary>

* 📄 `twi.c` — Implementation of twi functions.
* 📄 `twi.h` — twi functions declarations and error status enum.
* 📄 `twi_cfg.h` — twi frequency and clock configurations.
* 📄 `twi_priv.h` — twi private macros.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>EEPROM/</b> (Electrically Erasable Programmable Read-Only Memory [Internal])</summary>

* 📄 `eeprom.c` — Implementation of eeprom functions.
* 📄 `eeprom.h` — eeprom functions declarations.
</details>
</details>


<details>
<summary>📂 <b>HAL</b> (Hardware Abstraction Layer)</summary>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>CLCD/</b> (Character LCD Driver)</summary>

* 📄 `CLCD_config.h` — Interface pin routing layout.
* 📄 `CLCD_int.h` — Character LCD Functions declarations.
* 📄 `CLCD_prog.c` — Character LCD Functions implementations.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>KPAD/</b> (Matrix Keypad Driver)</summary>

* 📄 `KPAD_config.h` — Row/column matrix pins.
* 📄 `KPAD_int.h` — Matrix keypad Functions declarations.
* 📄 `KPAD_priv.h` — Row/column matrix key numbers/definitions.
* 📄 `KPAD_prog.c` — Matrix keypad Functions implementations.
</details>
<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>EEPROM_EXT/</b> (Electrically Erasable Programmable Read-Only Memory [External])</summary>

* 📄 `eeprom_ext.c` — Implementation of eeprom functions.
* 📄 `eeprom_ext.h` — eeprom functions declarations.
</details>
</details>

<details>
<summary>📂 <b>service</b> (Shared Utilities Layer)</summary>

* 📄 **`bit_math.h`** — Highly optimized bitwise macro functions (`SET_BIT`, `CLR_BIT`, `GET_BIT`, etc...).
* 📄 **`std_types.h`** — Platform-independent strict width primitive overrides (`u8`, `s16`, `f32`, etc...).
</details>

</blockquote>
</details>


---

## 🎛️ Peripheral Configurations

### 1. Character LCD (CLCD)
The system is configured to run both optimized **4-Bit Mode** and **8-Bit Mode**.
* **The interface:** 
    * 8-Bit Mode -> `CLCD_8_BITS`
    * 4-Bit Mode -> `CLCD_4_BITS`
* **Data Port:** `CLCD_DATA_PORTx`
<details style="margin-top: 5px; margin-bottom: 10px; margin-left: 20px;">
<summary> IMP! While using 4-bit mode. </summary>

* user configures the GPIO Pins for :
    * CLCD_DATA_PIN<code>x<sub>0</sub></code>
    * CLCD_DATA_PIN<code>x<sub>1</sub></code>
    * CLCD_DATA_PIN<code>x<sub>2</sub></code>
    * CLCD_DATA_PIN<code>x<sub>3</sub></code>
</details>

* **Control Port:** `CLCD_CTRL_PORTx`
    * The user configures the GPIO pins for :
        * CLCD_RS_PIN`x`
        * CLCD_RW_PIN`x`
        * CLCD_E_PIN`x`
* **Data Nibble (only on 4-bit interface):** Pins configured are mapped to data lines `D4`-`D7`

### 2. Keypad (KPAD)
The Keypad is a 4x4 Matrix containing 16 buttons
* **The interface:** 
    * it is configured to run in `8 GPIO pins`
<details style="margin-top: 5px; margin-bottom: 10px; margin-left: 20px;">
<summary> Data Port/Ports: <code>KPAD_COL_PORTx</code> & <code>KPAD_ROW_PORTx</code> </summary>

* user configures the GPIO Pins for :
    * **KPAD_COL_PORT`x`**
        * KPAD_COL_PIN<code>x<sub>0</sub></code>
        * KPAD_COL_PIN<code>x<sub>1</sub></code>
        * KPAD_COL_PIN<code>x<sub>2</sub></code>
        * KPAD_COL_PIN<code>x<sub>3</sub></code>

    * **KPAD_ROW_PORT`x`**
        * KPAD_ROW_PIN<code>x<sub>0</sub></code>
        * KPAD_ROW_PIN<code>x<sub>1</sub></code>
        * KPAD_ROW_PIN<code>x<sub>2</sub></code>
        * KPAD_ROW_PIN<code>x<sub>3</sub></code>
</details>



## 📌 API Reference

### DIO Driver (`dio.h`)
```c
void DIO_voidSetPinDir (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Dir); 
// allows user to set `pin` to input/output

void DIO_voidSetPinVal (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Val);
// allows user to set `pin` to High/Low

u8 DIO_u8GetPinVal (u8 Copy_u8PortID, u8 Copy_u8PinID);
// allows user to get `pin` data

void DIO_voidSetPortDir (u8 Copy_u8PortID, u8 Copy_u8Dir);
// allows user to set `port` to input/output

void DIO_voidSetPortVal (u8 Copy_u8PortID, u8 Copy_u8Val);
// allows user to set `port` to High/Low

u8 DIO_u8GetPortVal (u8 Copy_u8PortID);
// allows user to get `port` data

void DIO_voidTogPinVal (u8 Copy_u8PortID,u8 Copy_u8PinID);
// allows user to toggle `pin` states 1/0

void DIO_voidEnablePullUp (u8 Copy_u8PortID,u8 Copy_u8PinID);
// allows user to set `pin` to pull-up
```
### GIE Driver (`gie.h`)
```c
void GIE_voidEnableGlobalInterrupt(void);
//  allows user to enable Global interrupts

void GIE_voidDisableGlobalInterrupt(void);
//  allows user to disable Global interrupts
```
### EXTI Driver (`exti.h`)
```c
void EXTI_voidEnableInt(u8 Copy_u8Int);
//  allows user to enable an interrupt pin

void EXTI_voidDisableInt(u8 Copy_u8Int);
//  allows user to disable an interrupt pin

void EXTI_voidSetSenseControl(u8 Copy_u8Int,u8 Copy_u8SC);
//  allows user to control what causes an interrupt ex: Falling edge

void EXTI_INT0_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
//  allows user to control Interrupt 0 routine

void EXTI_INT1_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
//  allows user to control Interrupt 1 routine

void EXTI_INT2_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
//  allows user to control Interrupt 2 routine
```
### ADC Driver (`adc.h`)
```c
void ADC_voidInit(void);
//  initializes the ADC

u16	 ADC_u16ReadValue(u8 Copy_u8Channel);
//  allows user to read the digital value from the ADC
```
### Timer0 Driver (`timer0.h`)
```c
void TIMER0_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode);
//  initializes timer0 and allows user to choose the clock pre-scaler and Mode

void TIMER0_voidSetPreloadVal(u8 Copy_u8Val);
//  allows user to preload the timer (count from an offset)

void TIMER0_voidSetOCRVal(u8 Copy_u8Val);
//  allows user to set the OCR0 value

void TIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle);
//  allows the user to set the pulse duty cycle

void TIMER0_voidSetCallBackOCR(void (*Copy_ptrvoidCallBackFunc)(void));
//  allows user to control timer0 (output compare) Interrupt routine

void TIMER0_voidSetCallBackOVF(void (*Copy_ptrvoidCallBackFunc)(void));
//  allows user to control timer0 (overflow) Interrupt routine
```
### USART/UART Driver (`usart.h`)
```c
void UART_voidInit(void);
//  initializes USART/UART

void UART_voidSend(u8 Copy_u8data);
//  allows user to send data

u8  UART_u8Receive(void);
//  allows user to receive data

void UART_voidSendString(const u8 *Copy_u8Str);
// allows user to send a string
```
### SPI Driver (`spi.h`)
```c
void SPI_voidMasterInit(void);
//  initializes SPI Master

u8  SPI_u8MasterSend(u8 Copy_u8data);
//  allows user to send/receive data as Master

void SPI_voidSlaveInit(void);
//  initializes SPI Slave

u8  SPI_u8SlaveSend(u8 Copy_u8data);
//  allows user to send/receive data as Slave
```
### TWI/I2C Driver (`twi.h`)
```c
void TWI_MasterInit(void);
//  initializes TWI/I2C Master

u8 TWI_u8SendStartCondition(void);
//  allows user to send start contidtion

u8 TWI_u8SendRepStartCondition(void);
//  allows user to send repeated start contidtion

u8 TWI_u8SendStopCondition(void);
//  allows user to send stop contidtion

u8 TWI_u8MasterSendSlaveAddWithRead(u8 Copy_u8SLA);
//  allows user to send the slave address and read bit

u8 TWI_u8MasterSendSlaveAddWithWrite(u8 Copy_u8SLA);
//  allows user to send the slave address and write bit

u8 TWI_u8MasterSendData(u8 Copy_u8Data);
//  allows user to send data as Master

u8 TWI_u8MasterReceiveData(u8* Copy_u8Data);
//  allows user to receive data as Master

void TWI_SlaveInit(void);
//  initializes TWI/I2C Slave

u8 TWI_u8SlaveSendData(u8 Copy_u8Data);
//  allows user to send data as Slave

u8 TWI_u8SlaveReceiveData(u8* Copy_u8Data);
//  allows user to receive data as Slave
```
### LCD Subsystem (`CLCD_int.h`)
```c
void CLCD_voidInit(void);
// initializes the LCD

void CLCD_voidSendData (u8 Copy_u8Data);
// allows user to send data to LCD

void CLCD_voidSendInst (u8 Copy_u8Data);
// allows user to send instruction/command to LCD

void CLCD_voidSendString (const u8 *Copy_u8Str);
// allows user to send a string to LCD (using send data function)

void CLCD_voidSendNumber(s32 Copy_s32Number);
// allows user to send a number to LCD from -2,147,483,648 to 2,147,483,647

void CLCD_voidSetCursorPos (u8 Copy_u8x,u8 Copy_u8y);
// allows user to control cursor position

void CLCD_voidClearScreen (void);
// clears LCD screen

void CLCD_voidSendSpecialChar (u8 Copy_u8Index,const u8 *Copy_u8Arr,u8 Copy_u8x,u8 Copy_u8y);
// allows user to create special characters and store them in CGRAM and send it to LCD
```
### Keypad Subsystem  (`KPAD_int.h`)
```c
void KPAD_voidInit (void);
// initializes the Keypad

u8 KPAD_u8GetKeyPressed (void);
// allows the user to get the pressed key
```