#include <stdlib.h>

#include "list.h"

void mx_foreach_list(t_list *list, void (*f)(t_list *node)) {
    if (f == NULL) {
        return;
    }

    t_list *node = list;

    while (node != NULL) {
        t_list *next_node = node->next;
        f(node);
        node = next_node;
    }
}

