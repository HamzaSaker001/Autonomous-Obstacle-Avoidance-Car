/*
 * PWM1_interface.h
 *
 * Created: 2/14/2026 2:31:03 PM
 *  Author: hamza
 */ 


#ifndef PWM1_INTERFACE_H_
#define PWM1_INTERFACE_H_


                   /************************** APIs Prototypes **************************/

void PWM1_voidInitChannel1A(void);
void PWM1_voidGenrateChannel1A(u16 copy_u16FrequencyHZ,f32 copy_f32DutyCycle);
void PWM1_voidStop(void);

#endif /* PWM1_INTERFACE_H_ */