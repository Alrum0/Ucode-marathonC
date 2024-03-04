#include "list.h"

char mx_tolower(char c) {
    if ('A' <= c && c <= 'Z') {
        c += 'a' - 'A';
    }

    return c;
}

