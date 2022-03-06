#include <avr/io.h>
#include <avr/interrupt.h>
#include "true_den.h"

volatile uint8_t numLions = 0;
uint8_t prevState = 0;
uint8_t stateOnEntry = 0;
volatile uint8_t counter = 0;

void init_interrupt() {
	PCMSK2 = 0b11000000;
	PCICR = 0b0100;
}

void init_leds() {
	DDRB = 0b11111111;
}

void init_sensors() {
	// what do we mean by input? if read only, 0s will suffice
	DDRC = 0b00000000;
}

uint8_t checkSensorOne() {
	uint8_t pinValue = PINC;
	pinValue = pinValue << 1;
	pinValue = pinValue >> 7;
	return pinValue;
}

uint8_t checkSensorTwo() {
	uint8_t pinValue = PINC;
	pinValue = pinValue >> 7;
	return pinValue;
}

uint8_t getState() {
	uint8_t state = 0b00;
	state |= checkSensorTwo() << 1;
	state |= checkSensorOne();
	return state;
}

void checkLions() {
	uint8_t currentState = getState();
	if (currentState != prevState) {
		// setting entry state allows lions to back out
		if (prevState == 0) stateOnEntry = currentState;
		if (currentState == 0) {
			// they have passed through
			if (prevState == 2 && stateOnEntry == 1) numLions++;
			if (prevState == 1 && stateOnEntry == 2) numLions--;
		}
		prevState = currentState;
	}
}


int main(void)
{
	init_sensors();
	init_leds();
	init_interrupt();
	security_system_init();
    sei();
	
	/* Replace with your application code */
    while (1) 
    {
		security_system_run();
    }
}

ISR(PCINT2_vect) {
	//counter++;
	checkLions();
	send_lions(numLions);
}
