global main
extern f1
extern f2
extern f3

section .text

main:
        ; Modify the required registers here so f1 prints a part of the flag.
        mov rdi, 5
        ; Do not change this line.
        call f1


        ; Modify the required registers here so f2 prints a part of the flag.
        mov rbx, 75
        mov r9, 0
        ; Do not change this line.
        call f2


        ; Modify the required registers here so f3 prints a part of the flag.
        mov r8, 2048
        ; Do not change these lines.
        call f3
        ret
