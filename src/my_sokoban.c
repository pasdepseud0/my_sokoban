/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

void init_map(void)
{
    char *msg = "Hello, world!";
    int len = my_strlen(msg);

    initscr();
    while (1) {
        clear();
        mvprintw (LINES / 2, (COLS / 2) - (len / 2), msg);
        refresh();
        if (getch() != 410) {
            break;
        }
    }
    endwin();
}

int main(void)
{
    init_map();
    return 0;
}
