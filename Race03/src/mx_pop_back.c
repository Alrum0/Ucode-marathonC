#include "../inc/list.h"

void mx_pop_back(t_list **list) {
    if (list == NULL) {
        return;
    }

    t_list *current_node = *list;

    if (current_node == NULL || current_node->next == NULL) {
        free(current_node);
        *list = NULL;
        return;
    }

    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    free(current_node->next);
    current_node->next = NULL;
}

