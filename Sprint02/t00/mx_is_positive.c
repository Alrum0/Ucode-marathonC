void mx_printstr(const char *s);

void mx_is_positive(int i) {
    if (i > 0) {
        mx_printstr("positive\n");
    } else if (i == 0) {
        mx_printstr("zero\n");
    } else {
        mx_printstr("negative\n");
    }
}



















