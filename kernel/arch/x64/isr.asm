BITS 64
global isr_page_fault
extern page_fault_handler

isr_page_fault:
    push rbp
    mov rbp, rsp

    ; Page Fault pushed error code automatically
    ; Stack layout already correct

    call page_fault_handler

    pop rbp
    add rsp, 8      ; skip error code
    iretq
