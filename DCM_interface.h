/*
 * DCM_interface.h
 *
 * Created: 2/12/2026 3:04:13 PM
 *  Author: hamza
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

void DCM_voidInit(u8 copy_u8MotorId);
void DCM_voidOn(u8 copy_u8MotorId, u8 copy_u8Dir);
void DCM_voidOff(u8 copy_u8MotorId );

void DCM_voidInitWithCtrlSpeed(u8 copy_u8MotorId);
void DCM_voidOnWithCtrlSpeed(u8 copy_u8MotorId, u8 copy_u8Dir, u8 copy_u8Speed);
void DCM_voidOffWithCtrlSpeed(u8 copy_u8MotorId);



#endif /* DCM_INTERFACE_H_ */