 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use macros like SET_BIT */

void ADC_init(void)
{
	ADMUX = (1 << REFS1) | (1 << REFS0);  // Set internal reference voltage to 2.56V
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set prescaler to F_CPU/128
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |= channel_num;

	SET_BIT(ADCSRA, ADSC);
	while(BIT_IS_CLEAR(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);

	return ADC;
}

