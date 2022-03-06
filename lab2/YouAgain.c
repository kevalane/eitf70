#include <avr/io.h>
#include <stdint.h>

int main(void)
{
	uint8_t *ledDDR = 0x24;
	uint8_t *ledPORT = 0x25;
	
	uint8_t *buttonPIN = 0x20;
	uint8_t *buttonDDR = 0x21;
	
	// init led
	*ledDDR |= 0b00001000;
	
	// init button
	*buttonDDR |= 0b000000;
	
	uint8_t now = 0;
	uint8_t prev = 0;
	uint8_t on = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		//*ledPORT |= 0b00001000;
		now = *buttonPIN;
		now = (now >> 2);
		if (now > prev) {
			//1 << 6
			
			if ((*buttonPIN >> 2) == 0b00001000) {
				if (on == 0) {
					*ledPORT |= 0x08;
					on = 1;
				} else {
					*ledPORT = 0x25;
					on = 0;
				}
				
			}
		}
		prev = now;
    }
}
