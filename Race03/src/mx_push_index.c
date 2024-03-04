#include "../inc/list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (list == NULL) {
        return;
    }

    if (index <= 0) {
        mx_push_front(list, data);
        return;
    }

    t_list *new_node = mx_create_node(data);

    if (new_node == NULL) {
        return;
    }

    t_list *current_node = *list;

    if (current_node == NULL) {
        *list = new_node;
        return;
    }

    for (int i = 1; i < index && current_node->next != NULL; i++) {
        current_node = current_node->next;
    }

    t_list *temp = current_node->next;
    current_node->next = new_node;
    new_node->next = temp;
}

