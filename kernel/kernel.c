/*

Kernel
├── arch/x86_64/        (CPU, GDT, IDT, Paging)
├── mm/                 (Memory Manager)
├── sched/              (Scheduler)
├── proc/               (Prozesse)
├── fs/                 (VFS + Filesystem)
├── drivers/            (Keyboard, Disk, etc.)
├── sys/                (Syscalls)
└── net/                (später)

*/

#include <vga.h>
#include <string.h>

void kmain(void){
    //vga_init();
    //const char *msg = "Kernel gestartet.";
    //vga_write(msg);

    volatile char* test = (char*)0xB8000;
    test[0] = 'X';
    test[1] = 0x07;
    while (1);

    //if (strcmp(msg, "Kernel gestartet.") == 0)
    //    vga_write("\nString funktioniert.");
}
