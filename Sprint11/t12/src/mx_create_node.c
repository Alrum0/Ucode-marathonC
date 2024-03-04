#include "list.h"

t_list *mx_create_node(char *artist, char *name) {
    t_list *new_node = (t_list*)malloc(sizeof(t_list));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->artist = artist;
    new_node->name = name;
    new_node->next = NULL;

    return new_node;
}

