BITS 32

SECTION .multiboot
align 8
mb2_header_start:
    dd 0xe85250d6
    dd 0
    dd mb2_header_end - mb2_header_start
    dd -(0xe85250d6 + 0 + (mb2_header_end - mb2_header_start))
    dw 0
    dw 0
    dd 8
mb2_header_end:

SECTION .text
BITS 64
global _start
extern kmain

_start:
    mov rsp, stack_top
    and rsp, -16
    call kmain

.hang:
    cli
    hlt
    jmp .hang

SECTION .bss
align 16
stack_bottom:
    resb 16384
stack_top:
