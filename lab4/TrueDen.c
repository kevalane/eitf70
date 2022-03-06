#include <avr/io.h>
#include <stdint.h>
#include "true_den.h"

uint8_t numLions = 0;
uint8_t prevState = 0;
uint8_t stateOnEntry = 0;

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
	security_system_init();
    /* Replace with your application code */
    while (1) 
    {
		send_lions(numLions);
		security_system_run();
		checkLions();
		PORTB = numLions;
    }
}
