# Computer Organization Lab 4

## Lion's Den

### HA1: How init I/O pins as input

Can init DDRC with 0s on pin 6 and 7, since we'll only need to read PINC value (not write).

### HA2: Code for lions den

See lionsDen.c

### LQ1: Required to wait for all states?

No, not really. Not needed to have logic for 11, 10 (or 01, dependent on direction).

Check if prev state 0, then record whether it reads 10, 01 and set global variable stateOnEntry to this.
Check this value when we receive another 0, to check whether the lion exited or not.

### LQ2: How fast can it go?

Theoretically, i guess if something moves faster than the CPU clock freq the sensor wouldn't have time
to register the movement.

### LQ3: Optional, revise code to allow backwards walking

The code takes this into account by checking both prevstate and entrystate upon exit.

### LQ4: Is it registered if moving fast?

No, it is not. Yes, kinda weird. Reason for not registering is probably the microprocessor is busy
executing another function, does not polling the state of sensors "all the time." Limitation when
polling is that we might miss an event if we are polling too many things simultaneously. 

### HA3: What PCINT?

PC6: PCINT22
PC7: PCINT23

### HA4: Enable PCINT?

`PCMSK2 = 0b11000000;`

### HA5: How to enable on PCICR?

`PCICR = 0b0100`

### LQ5: Value of counter?

The value of the counter is 4.

### LQ6: Disadvantage using interrupts

I guess we cannot 'not' interrupt, meaning if we currently execute a method that we really need to 
execute, and then an interrupt happens, issues arise. What happens if an interrupt is interrupted?
Generally difficult to get various pieces to work well with each other. Can we know what part is executed
before interrupt? I don't know, maybe with the stack pointer? is it affected? can we store our prev
location within the interrupt service?
