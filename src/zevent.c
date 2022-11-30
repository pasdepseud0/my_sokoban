/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "my_sokoban.h"
#include <ncurses.h>

void zevent(global_t *all, int key)
{
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (key == KEY_UP && all->game->map[all->coord.y - 1][all->coord.x] != '#')
        move_up(all);
    if (key == KEY_DOWN && all->game->map[all->coord.y + 1][all->coord.x] !=
        '#')
        move_down(all);
    if (key == KEY_LEFT && all->game->map[all->coord.y][all->coord.x - 1] !=
        '#')
        move_left(all);
    if (key == KEY_RIGHT && all->game->map[all->coord.y][all->coord.x + 1]
        != '#')
        move_right(all);
}
