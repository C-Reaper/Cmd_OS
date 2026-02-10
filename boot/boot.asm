BITS 64
SECTION .multiboot
align 8
mb2_start:
    dd 0xe85250d6
    dd 0
    dd mb2_end - mb2_start
    dd -(0xe85250d6 + 0 + (mb2_end - mb2_start))
mb2_end:

SECTION .text
global _start
extern kernel_main

_start:
    mov rsp, stack_top
    call kernel_main
.hang:
    cli
    hlt
    jmp .hang

SECTION .bss
align 16
stack_bottom:
    resb 16384
stack_top:

