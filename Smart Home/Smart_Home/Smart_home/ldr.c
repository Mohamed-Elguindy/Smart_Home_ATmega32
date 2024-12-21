/*
 * ldr.c
 *
 *  Created on: Oct 5, 2024
 *      Author: MOH
 */
#include <avr/io.h>
#include "common_macros.h"
#include "gpio.h"
#include "ldr.h"
#include "adc.h"
uint16 LDR_getLightIntensity(void)
{
	ADC_init();
	uint16 adc_digital_value = (uint16)ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	uint16 ldr_value = (uint16)(((uint32)adc_digital_value*LDR_SENSOR_MAX_LIGHT_INTENSITY)/ADC_MAXIMUM_VALUE);

	return (ldr_value);
}

