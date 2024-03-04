#include <stdlib.h>

#include "list.h"

void mx_pop_index(t_list **list, int index) {
    if (list == NULL || *list == NULL) {
        return;
    }

    if (index <= 0) {
        mx_pop_front(list);
        return;
    }

    int current_index = 0;
    t_list *current_node = *list;

    while (current_index != index - 1 && current_node->next != NULL) {
        current_index++;
        current_node = current_node->next;
    }

    if (current_node->next == NULL) {
        mx_pop_back(list);
        return;
    }

    t_list *target_node = current_node->next;
    current_node->next = target_node->next;
    free(target_node);
}

