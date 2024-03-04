#include "list.h"

void mx_push_front(t_list **list, char *artist, char *name) {
    t_list *new_node = mx_create_node(artist, name);

    if (new_node == NULL) {
        return;
    }

    new_node->next = *list;

    *list = new_node;
}

