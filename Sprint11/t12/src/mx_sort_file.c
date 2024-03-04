#include "list.h"

char *word_to_lower(const char *word) {
    int word_length = mx_strlen(word);
    char *new_word = mx_strnew(word_length);

    for (int i = 0; i < word_length; i++) {
        new_word[i] = mx_tolower(word[i]);
    }

    return new_word;
}

bool sort_by_name(t_list *node1, t_list *node2) {
    char *name1_lower = word_to_lower(node1->name);
    char *name2_lower = word_to_lower(node2->name);

    bool compare_result = mx_strcmp(name1_lower, name2_lower) > 0;

    free(name1_lower);
    free(name2_lower);

    return compare_result;;
}

bool sort_by_artist(t_list *node1, t_list *node2) {
    char *artist1_lower = word_to_lower(node1->artist);
    char *artist2_lower = word_to_lower(node2->artist);

    bool compare_result = mx_strcmp(artist1_lower, artist2_lower) > 0;

    free(artist1_lower);
    free(artist2_lower);

    return compare_result;
}

bool mx_sort_file(const char *filename, const char *option) {
    t_list *list_head = mx_csv_to_linked_list(filename);

    if (list_head == NULL) {
        return false;
    }
    
    if (mx_strcmp(option, "name") == 0) {
        list_head = mx_sort_list(list_head, sort_by_name);
    }
    else if (mx_strcmp(option, "artist") == 0) {
        list_head = mx_sort_list(list_head, sort_by_artist);
    }
    else {
        return false;
    }

    bool success = mx_overwrite_file_with_linked_list(filename, list_head);

    mx_clear_list(&list_head);

    return success;
}

