# timer0nano
Using the 8-bit timer0 component included in the ATmega328P to generate PWM waves giving the illusion that the LED it's connected to changes brightness.

Note: This project is called 'timer0nano' because it was made on an Arduino Nano, but it should work on any ATmega328P chip.
# Usage

Connect PD6 pin to a LED

Connect PD3 to a switch

Run `make && make upload` (with sufficient permissions) to compile the program and flash on the chip

To increase LED 'brightness', press the switch.
