#include "../inc/list.h"

void mx_foreach_list(t_list *list, void (*f)(t_list *node)) {
    if (list == NULL || f == NULL) {
        return;
    }

    t_list *current_node = list;

    while (current_node != NULL) {
        t_list *temp = current_node->next;
        f(current_node);
        current_node = temp;
    }
}

