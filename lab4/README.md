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


