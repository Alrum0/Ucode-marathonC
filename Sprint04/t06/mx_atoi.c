#include <stdbool.h>

bool mx_digit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    while (mx_isspace(*str)){
        str++;
    }
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (mx_digit(*str)) {
        result = result * 10 + (*str++ - '0');
    }
    return result * sign;
}









