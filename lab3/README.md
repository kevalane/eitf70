# Lab 3

## Sanity Check

### HA1: Number of clock cycles for 0.1s delay

Since T = 1/f, will require 1.6*10^6.

### HA2: Number of bits to count

21 bits, number is 0b110000110101000000000

### HA3: Number of registers for delay

Given we delay by arithmetic and breq when number in register
equals our 21 bit number, we'll need 3 registers of 8bits each.

### HA4: Write .asm for 0.1s delay

See delay subroutine in SanityCheck.asm

### HA5 Turn on LED 2

See start in SanityCheck.asm

### L1

To create arbitrary delays, use countDelay.c and change global double delayTime. Limitation is number of registers
used, in this case 3. Max delay becomes what can be generated using 255 as delay constant, roughly yielding a delay of 4.16s

### HA6 How to allocate 10 ints

See DynamicMemAlloc.asm, subroutine allocate_10

### L2 Value of stack opinter after alloc

Before: 16635 = 0x40FB
After: 16625 = 0x40F1

### H7 Where is value of index 3 if malloc array ending at 0x40e0

Assuming start @ 0x40ff, 0th element at 0x40ff, 1st at 0x40fe, 2nd at 0x40fd, 3rd at 0x40fc
given first element stored at highest memory address. If flipped, 0th is 0x40e0, 1st 0x40e1,
2nd 0x40e2, 3rd 0x40e3

### L3: What happens if we do not return memory

If we don't reset the stack pointer will result in subroutines returning back to the wrong address after execution.

If we don't deallocate memory our stack will continue to grow until it will collide with other content stored in RAM.

### L4: Need to store values in allocated array?

If we only need the values 'inside' the subroutine, locally, we do not. However, if we want to access the values
in another subroutine - i.e., other parts of the program, we would need to store it somewhere. In the current implementation,
it will be overwritten by another subroutine allocating the same amount of bytes.
