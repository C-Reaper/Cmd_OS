#include <stdint.h>

static volatile uint16_t* vga = (uint16_t*)0xB8000;

void kernel_main(void) {
    const char* msg = "Hello from my x86_64 kernel!";
    for (int i = 0; msg[i]; i++) {
        vga[i] = (0x0F << 8) | msg[i];
    }
}
