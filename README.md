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

* 📄 **`dio.c`** — Implementation of pin/port controls ( direction, value, etc... ).
* 📄 **`dio.h`** — Pin/Port directions and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>GIE/</b> (Global Interrupt Enable Driver)</summary>

* 📄 **`gie.c`** — Implementation of global Interrupt Enable functions.
* 📄 **`gie.h`** — global Interrupt Enable functions declarations.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>EXTI/</b> (External Interrupts Driver)</summary>

* 📄 **`exti.c`** — Implementation of interrupts control, sense control, call-back functions.
* 📄 **`exti.h`** — External interrupts functions declarations and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>ADC/</b> (Analogue to digital converter Driver)</summary>

* 📄 **`adc.c`** — Implementation of Analogue to digital converter functions.
* 📄 **`adc.h`** — Analogue to digital converter functions declarations and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>TIMER0/</b> (Timer/Counter 0 Driver)</summary>

* 📄 **`timer0.c`** — Implementation of Timer0 functions.
* 📄 **`timer0.h`** — Timer0 functions declarations and macro definitions.
* 📄 **`timer0_cfg.h`** — Timer0 Modes configurations.
* 📄 **`timer0_priv.h`** — Timer0 private macros.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>TIMER1/</b> (Timer/Counter 1 Driver)</summary>

* 📄 **`timer1.c`** — Implementation of Timer1 functions.
* 📄 **`timer1.h`** — Timer1 functions declarations and macro definitions.
* 📄 **`timer1_cfg.h`** — Timer1 Modes configurations.
* 📄 **`timer1_priv.h`** — Timer1 private macros.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>USART/</b> (Universal Synchronous/Asynchronous Receiver/Transmitter Driver)</summary>

* 📄 **`usart.c`** — Implementation of usart functions.
* 📄 **`usart.h`** — usart functions declarations.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>SPI/</b> (Serial Peripheral Interface Driver)</summary>

* 📄 **`spi.c`** — Implementation of spi functions.
* 📄 **`spi.h`** — spi functions declarations and macro definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>TWI (I2C)/</b> (Two-Wire Interface Driver)</summary>

* 📄 **`twi.c`** — Implementation of twi functions.
* 📄 **`twi.h`** — twi functions declarations and error status enum.
* 📄 **`twi_cfg.h`** — twi frequency and clock configurations.
* 📄 **`twi_priv.h`** — twi private macros.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>EEPROM/</b> (Electrically Erasable Programmable Read-Only Memory [Internal])</summary>

* 📄 **`eeprom.c`** — Implementation of eeprom functions.
* 📄 **`eeprom.h`** — eeprom functions declarations.
</details>
</details>

<details>
<summary>📂 <b>HAL</b> (Hardware Abstraction Layer)</summary>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>CLCD/</b> (Character LCD Driver)</summary>

* 📄 **`CLCD_prog.c`** — Character LCD Functions implementations.
* 📄 **`CLCD_int.h`** — Character LCD Functions declarations.
* 📄 **`CLCD_config.h`** — Interface pin routing layout.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>KPAD/</b> (Matrix Keypad Driver)</summary>

* 📄 **`KPAD_prog.c`** — Matrix keypad Functions implementations.
* 📄 **`KPAD_int.h`** — Matrix keypad Functions declarations.
* 📄 **`KPAD_config.h`** — Row/column matrix pins.
* 📄 **`KPAD_priv.h`** — Row/column matrix key numbers/definitions.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>DCMOTOR/</b> (DC Motor Driver)</summary>

* 📄 **`dcmotor_.c`** — DC Motor Functions implementations.
* 📄 **`dcmotor_.h`** — DC Motor Functions declarations.
* 📄 **`dcmotor_cfg.h`** — Motor direction pins and PWM channel configurations.
* 📄 **`dcmotor_priv.h`** — DC Motor private macros.
</details>

<details>
<summary>&nbsp;&nbsp;&nbsp;&nbsp;📂 <b>EEPROM_EXT/</b> (Electrically Erasable Programmable Read-Only Memory [External])</summary>

* 📄 **`eeprom_ext.c`** — Implementation of eeprom functions.
* 📄 **`eeprom_ext.h`** — eeprom functions declarations.
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



