#pragma once

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

void mx_pop_front(t_list **list);

