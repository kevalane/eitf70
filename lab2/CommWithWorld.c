#include <avr/io.h>
#include <stdint.h>

void usart0_init() {
	// set baud rate to 9600 on a 16mhz proc
	UBRR0 = 103;
	
	// init receiver and transmitter, bit 3 trans, bit 4 rec pp.260
	UCSR0B = 0b00011000;
	
	// set data length and bits
	UCSR0C = 0b00000110;
}

uint8_t usart0_receive() {
	// check if bit 8 is 1, means unread data in buffer
	while (!(UCSR0A & 0b10000000));
	return UDR0;
}

void usart0_transmit(uint8_t data) {
	// check so data register empty, bit 5
	while (!(UCSR0A & 0b00100000));
	
	//send data;
	UDR0 = data;
	
	// wait for transmit complete
	while(!(UCSR0A & 0b01000000));
}

int main(void)
{
	DDRB |= 0x08;
	usart0_init();
    /* Replace with your application code */
    while (1) 
    {
		uint8_t receiveData = usart0_receive();
		// ascii 49 is 1 character
		if (receiveData == 49) {
			PORTB |= 0x08;
		} else if (receiveData == 48) {
			PORTB = 0x25;
		}
		usart0_transmit(receiveData);
    }
}
