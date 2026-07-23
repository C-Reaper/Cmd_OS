; ============================================================================
; PongOS
; paging.asm
;
; Erstellt:
;   - PML4
;   - PDPT
;   - Page Directory
;
; Identity Mapping der ersten 1 GiB mit 2 MiB Pages.
; ============================================================================

BITS 32

global paging_init
global pml4_table

section .bss

align 4096
pml4_table:
    resq 512

align 4096
pdpt_table:
    resq 512

align 4096
page_directory:
    resq 512

section .text

paging_init:

    ; -------------------------------------------------------
    ; PML4[0] -> PDPT
    ; -------------------------------------------------------

    mov eax, pdpt_table
    or eax, 0x03            ; Present | Writable
    mov [pml4_table], eax
    mov dword [pml4_table+4], 0

    ; -------------------------------------------------------
    ; PDPT[0] -> Page Directory
    ; -------------------------------------------------------

    mov eax, page_directory
    or eax, 0x03
    mov [pdpt_table], eax
    mov dword [pdpt_table+4], 0

    ; -------------------------------------------------------
    ; Identity Map:
    ; 512 * 2 MiB = 1 GiB
    ; -------------------------------------------------------

    xor ecx, ecx

.map_loop:

    mov eax, ecx

    shl eax, 21             ; ecx * 2 MiB

    or eax, 0x83            ; Present | Write | Huge Page

    mov [page_directory + ecx*8], eax
    mov dword [page_directory + ecx*8 + 4], 0

    inc ecx
    cmp ecx, 512
    jne .map_loop

    ret