## 📌 API Reference (MCAL)

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
// allows user to enable Global interrupts

void GIE_voidDisableGlobalInterrupt(void);
// allows user to disable Global interrupts
```
### EXTI Driver (`exti.h`)
```c
void EXTI_voidEnableInt(u8 Copy_u8Int);
// allows user to enable an interrupt pin

void EXTI_voidDisableInt(u8 Copy_u8Int);
// allows user to disable an interrupt pin

void EXTI_voidSetSenseControl(u8 Copy_u8Int,u8 Copy_u8SC);
// allows user to control what causes an interrupt ex: Falling edge

void EXTI_INT0_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
// allows user to control Interrupt 0 routine

void EXTI_INT1_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
// allows user to control Interrupt 1 routine

void EXTI_INT2_CallBack(void(*Copy_ptrvoidCallBackFunc)(void));
// allows user to control Interrupt 2 routine
```
### ADC Driver (`adc.h`)
```c
void ADC_voidInit(void);
// initializes the ADC

u16 ADC_u16ReadValue(u8 Copy_u8Channel);
// allows user to read the digital value from the ADC
```
### Timer0 Driver (`timer0.h`)
```c
void TIMER0_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode);
// initializes timer0 and allows user to choose the clock pre-scaler and Mode

void TIMER0_voidSetPreloadVal(u8 Copy_u8Val);
// allows user to preload timer0 (count from an offset)

void TIMER0_voidSetOCRVal(u8 Copy_u8Val);
// allows user to set the OCR0 value

void TIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle);
// allows the user to set the pulse duty cycle

void TIMER0_voidSetCallBackOCR(void (*Copy_ptrvoidCallBackFunc)(void));
// allows user to control timer0 (output compare) Interrupt routine

void TIMER0_voidSetCallBackOVF(void (*Copy_ptrvoidCallBackFunc)(void));
// allows user to control timer0 (overflow) Interrupt routine
```
### Timer1 Driver (`timer1.h`)
```c
void TIMER1_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8Mode);
// initializes timer1 and allows user to choose the clock pre-scaler and Mode

void TIMER1_voidSetPreloadVal(u16 Copy_u16Val);
// allows user to preload timer1 (count from an offset)

u16  TIMER1_u16GetTimerVal(void);
// allows user to read the current count value inside timer1

void TIMER1_voidSetOCR1AVal(u16 Copy_u16Val);
// allows user to set the OCR1A value

void TIMER1_voidSetOCR1BVal(u16 Copy_u16Val);
// allows user to set the OCR1B value

void TIMER1_voidSetICR1Val(u16 Copy_u16Val);
// allows user to set the ICR1 value (TOP ceiling for PWM/CTC modes)

void TIMER1_voidSetDutyCycleA(u8 Copy_u8DutyCycle);
// allows user to set the pulse duty cycle (0-100%) on Channel A (OC1A / PD5)

void TIMER1_voidSetDutyCycleB(u8 Copy_u8DutyCycle);
// allows user to set the pulse duty cycle (0-100%) on Channel B (OC1B / PD4)

void TIMER1_voidICUInit(u8 Copy_u8Edge);
// initializes the Input Capture Unit (ICU) with a trigger edge and enables its interrupt

void TIMER1_voidICUSetEdge(u8 Copy_u8Edge);
// allows user to set the ICU trigger edge (Rising or Falling)

u16  TIMER1_u16GetICR1Val(void);
// allows user to read the captured timestamp value from ICR1

void TIMER1_voidICUEnableInterrupt(void);
// allows user to enable the Input Capture (ICU) interrupt

void TIMER1_voidICUDisableInterrupt(void);
// allows user to disable the Input Capture (ICU) interrupt

void TIMER1_voidSetCallBackOVF(void (*Copy_ptrvoidCallBackFunc)(void));
// allows user to control timer1 (overflow) Interrupt routine

void TIMER1_voidSetCallBackCOMPA(void (*Copy_ptrvoidCallBackFunc)(void));
// allows user to control timer1 (output compare A) Interrupt routine

void TIMER1_voidSetCallBackCOMPB(void (*Copy_ptrvoidCallBackFunc)(void));
// allows user to control timer1 (output compare B) Interrupt routine

