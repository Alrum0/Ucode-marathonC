#include <stddef.h>

int mx_strlen(const char* s);
int mx_strncmp(const char* s1, const char* s2, int n);
char* mx_strchr(const char* s, int c);
char* mx_strstr(const char* s1, const char* s2);

int mx_count_substr(const char* str, const char* sub) {
    int count = 0;
    int len_sub = mx_strlen(sub);
 
    if (len_sub == 0) {
        return 0;
    }
 
    char* result = mx_strstr(str, sub);
 
    while (result != NULL) {
        count++;
 
        result = mx_strstr(result + len_sub, sub);
    }
 
    return count;
}

