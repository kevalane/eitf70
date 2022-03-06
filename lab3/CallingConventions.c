#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

extern void led_init();
extern void button_init();
extern void led_on(char);
extern void led_off(char);
extern char check_button(char);

int main(void)
{
	led_init();
	button_init();
	
	uint8_t led = 0b00000010;
	uint8_t button = 0b00000010;
	
    /* Replace with your application code */
    while (1) 
    {
		if (check_button(button)) {
			led_on(led);
			_delay_ms(5000);
			led_off(led);	
		}
    }
}
