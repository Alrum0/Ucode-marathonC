#include "list.h"

bool mx_remove_from_file(const char *filename, int index) {
    t_list *list_head = mx_csv_to_linked_list(filename);

    if (list_head == NULL) {
        return false;
    }

    mx_pop_index(&list_head, index);

    bool success = mx_overwrite_file_with_linked_list(filename, list_head);

    mx_clear_list(&list_head);

    return success;
}

