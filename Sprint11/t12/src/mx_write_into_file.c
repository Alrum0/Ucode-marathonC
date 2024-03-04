#include "list.h"

void mx_write_into_file(int fd, const char *str) {
    if (str == NULL) {
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        write(fd, &(str[i]), 1);
    }
}

