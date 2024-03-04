#include "list.h"

bool mx_overwrite_file_with_linked_list(const char *filename, t_list *head) {
    int fd = open(filename, O_WRONLY | O_TRUNC);

    if (fd == -1) {
        return false;
    }

    while (head != NULL) {
        mx_write_into_file(fd, head->artist);
        mx_write_into_file(fd, ",");
        mx_write_into_file(fd, head->name);
        mx_write_into_file(fd, "\n");

        head = head->next;
    }

    close(fd);

    return true;
}

