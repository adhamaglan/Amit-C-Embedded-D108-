/*
 * dcmotor.h
 *
 * Created: 11/14/2026 1:59:11 PM
 *  Author: adham
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_



#define DCMOTOR_RIGHT       0
#define DCMOTOR_LEFT        1

void DCMOTOR_voidInit(void);
void DCMOTOR_voidRotateCW(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent);
void DCMOTOR_voidRotateCCW(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent);
void DCMOTOR_voidSetSpeed(u8 Copy_u8MotorId, u8 Copy_u8SpeedPercent);
void DCMOTOR_voidStop(u8 Copy_u8MotorId);

void DCMOTOR_voidMoveForward(u8 Copy_u8SpeedPercent);
void DCMOTOR_voidMoveBackward(u8 Copy_u8SpeedPercent);
void DCMOTOR_voidTurnRight(u8 Copy_u8SpeedPercent);
void DCMOTOR_voidTurnLeft(u8 Copy_u8SpeedPercent);
void DCMOTOR_voidStopAll(void);

#endif /* DCMOTOR_H_ */