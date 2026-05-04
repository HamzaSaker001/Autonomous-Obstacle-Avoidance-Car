/*
 * DCM_config.h
 *
 * Created: 2/12/2026 3:04:29 PM
 *  Author: hamza
 */ 


#ifndef DCM_CONFIG_H_
#define DCM_CONFIG_H_

#define DCM_MOTOR_A                         1
#define DCM_MOTOR_B                         2
							               
#define DCM_MOTOR_A_EN_PORT                 DIO_PORTB
#define DCM_MOTOR_A_EN_PIN                  DIO_PIN3
							               
#define DCM_MOTOR_A_IN_PORT                 DIO_PORTC
#define DCM_MOTOR_A_IN1_PIN                 DIO_PIN3
#define DCM_MOTOR_A_IN2_PIN                 DIO_PIN4
							               
#define DCM_MOTOR_B_EN_PORT                 DIO_PORTD
#define DCM_MOTOR_B_EN_PIN                  DIO_PIN4
				  			               
#define DCM_MOTOR_B_IN_PORT                 DIO_PORTC
#define DCM_MOTOR_B_IN1_PIN                 DIO_PIN5
#define DCM_MOTOR_B_IN2_PIN                 DIO_PIN6
							               
#define DCM_CW                              0
#define DCM_CCW                             1

#endif /* DCM_CONFIG_H_ */