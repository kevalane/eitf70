#define PORTB 0x05;
#define DDRB 0x04;
#define decr 158

; Replace with your application code
start:
	;rjmp end
    ;init led
	ldi r20, 0b11111111
	out DDRB, r20

	ldi r20, 0b00000100
	out PORTB, r20
	call delay
	ldi r20, 0b0
	out PORTB, r20
	call delay
    rjmp start
end:
	rjmp end

delay:
	;ldi r21, 0b00011000
	ldi r21, decr
	l1:
		;ldi r22, 0b01101010
		ldi r22, decr
		l2:
			ldi r23, decr
			l3:
				dec r23
				cpi r23, 0
				brne l3
				
				dec r22
				cpi r22, 0
				brne l2

				dec r21
				cpi r21, 0
				brne l1
	ret
