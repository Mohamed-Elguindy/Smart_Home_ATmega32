# Smart Home Automation

## Overview
This project automates lighting and fan control based on environmental conditions using an ATmega32 microcontroller, LCD display, temperature sensor, LDR sensor, flame sensor, and motor control. The goal is to enhance convenience and energy efficiency by adjusting system settings according to changes in temperature and light levels.

## Features

### Automated Lighting
- Controls lighting intensity based on ambient light from the LDR sensor.

### Temperature-Controlled Fan
- Adjusts fan speed according to the temperature detected by the LM35 sensor.

### Fire Detection
- Detects fire through the flame sensor and triggers a buzzer alert.

### Real-Time Monitoring
- Displays temperature and light level data on the LCD.

## Hardware Components

### Microcontroller
- **ATmega32**

### Sensors
- **Temperature Sensor (LM35):** Monitors ambient temperature.
- **LDR (Light Dependent Resistor):** Measures ambient light levels.
- **Flame Sensor:** Detects presence of fire.

### Motor Control
- Controls fan speed using PWM for temperature-based adjustment.

### Output
- **LCD Display:** Shows real-time temperature and light level data.
- **LED Indicators:** LEDs for displaying varying light intensity levels.
- **Buzzer:** Sounds when the flame sensor detects a fire.

## System Overview
The ATmega32 microcontroller reads data from the temperature, light, and flame sensors, adjusting lighting and fan speed as needed. The LCD displays real-time environmental conditions. If fire is detected, a buzzer alarm sounds to alert users. This automation enhances both safety and convenience.

