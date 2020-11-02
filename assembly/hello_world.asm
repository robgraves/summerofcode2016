; Hello world in assembly
;
;
; Author: Matthew Page
; Date: 11/01/2020
;
; Refererence unistd.h
;
; commands to assemble and link?:
; nasm -f elf32 -o hello_world.0 hello_world.asm
; ld -m elf_i386 -o hello_world hello_world.o

global _start

section .text:

_start:
    mov eax, 0x4                        ; use the write syscall
    mov ebx, 1                          ; use stdout as the fd (file descriptor)
    mov ecx, message                    ; use message as the buffer
    mov edx, message_length             ; and supply length
    int 0x80                            ; int is interrupt, 0x80 is syscall

    ; now gracefully exit
    
    mov eax, 0x1                        ; 0x1 is 1 in hex, 1 is for exit
    mov ebx, 0                          ; return value of 0 for success
    int 0x80



section .data:
    message: db "Hello World!", 0xA     ; defining message with db and 0xA is new line character
    message_length equ $-message        ; length of message is equal to message
