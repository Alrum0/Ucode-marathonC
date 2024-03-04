#include "../inc/list.h"

void mx_pop_front(t_list **list) {
    if (list == NULL) {
        return;
    }

    t_list *current_node = *list;

    if (current_node == NULL) {
        return;
    }

    *list = current_node->next;
    free(current_node);
}

