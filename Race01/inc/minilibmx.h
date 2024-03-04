#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

double mx_pow(double n, unsigned int pow);
int mx_atoi(const char *str);
char *mx_itoa(int number);
int mx_atoi_ruthless(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
void mx_strdel(char **str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);
void mx_str_reverse(char *s);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);

#endif

