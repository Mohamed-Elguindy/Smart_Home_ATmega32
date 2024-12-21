/*
 * motor.h
 *
 *  Created on: Oct 5, 2024
 *      Author: MOH
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
typedef enum {
    STOP,
    CW,
    ACW
} DcMotor_State;
#define MOTOR_PORT_ID1 PORTB_ID
#define MOTOR_PORT_ID2 PORTB_ID

#define MOTOR_PIN_ID1 PIN0_ID
#define MOTOR_PIN_ID2 PIN1_ID

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
