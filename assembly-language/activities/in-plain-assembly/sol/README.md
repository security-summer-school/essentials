# Name: In Plain Assembly

## Vulnerability

The binary verifies the flag byte by byte in the `verify_flag` function.
Before being verified, each byte is multiplied by 2 and then 1 is added to it.

## Exploit

Use Ghidra or GDB to decode the values of each letter `* 2 + 1` then do the math to find the original letters
