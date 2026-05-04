/*
 * AC_config.h
 *
 * Created: 2/27/2026 11:15:04 PM
 *  Author: hamza
 */ 


#ifndef AC_CONFIG_H_
#define AC_CONFIG_H_

/* Ultrasonic Sensor */
#define ULTRASONIC_TRIGGER_PORT   DIO_PORTD
#define ULTRASONIC_TRIGGER_PIN    DIO_PIN6
#define ULTRASONIC_ECHO_PORT      DIO_PORTD
#define ULTRASONIC_ECHO_PIN       DIO_PIN7

/* Servo Motor (PWM1 Channel 1A) */
#define SERVO_PORT                DIO_PORTD
#define SERVO_PIN                 DIO_PIN5

/* DC Motors (L293D) */
#define DCM_MOTOR_LEFT            DCM_MOTOR_A
#define DCM_MOTOR_RIGHT           DCM_MOTOR_B

#endif /* AC_CONFIG_H_ */