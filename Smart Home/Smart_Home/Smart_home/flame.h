/*
 * flame.h
 *
 *  Created on: Oct 5, 2024
 *      Author: MOH
 */

#ifndef FLAME_H_
#define FLAME_H_
#include "std_types.h"

#define FLAME_SENSOR_PORT_ID PORTD_ID
#define FLAME_SENSOR_PIN_ID  PIN2_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);
#endif /* FLAME_H_ */
