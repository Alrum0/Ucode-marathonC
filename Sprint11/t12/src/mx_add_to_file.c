#include "../inc/list.h"

bool mx_add_to_file(const char *filename, const char *artist, const char *name) {
    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);

    if (fd == -1) {
        return false;
    }

    mx_write_into_file(fd, artist);
    mx_write_into_file(fd, ",");
    mx_write_into_file(fd, name);
    mx_write_into_file(fd, "\n");

    close(fd);

    return true;
}

