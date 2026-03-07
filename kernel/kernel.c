#include <vga.h>
#include <mm/memory.h>
#include <arch/x64/interrupts.h>

void kmain(void)
{
    vga_init();
    vga_write("Kernel gestartet...\n");

    memory_init();
    vga_write("Memory Manager bereit.\n");

    void* test = kmalloc(64);
    if (test)
        vga_write("kmalloc 64 Bytes erfolgreich.\n");

    idt_init();

    // absichtlich Page Fault zum Test
    volatile int* ptr = (int*)0xDEADBEEF;
    *ptr = 42;

    while(1);
}
