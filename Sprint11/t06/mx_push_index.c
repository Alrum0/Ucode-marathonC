#include <stdlib.h>
#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (list == NULL) {
        return;
    }

    if (index <= 0 || *list == NULL) {
        mx_push_front(list, data);
        return;
    }

    int current_index = 0;
    t_list *current_node = *list;

    while (current_index != index - 1 && current_node->next != NULL) {
        current_index++;
        current_node = current_node->next;
    }

    if (current_index < index - 1 && current_node->next == NULL) {
        mx_push_back(&current_node, data);
        return;
    }

    t_list *new_node = mx_create_node(data);
    new_node->next = current_node->next;
    current_node->next = new_node;
}




