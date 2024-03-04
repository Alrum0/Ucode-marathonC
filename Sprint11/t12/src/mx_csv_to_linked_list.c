#include "list.h"

int count_to_comma(const char *str) {
    int len = 0;

    while (*str != ',' && *str != '\0') {
        len++;
        str++;
    }

    return len;
}

int count_to_newline(const char *str) {
    int len = 0;

    while (*str != '\n' && *str != '\0') {
        len++;
        str++;
    }

    return len;
}

bool is_valid_csv_file(const char *str) {
    if (str == NULL) {
        return false;
    }

    while (mx_isspace(*str)) {
        str++;
    }

    if (*str == '\0') {
        return false;
    }

    while (true) {
        while (*str != ',' && *str != '\0') {
            str++;
        }

        if (*str == '\0') {
            return false;
        }

        str++;

        while (*str != '\n' && *str != '\0') {
            if (*str == ',') {
                return false;
            }
            str++;
        }

        if (*str == '\0') {
            return true;
        }

        while (mx_isspace(*str)) {
            str++;
        }

        if (*str == '\0') {
            return true;
        }
    }
}

t_list *mx_csv_to_linked_list(const char *filename) {
    char *file_str = mx_file_to_str(filename);

    if (!is_valid_csv_file(file_str)) {
        return NULL;
    }

    char *file_str_ptr = file_str;
    t_list *list_head = NULL;

    while (mx_isspace(*file_str)) {
        file_str++;
    }

    int line_length;
    int artist_length;
    int song_name_length;

    while (*file_str != '\0') {
        line_length = count_to_newline(file_str);
        artist_length = count_to_comma(file_str);
        song_name_length = line_length - artist_length - 1;

        char *artist = mx_strnew(artist_length);
        mx_strncpy(artist, file_str, artist_length);

        file_str += artist_length + 1;

        char *name = mx_strnew(song_name_length);
        mx_strncpy(name, file_str, song_name_length);

        mx_push_back(&list_head, artist, name);

        file_str += song_name_length;

        while (mx_isspace(*file_str)) {
            file_str++;
        }
    }
    
    free(file_str_ptr);

    return list_head;
}

