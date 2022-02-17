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
