#include "../inc/list.h"

void mx_clear_list(t_list **list) {
    if (list == NULL) {
        return;
    }

    t_list *current_node = *list;

    while (current_node != NULL) {
        t_list *temp = current_node->next;
        free(current_node);
        current_node = temp;
    }

    *list = NULL;
}