void TIMER1_voidSetCallBackICU(void (*Copy_ptrvoidCallBackFunc)(void));
// allows user to control timer1 (input capture) Interrupt routine
```
### USART/UART Driver (`usart.h`)
```c
void UART_voidInit(void);
// initializes USART/UART

void UART_voidSend(u8 Copy_u8data);
// allows user to send data

u8 UART_u8Receive(void);
// allows user to receive data

void UART_voidSendString(const u8 *Copy_u8Str);
// allows user to send a string
```
### SPI Driver (`spi.h`)
```c
void SPI_voidMasterInit(void);
// initializes SPI Master

u8 SPI_u8MasterSend(u8 Copy_u8data);
// allows user to send/receive data as Master

void SPI_voidSlaveInit(void);
// initializes SPI Slave

u8 SPI_u8SlaveSend(u8 Copy_u8data);
// allows user to send/receive data as Slave
```
### TWI/I2C Driver (`twi.h`)
```c
void TWI_MasterInit(void);
// initializes TWI/I2C Master

u8 TWI_u8SendStartCondition(void);
// allows user to send start contidtion

u8 TWI_u8SendRepStartCondition(void);
// allows user to send repeated start contidtion

u8 TWI_u8SendStopCondition(void);
// allows user to send stop contidtion

u8 TWI_u8MasterSendSlaveAddWithRead(u8 Copy_u8SLA);
// allows user to send the slave address and read bit

u8 TWI_u8MasterSendSlaveAddWithWrite(u8 Copy_u8SLA);
// allows user to send the slave address and write bit

u8 TWI_u8MasterSendData(u8 Copy_u8Data);
// allows user to send data as Master

u8 TWI_u8MasterReceiveData(u8* Copy_u8Data);
// allows user to receive data as Master

void TWI_SlaveInit(void);
// initializes TWI/I2C Slave

u8 TWI_u8SlaveSendData(u8 Copy_u8Data);
// allows user to send data as Slave

u8 TWI_u8SlaveReceiveData(u8* Copy_u8Data);
// allows user to receive data as Slave
```
### EEPROM (`eeprom.h`)
```c
void EEPROM_voidWriteDataByte(u16 Copy_u16adress, u8 Copy_u8data);
// allows user to send (store) data in the internal EEPROM

u8 EEPROM_voidReadDataByte(u16 Copy_u16adress);
// allows user to Read data in the internal EEPROM
```
## 📌 API Reference (HAL)
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
### Keypad Subsystem (`KPAD_int.h`)
```c
void KPAD_voidInit (void);
// initializes the Keypad

u8 KPAD_u8GetKeyPressed (void);
// allows the user to get the pressed key
```
### EEPROM_EXT (`eeprom_ext.h`)
```c
void EEPROM_EXT_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);
// allows user to send (store) data in the external EEPROM

u8 EEPROM_EXT_u8ReadDataByte(u16 Copy_u16LocationAddress);
// allows user to Read data in the external EEPROM
```
### DCMOTOR Driver (`dcmotor.h`)
```c
void DCMOTOR_voidInit(void);
// initializes the motors

void DCMOTOR_voidRotateCW(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent);
// allows user to Rotate one motor Clock-Wise

void DCMOTOR_voidRotateCCW(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent);
// allows user to Rotate one motor Counter Clock-Wise

void DCMOTOR_voidSetSpeed(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent);
// allows user to control motor speed

void DCMOTOR_voidStop(u8 Copy_u8MotorId);
// allows user to stop one motor

void DCMOTOR_voidMoveForward(u8 Copy_u8SpeedPercent);
// allows user to move both motors Forward (Clock-Wise)

void DCMOTOR_voidMoveBackward(u8 Copy_u8SpeedPercent);
// allows user to move both motors Backward (Counter Clock-Wise)

void DCMOTOR_voidTurnRight(u8 Copy_u8SpeedPercent);
// allows user to turn right (right motor -> ccw , left motor -> cw)

void DCMOTOR_voidTurnLeft(u8 Copy_u8SpeedPercent);
// allows user to turn left (right motor -> cw , left motor -> ccw)

void DCMOTOR_voidStopAll(void);
// allows user to stop all motors
```