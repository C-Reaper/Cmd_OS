#ifndef STRING_H
#define STRING_H

#include <stddef.h>

void *memset(void *dest, int val, size_t count);
void *memcpy(void *dest, const void *src, size_t count);
size_t strlen(const char *str);
int strcmp(const char *a, const char *b);

#endif
