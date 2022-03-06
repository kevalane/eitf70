#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

uint8_t button_read_realiably() {
	uint8_t button_state = (PIND >> PIND7);
	if (button_state) {
		_delay_ms(15);
		button_state = (PIND >> PIND7);
		if (button_state) return 1;
	}
	return 0;
}

int main(void)
{
	
	// init led
	DDRB |= 0b00001000;
	
	// init button
	DDRD |= 0b000000;
	
	uint8_t now = 0;
	uint8_t prev = 0;
	uint8_t on = 0;
	
	/* Replace with your application code */
	while (1)
	{
		now = button_read_realiably();
		if (now > prev) {
			// is 0b00011111 if not pressed, 0b01011111 if pressed. Shift 7 (PIND7 = 7)
			//if (PIND >> PIND7)  {
			if (now) {
				if (on == 0) {
					PORTB |= 0x08;
					on = 1;
				} else {
					PORTB = 0x25;
					on = 0;
				}
			}
		}
		prev = now;
	}
}
