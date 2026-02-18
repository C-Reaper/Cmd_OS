#ifndef VGA_H
#define VGA_H

#include <stdint.h>

void vga_init(void);
void vga_write(const char* str);

#endif
