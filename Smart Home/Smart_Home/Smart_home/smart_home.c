/*
 * smart_home.c
 *
 *  Created on: Oct 6, 2024
 *      Author: MOH
 */
#include "lcd.h"
#include "adc.h"
#include "buzzer.h"
#include "flame.h"
#include "ldr.h"
#include "led.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "pwm.h"
uint8 temperature =0;
uint16 light_Intensity=0;
void light_control(void){
	light_Intensity = LDR_getLightIntensity();
    if (light_Intensity <= 15) {
        // Turn ON all LEDs (Red, Green, Blue)
        LED_on(LED_RED);
        LED_on(LED_GREEN);
        LED_on(LED_BLUE);
    }
    else if (light_Intensity > 15 && light_Intensity <= 50) {
        // Turn ON Red and Green LEDs, Turn OFF Blue LED
        LED_on(LED_RED);
        LED_on(LED_GREEN);
        LED_off(LED_BLUE);
    }
    else if (light_Intensity > 50 && light_Intensity <= 70) {
        // Turn ON only Red LED, Turn OFF Green and Blue LEDs
        LED_on(LED_RED);
        LED_off(LED_GREEN);
        LED_off(LED_BLUE);
    }
    else {
        // Turn OFF all LEDs
        LED_off(LED_RED);
        LED_off(LED_GREEN);
        LED_off(LED_BLUE);
    }

}
void FanControl(void) {
	temperature =LM35_getTemperature();
    if (temperature >= 40) {
        DcMotor_Rotate(CW, 100);  // Fan ON at 100% speed
    } else if (temperature >= 35) {
        DcMotor_Rotate(CW, 75);   // Fan ON at 75% speed
    } else if (temperature >= 30) {
        DcMotor_Rotate(CW, 50);   // Fan ON at 50% speed
    } else if (temperature >= 25) {
        DcMotor_Rotate(CW, 25);   // Fan ON at 25% speed
    } else {
        DcMotor_Rotate(STOP, 0);  // Fan OFF
    }
}
void lcd(void){
    LCD_moveCursor(1 , 5);
    LCD_intgerToString( (uint32) temperature) ;
    LCD_displayStringRowColumn(1,7," ");
    if( temperature < 25 )
    {
        LCD_displayStringRowColumn( 0 , 7 , "OFF" );
    }
    else
    {
        LCD_displayStringRowColumn( 0 , 7 , "ON " );
    }

    LCD_moveCursor(1,12);
    if(light_Intensity == 100 )
    {
        LCD_intgerToString( (uint32)light_Intensity ) ;
    }
    else
    {
        LCD_intgerToString( (uint32)light_Intensity ) ;
        LCD_displayCharacter(' ');
    }
    LCD_moveCursor(1,15);
    LCD_displayCharacter('%');

    if (FlameSensor_getValue() )
    {
        LCD_clearScreen();
        LCD_displayString("Critical alert!");
        Buzzer_on();
        while (FlameSensor_getValue() );  /* wait until the flame is off */
        Buzzer_off();
        LCD_clearScreen() ;
        LCD_displayStringRowColumn(0,0,"Fan is  ");
        LCD_displayStringRowColumn(1,0,"Temp=   LDR=    ");
        LCD_moveCursor(1 , 5);
        LCD_intgerToString( (uint32) temperature );
        LCD_moveCursor(1 , 12);
        LCD_intgerToString( (uint32) light_Intensity);
        LCD_moveCursor(1 , 15);
        LCD_displayCharacter('%');


    }
}
int main(void){
	DcMotor_Init();
	LEDS_init();
	LCD_init();
	FlameSensor_init();
	Buzzer_init();
	Timer0_INIT_PWM();
    LCD_displayStringRowColumn(0,0,"Fan is  ");
    LCD_displayStringRowColumn(1,0,"Temp=   LDR=    ");
	while(1){
		light_control();
		FanControl();
		lcd();



	}
}

