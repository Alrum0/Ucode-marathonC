#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    if (list == NULL || *list == NULL || cmp == NULL) {
        return;
    }

    t_list *start = *list;
    t_list *previous_node;
    t_list *current_node;
    t_list *next_node;

    current_node = start;
    previous_node = current_node;

    while (current_node != NULL) {
        next_node = current_node->next;

        if (cmp(current_node->data, del_data)) {
            if (current_node == start) {
                free(current_node);
                start = next_node;
                current_node = next_node;
                continue;
            }
            else {
                previous_node->next = next_node;
                free(current_node);

                current_node = previous_node;
            }
        }

        previous_node = current_node;
        current_node = current_node->next;
    }

    *list = start;
}

