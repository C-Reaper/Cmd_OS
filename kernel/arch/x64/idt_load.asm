BITS 64

; kernel/arch/x64/idt_load.asm
; Assembly-Stub zum Laden der IDT
global load_idt
section .text
load_idt:
    mov rax, rdi      ; rdi = &idt_ptr
    lidt [rax]        ; lade IDT
    ret
