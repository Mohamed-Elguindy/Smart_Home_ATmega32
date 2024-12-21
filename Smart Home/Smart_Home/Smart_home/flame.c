/*
 * flame.c
 *
 *  Created on: Oct 5, 2024
 *      Author: MOH
 */

#include <avr/io.h>
#include "common_macros.h"
#include "gpio.h"
#include "flame.h"

// Initialize the flame sensor pin as INPUT
void FlameSensor_init(void) {
    GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

// Read the value from the flame sensor
uint8 FlameSensor_getValue(void)
{

    uint8 flameSensorValue = 0 ;

    flameSensorValue = GPIO_readPin( FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID )  ;

    return flameSensorValue ;
}

