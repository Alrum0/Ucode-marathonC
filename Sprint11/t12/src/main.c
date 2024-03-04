#include "list.h"

bool is_valid_num(const char *str) {
    while (mx_isspace(*str)) {
        str++;
    }

    if (*str == '-') {
        str++;
    }
    else if (*str == '+') {
        str++;
    }

    while (mx_isdigit(*str) || *str == '?') {    
        str++;
    }
    
    while (mx_isspace(*str)) {
        str++;
    }
    
    if (*str != '\0') {
        return false;
    }
    
    return true;
}

int main(int argc, char *argv[]) {
    if (argc == 5) {
        if (mx_strcmp(argv[2], "add") != 0) {
            mx_printerr("ERROR\n");
            exit(EXIT_FAILURE);
        }

        bool is_success = mx_add_to_file(argv[1], argv[3], argv[4]);

        if (!is_success) {
            mx_printerr("ERROR\n");
        }
    }
    else if (argc == 4) {
        if (mx_strcmp(argv[2], "remove") == 0) {
            if (!is_valid_num(argv[3])) {
                mx_printerr("ERROR\n");
                exit(EXIT_FAILURE);
            }

            const char *filename = argv[1];
            int item_index = mx_atoi(argv[3]);

            bool is_success = mx_remove_from_file(filename, item_index);

            if (!is_success) {
                mx_printerr("ERROR\n");
                exit(EXIT_FAILURE);
            }
        }
        else if (mx_strcmp(argv[2], "sort") == 0) {
            bool is_success = mx_sort_file(argv[1], argv[3]);

            if (!is_success) {
                mx_printerr("ERROR\n");
                exit(EXIT_FAILURE);
            }
        }
        else {
            mx_printerr("ERROR\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (argc == 3) {
        if (mx_strcmp(argv[2], "print") != 0) {
            mx_printerr("ERROR\n");
            exit(EXIT_FAILURE);
        }

        bool is_success = mx_print_file(argv[1]);

        if (!is_success) {
            mx_printerr("ERROR\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}


