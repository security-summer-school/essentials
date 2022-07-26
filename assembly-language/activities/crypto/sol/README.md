# Name: Crypto

## Vulnerability

The function that decrypts and prints the flag is in the binary.

## Exploit

Just need to call `get_flag` from GDB either with `jump get_flag` or `set $pc=get_flag`.
