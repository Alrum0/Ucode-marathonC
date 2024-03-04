#ifndef MATRIX_RAIN_H
#define MATRIX_RAIN_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

#include "./minilibmx.h"
#include "./list.h"

typedef struct s_droplet {
    wchar_t *data;
    int size;
    int x;
    int y; // y of the last character wrt the window
    struct s_droplet *prev;
}              t_droplet;

t_droplet *mx_droplet_random(int size, int x, int y);
void mx_droplet_free(t_droplet **droplet);
void mx_droplet_move_down(t_droplet *droplet);
void mx_droplet_render(t_droplet *droplet);

#endif

