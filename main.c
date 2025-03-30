#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT1_vect) {
	if (OCR0A == 0xFA) {
		OCR0A = 0x19;
	}
	else { 
		OCR0A += 0x19;
	}
}

void setupPWM() {
	// Set PD6 as an output (enable OC0A pin)
	DDRD |= (1 << 6);
	
	// Set OCR0A to 0x19
	OCR0A = 0x19;
	// Select CLKio/1024
	TCCR0B |= 0x05;
	TCCR0B &= ~(1 << 1);
	
	// COM0 1:0 = 10; Clear OC0A on match and set it at BOTTOM
	TCCR0A &= ~(1 << 6);
	TCCR0A |= (1 << 7);
	
	// Set WGM 2:0 = 011 to enable Fast PWM with TOP = 0xFF
	TCCR0A |= (1 << 0);	
	TCCR0A |= (1 << 1);
	TCCR0B &= ~(1 << 3);	
}

void setupSwitch() {
	// Set PD3 (INT1 pin) as an input
	DDRD &= ~(1 << 3);

	// Disable internal pull-up resistor of PD3
	PORTD &= ~(1 << 3);
	
	// ISC1 1:0 = 11; Rising edge of INT1 generates Int. Req.
	EICRA |= (1 << 3);
	EICRA |= (1 << 2);
	
	// Enable External Interrupt Request 1
	EIMSK |= 0x2;
	
	// Enable global interrupts
	sei();
}

void main(void) {
	setupPWM();
	setupSwitch();
	
	while (1);
}	
