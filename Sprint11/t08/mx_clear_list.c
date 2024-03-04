#include <stdlib.h>

#include "list.h"

void mx_clear_list(t_list **list) {
    t_list *head = *list;

    t_list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    *list = NULL;
}

