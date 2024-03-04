#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include "./minilibmx.h"

enum e_error {
    INVALID_OPERATION,
    INVALID_OPERAND,
    INVALID_RESULT,
};

void mx_print_variations(char *operand1, char *operation, char *operand2, char *result);
void mx_handle_error(enum e_error type, char *value);
bool mx_parse_number(char *value);
bool mx_parse_operator(char *value);
void mx_parse_arguments(char **operand1, char **operation, char **operand2, char **result);

#endif

