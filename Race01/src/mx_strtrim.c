#include "../inc/minilibmx.h"

char *mx_strtrim(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  while (*str != '\0' && mx_isspace(*str)) {
    str++;
  }

  int trimmed_len = mx_strlen(str);

  while (trimmed_len >= 1 && mx_isspace(str[trimmed_len - 1])) {
    trimmed_len--;
  }

  char *trimmed = mx_strnew(trimmed_len);

  if (trimmed == NULL) {
    return NULL;
  }

  return mx_strncpy(trimmed, str, trimmed_len);
}
