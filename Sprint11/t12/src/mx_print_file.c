#include "list.h"

void print_linked_list(t_list *head) {
    int index = 0;

    while (head != NULL) {
        mx_printint(index);
        mx_printstr(". ");
        mx_printstr(head->artist);
        mx_printstr(" - ");
        mx_printstr(head->name);
        mx_printchar('\n');

        index++;
        head = head->next;
    }
}

bool mx_print_file(const char *filename) {
    t_list *list_head = mx_csv_to_linked_list(filename);

    if (list_head == NULL) {
        return false;
    }

    print_linked_list(list_head);

    mx_clear_list(&list_head);

    return true;
}
