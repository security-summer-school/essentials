# Name: Jump Maze

## Vulnerability

Each letter of the flag is written to a register in `flag_maze.o`.
After each `mov` there is a `jmp` to another snippet that writes another letter.

## Exploit

Start from the first instruction, decode the bytes written to the registers and follow the `jmp`s to find the flag.
