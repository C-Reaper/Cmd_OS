#include <mm/memory.h>
#include <string.h>  // unsere eigene string.h

#define KERNEL_HEAP_START 0x100000   // ab 1MB
#define KERNEL_HEAP_SIZE 0x100000    // 1 MB

static uint8_t* heap_base;
static size_t heap_offset;

void memory_init(void)
{
    heap_base = (uint8_t*)KERNEL_HEAP_START;
    heap_offset = 0;
}

void* kmalloc(size_t size)
{
    void* ptr = heap_base + heap_offset;
    heap_offset += size;

    // simple alignment auf 8 Bytes
    if (heap_offset % 8)
        heap_offset += 8 - (heap_offset % 8);

    if (heap_offset >= KERNEL_HEAP_SIZE)
        return 0; // Out of memory

    return ptr;
}

void kfree(void* ptr)
{
    // keine Implementierung jetzt – später
    (void)ptr;
}
