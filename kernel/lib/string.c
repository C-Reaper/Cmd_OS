#include <stddef.h>

void *memset(void *dest, int val, size_t count){
    unsigned char *ptr = dest;
    while (count--)
        *ptr++ = (unsigned char)val;
    return dest;
}

void *memcpy(void *dest, const void *src, size_t count){
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (count--)
        *d++ = *s++;
    return dest;
}

size_t strlen(const char *str){
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

int strcmp(const char *a, const char *b){
    while (*a && (*a == *b)){
        a++;
        b++;
    }
    return *(unsigned char *)a - *(unsigned char *)b;
}
