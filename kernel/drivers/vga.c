#include <stdint.h>
#include <stddef.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static uint16_t* const VGA_MEMORY = (uint16_t*)0xB8000;

static uint8_t row = 0;
static uint8_t col = 0;
static uint8_t color = 0x0F;

static inline uint16_t vga_entry(char c)
{
    return (uint16_t)c | ((uint16_t)color << 8);
}

void vga_init(void)
{
    row = 0;
    col = 0;

    for (uint16_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (uint16_t x = 0; x < VGA_WIDTH; x++)
        {
            VGA_MEMORY[y * VGA_WIDTH + x] = vga_entry(' ');
        }
    }
}

static void vga_putchar(char c)
{
    if (c == '\n')
    {
        col = 0;
        row++;
        return;
    }

    VGA_MEMORY[row * VGA_WIDTH + col] = vga_entry(c);
    col++;

    if (col >= VGA_WIDTH)
    {
        col = 0;
        row++;
    }

    if (row >= VGA_HEIGHT)
    {
        row = 0;   // kein Scrollen – einfach Reset
    }
}

void vga_write(const char* str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        vga_putchar(str[i]);
}

