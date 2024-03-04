#include "list.h"

void mx_push_back(t_list **list, char *artist, char *name) {
    if (list == NULL) {
        return;
    }

    t_list *new_node = mx_create_node(artist, name);
    
    if (new_node == NULL) {
        return;
    }
    
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    
    t_list *current_node = *list;
    
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    
    current_node->next = new_node;
}

