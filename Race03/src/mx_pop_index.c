#include "../inc/list.h"

void mx_pop_index(t_list **list, int index) {
    if (list == NULL) {
        return;
    }

    if (index <= 0) {
        mx_pop_front(list);
        return;
    }

    t_list *current_node = *list;

    if (current_node == NULL) {
        return;
    }

    if (current_node->next == NULL) {
        free(current_node);
        *list = NULL;
        return;
    }

    for (int i = 1; i < index && current_node->next->next != NULL; i++) {
        current_node = current_node->next;
    }

    t_list *temp = current_node->next->next;
    free(current_node->next);
    current_node->next = temp;
}

