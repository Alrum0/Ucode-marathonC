#include "list.h"

void mx_printerr_list(t_list *head) {
    mx_printerr("Linked list content:\n");
    while (head != NULL) {
        mx_printerr(head->artist);
        mx_printerr(" - ");
        mx_printerr(head->name);
        mx_printerr("\n");
        head = head->next;
    }
}

