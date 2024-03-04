#ifndef LIST_H
#define LIST_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct s_list {
    char *artist;
    char *name;
    struct s_list *next;
}              t_list;

void mx_printerr_list(t_list *head);
void mx_pop_front(t_list **list);
void mx_pop_back(t_list **list);
void mx_pop_index(t_list **list, int index);
void mx_push_back(t_list **list, char *artist, char *name);
void mx_push_front(t_list **list, char *artist, char *name);
void mx_push_index(t_list **list, char *artist, char *name, int index);
void mx_clear_list(t_list **list);
void mx_foreach_list(t_list *list, void (*f)(t_list *node));

int mx_list_size(t_list *list);
bool mx_overwrite_file_with_linked_list(const char *filename, t_list *head);

t_list *mx_csv_to_linked_list(const char *filename);
t_list *mx_create_node(char *artist, char *data);
t_list *mx_sort_list(t_list *list, bool (*cmp)(t_list *node1, t_list *node2));

void mx_printerror_int(int n);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);

void mx_write_into_file(int fd, const char *str);
char *mx_file_to_str(const char *filename);
bool mx_add_to_file(const char *filename, const char *artist, const char *name);
bool mx_remove_from_file(const char *filename, int index);
bool mx_sort_file(const char *filename, const char *option);
bool mx_print_file(const char *filename);

int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
int mx_atoi(const char *s);
bool mx_isspace(char c);
bool mx_isdigit(char c);
char mx_tolower(char c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strnew(int size);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_buffer_to_string(char buffer[], int bytes_to_read);

#endif







