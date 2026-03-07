#include <arch/x64/interrupts.h>
#include <vga.h>

#define IDT_SIZE 256

static idt_entry_t idt[IDT_SIZE];
static idt_ptr_t idt_ptr;

// Assembly-Stub für lidt
extern void load_idt(uint64_t);

// Hilfsfunktion: IDT-Eintrag setzen
static void set_idt_entry(int n, uint64_t base, uint16_t selector, uint8_t flags)
{
    idt[n].offset_low  = base & 0xFFFF;
    idt[n].selector    = selector;
    idt[n].ist         = 0;
    idt[n].type_attr   = flags;
    idt[n].offset_mid  = (base >> 16) & 0xFFFF;
    idt[n].offset_high = (base >> 32) & 0xFFFFFFFF;
    idt[n].zero        = 0;
}

// Default Handler für alle Interrupts
void isr_default_handler(void)
{
    vga_write("Interrupt ausgelöst!\n");
    while(1); // anhängen, Kernel stoppt hier
}

// Page Fault Handler (Interrupt 14)
void page_fault_handler(void* frame)
{
    vga_write("Page Fault ausgelöst!\n");
    while(1); // Kernel stoppt hier
}

// IDT initialisieren
void idt_init(void)
{
    idt_ptr.limit = sizeof(idt_entry_t) * IDT_SIZE - 1;
    idt_ptr.base  = (uint64_t)&idt;

    // alle Einträge auf Default Handler
    for (int i = 0; i < IDT_SIZE; i++)
    {
        set_idt_entry(i, (uint64_t)isr_default_handler, 0x08, 0x8E);
    }

    // Page Fault Interrupt (14) auf speziellen Handler setzen
    set_idt_entry(14, (uint64_t)page_fault_handler, 0x08, 0x8E);

    // IDT laden
    load_idt((uint64_t)&idt_ptr);

    vga_write("IDT initialisiert.\n");
}
