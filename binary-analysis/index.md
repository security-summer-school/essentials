---
linkTitle: 09. Binary Analysis
type: docs
weight: 10
---

# Introduction

Objectives and rationale for the current session.

# Reminders and Prerequisites

- Information required for this section
- Commands / snippets that should be known, useful to copy-paste throughout the practical session

# Static Analysis

## strings

`strings` is used to find strings in a binary file - very intuitive.
It is the most basic static analysis tool available.
Before any other more complex analysis takes place, a `strings` can find many hidden secrets.

## file

`file` is another useful tool, not only for binary analysis.
But it should be used before any investigation, to make sure that the binary is a binary file, and not an archive.
It also shows if the executable is statically-linked (lots of strings, functions) or dynamically-linked.

### Counter-measures

For `strings` and `file` there is no counter-measure to hide the data that would be found by them.
That's why they are almost used first when analysing a binary.

## nm

`nm` is used to find **symbols** - variable names, function names, and their addresses.
It also shows where those symbols are placed: text (T or t), rodata (R or r), bss (B or b), etc.
[Here](https://www.thegeekstuff.com/2012/03/linux-nm-command/) you can find all the symbols' meaning.

The difference between capital-letter symbols and lowercase symbols is the following:
Capital-letter symbols are global, meaning they can be refferenced from another object files.
Example: object1.o has a global symbol named `global_var`.
object2.o can use `global_var`, if object1.o and object2.o are linked together.

### Counter-measures: Strip

`strip` removes all symbols from a binary file.
If a binary is stripped, `nm` becomes useless.

## objdump

`objdump` is a dissassembler.
It takes binary files and transforms them to hexadecimal values and, where possible, assembly language.
It is usefull in many cases: when we want to explore the sections of a program, when we want to see what a specific function does, or when we want to make sure that the binary won't crash more complex analysis tools (!).
`objdump` is a fast way to turn a binary file into more accessible format.

### Counter-measures

`objdump` is pretty good at what is must do.
It becomes less helpful if the binary is large, with multiple functions that call eachother and we have a hard time understanding the flow of the application.
That's why it is a bad idea, generally, to break down real-life applications with `objdump`.

## Ghidra

`Ghidra` is a decompiler: it turns a binary file into C code.
It also does function analysis, meaning it constructs a tree of function calls.
It is the best tool to understand what a binary does, without running it.

### Counter-measures

Unorthodox code, self-changing code, polymorphic code and other measures were taken by various people to counter Ghidra.
[This](https://www.youtube.com/watch?v=HlUe0TUHOIc&ab_channel=DEFCONConference) talk by Christopher Domas is one of the best examples of measures taken to counter Ghidra and other decompilers.

# Dynamic Analysis

## strace

`strace` shows system calls performed by a binary application.
That means opening any kind of file, reading and writing into files, `mprotect`s and other things.
It is useful to find out if the program does any changes to the system itself, or if it writes in some files.

## ltrace

`ltrace` shows calls to dynamic library functions, along with system calls.
It is similar to `strace`.

## gdb

GDB is the most powerful dynamic analysis tool available to the regular user.
It allows executing the code instruction by instruction, inspecting memory areas, changing memory areas, jumping to other pieces of code, that weren't executed normally.
GDB is best used when the user has knowledge about assembly language, which will be presented in the last 2 sessions.
For this session, GDB isn't required.

# Summary

- Sumamrizing session concepts
- Summarizing commands / snippets that are useful for tutorials, challenges (easy reference, copy-paste)

# Activities

## Challenge: Easy to Sopt

It's an easy challenge.
Really.

## Challenge: Packaging is Important

Someone delivered you a mysterious package.

## Challenge: Ghidra Killer

Some people just hate the people that use decompilers.
One of those people left you a binary, to investigate.

## Challenge: Spaghetti

Someone felt like cooking today. Can you find the flag?

# Further Reading

Any links or references to extra information.