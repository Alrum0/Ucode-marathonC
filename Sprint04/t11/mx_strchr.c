#include <stddef.h> 

char* mx_strchr(const char* s, int c) {
    while (*s != '\0' && *s != c) {
        s++;
    }

    return (*s == c) ? (char*)s : NULL;
}

