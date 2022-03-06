#define STACK_H 0x3e
#define STACK_L 0x3d
#define N_ALLOC 5
#define DDRA 0x01
#define PINA 0x00

; Replace with your application code
start:
	call button_init
	inf:
		call alloc_mem
		rjmp inf

end:
	rjmp end

button_init:
	push r16
	; set ddra to read
	ldi r16, 0b00000000
	out DDRA, r16
	pop r16
	ret

alloc_mem:
	; prologue
	push r21 ; used for button pinA
	push r22 ; used for for loop

	push r28 ; used for stackpointer
	push r29 ; used for stackpointer
	in r28, STACK_L
	in r29, STACK_H
	sbiw Y, N_ALLOC
	out STACK_L, r28
	out STACK_H, r29

	; body
	ldi r22, N_ALLOC ; set it to 5 for loop
	loop:
		in r21, PINA
		adiw Y, 1 ; add space to stack
		st Y, r21
		dec r22
		cpi r22, 0
		brne loop
	; end body

	; epilogue
	in r28, STACK_L
	in r29, STACK_H
	adiw Y, N_ALLOC
	out STACK_L, r28
	out STACK_H, r29
	pop r29
	pop r28
	pop r22;
	pop r21;
	ret
