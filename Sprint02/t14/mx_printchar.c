#include <unistd.h>

void mx_printchar(char c)
{
    char *symbol = &c;
    write(1, symbol, 1);
}
