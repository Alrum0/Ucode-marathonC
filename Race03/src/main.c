#include "../inc/matrix_rain.h"

int mx_random_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

t_droplet *mx_droplet_random(int size, int x, int y) {
    t_droplet *droplet = malloc(sizeof(t_droplet));

    if (droplet == NULL) {
        return NULL;
    }

    droplet->size = size;
    droplet->x = x;
    droplet->y = y;
    droplet->prev = NULL;

    if ((droplet->data = malloc(sizeof(wchar_t) * size)) == NULL) {
        free(droplet);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        droplet->data[i] = mx_random_range(32, 126);
    }

    return droplet;
}

void mx_droplet_free(t_droplet **droplet) {
    if (droplet == NULL || *droplet == NULL) {
        return;
    }

    free((*droplet)->data);
    free(*droplet);
    *droplet = NULL;
}

void mx_droplet_move_down(t_droplet *droplet) {
    if (droplet == NULL) {
        return;
    }

    wchar_t *data = droplet->data;
    int size = droplet->size;

    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    data[size - 1] = mx_random_range(32, 126);
    droplet->y++;
}

void mx_droplet_render(t_droplet *droplet) {
    wchar_t *data = droplet->data;
    int size = droplet->size;
    int x = droplet->x;
    int y = droplet->y;

    attron(COLOR_PAIR(0));
    mvprintw(y, x, "%lc", data[size - 1]);
    attroff(COLOR_PAIR(0));

    for (int i = 1; i < droplet->size; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(y - i, x, "%lc", data[size - i - 1]);
        attroff(COLOR_PAIR(1));
    }
}

bool mx_list_cmp(void *a, void *b) {
    return a == b;
}

void mx_handle_update(t_list *node) {
    int max_y = getmaxy(stdscr);

    t_droplet *droplet = node->data;

    mx_droplet_render(droplet);
    mx_droplet_move_down(droplet);
    
    int first_char_y = droplet->y - droplet->size;

    if (droplet->prev == NULL && first_char_y >= 5) {
        t_droplet *droplet_new = mx_droplet_random(
            mx_random_range(1, max_y),
            droplet->x,
            -mx_random_range(0, 20)
        );
        t_list *temp = node->next;
        node->next = mx_create_node(droplet_new);
        node->next->next = temp;
        droplet->prev = droplet_new;
    }

    if (first_char_y >= max_y) {
        mx_droplet_free(&droplet);
        node->data = droplet;
    }
}

void mx_clear_droplets(t_list *node) {
    t_droplet *droplet = node->data;
    mx_droplet_free(&droplet);
    node->data = droplet;
}

int main(void) {
    setlocale(LC_ALL, "");

    srand(time(NULL));

    initscr();
    halfdelay(1);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

    int max_x;
    int max_y;

    getmaxyx(stdscr, max_y, max_x);

    t_list *droplets = NULL;

    for (int i = 0; i < max_x; i++) {
        t_droplet *droplet = mx_droplet_random(
            mx_random_range(1, max_y),
            i,
            -mx_random_range(0, 20)
        );
        mx_push_back(&droplets, droplet);
    }

    char *lines[] = {
        "Wake up , Neo..",
        "The Matrix has you..",
        "Follow the white rabbit",
        "Knock, knock, Neo",
    };

    for (int i = 0; i < 4; i++) {
        erase();

        int line_len = mx_strlen(lines[i]);

        for (int j = 0; j < line_len; j++) {
            mvaddch(0, j, lines[i][j] | COLOR_PAIR(1));
            refresh();
            usleep(200000);
        }

        usleep(800000);
    }

    while (getch() != 'q') {
        erase();
        mx_foreach_list(droplets, &mx_handle_update);
        mx_del_node_if(&droplets, NULL, &mx_list_cmp);
        refresh();
        usleep(1);
    }

    mx_foreach_list(droplets, &mx_clear_droplets);
    mx_del_node_if(&droplets, NULL, &mx_list_cmp);
    mx_clear_list(&droplets);
    endwin();

    exit(0);
}

