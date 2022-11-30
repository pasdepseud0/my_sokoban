/*
** EPITECH PROJECT, 2022
** move_chara.c
** File description:
** move a P on the
*/

#include "my.h"
#include "my_sokoban.h"
#include <stdlib.h>

int move_up(global_t *all)
{
    if (all->game->map[all->coord.y - 1][all->coord.x] == 'X' &&
        all->game->map[all->coord.y - 2][all->coord.x] != '#' &&
        all->game->map[all->coord.y - 2][all->coord.x] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O') {
            all->game->map[all->coord.y][all->coord.x] = 'O';
        } else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y - 2][all->coord.x] = 'X';
        all->game->map[all->coord.y - 1][all->coord.x] = 'P';
        all->coord.y--;
    } else if (all->game->map[all->coord.y - 1][all->coord.x] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O')
            all->game->map[all->coord.y][all->coord.x] = 'O';
        else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y - 1][all->coord.x] = 'P';
        all->coord.y--;
    }
    return (0);
}

int move_down(global_t *all)
{
    if (all->game->map[all->coord.y + 1][all->coord.x] == 'X' &&
        all->game->map[all->coord.y + 2][all->coord.x] != '#' &&
        all->game->map[all->coord.y + 2][all->coord.x] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O') {
            all->game->map[all->coord.y][all->coord.x] = 'O';
        } else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y + 2][all->coord.x] = 'X';
        all->game->map[all->coord.y + 1][all->coord.x] = 'P';
        all->coord.y++;
    } else if (all->game->map[all->coord.y + 1][all->coord.x] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O')
            all->game->map[all->coord.y][all->coord.x] = 'O';
        else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y + 1][all->coord.x] = 'P';
        all->coord.y++;
    }
    return (0);
}

int move_left(global_t *all)
{
    if (all->game->map[all->coord.y][all->coord.x - 1] == 'X' &&
        all->game->map[all->coord.y][all->coord.x - 2] != '#' &&
        all->game->map[all->coord.y][all->coord.x - 2] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O') {
            all->game->map[all->coord.y][all->coord.x] = 'O';
        } else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y][all->coord.x - 1] = 'P';
        all->game->map[all->coord.y][all->coord.x - 2] = 'X';
        all->coord.x--;
    } else if (all->game->map[all->coord.y][all->coord.x - 1] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O')
            all->game->map[all->coord.y][all->coord.x] = 'O';
        else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y][all->coord.x - 1] = 'P';
        all->coord.x--;
    }
    return (0);
}

int move_right(global_t *all)
{
    if (all->game->map[all->coord.y][all->coord.x + 1] == 'X' &&
        all->game->map[all->coord.y][all->coord.x + 2] != '#' &&
        all->game->map[all->coord.y][all->coord.x + 2] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O') {
            all->game->map[all->coord.y][all->coord.x] = 'O';
        } else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y][all->coord.x + 1] = 'P';
        all->game->map[all->coord.y][all->coord.x + 2] = 'X';
        all->coord.x++;
    } else if (all->game->map[all->coord.y][all->coord.x + 1] != 'X') {
        if (all->game->save[all->coord.y][all->coord.x] == 'O')
            all->game->map[all->coord.y][all->coord.x] = 'O';
        else
            all->game->map[all->coord.y][all->coord.x] = ' ';
        all->game->map[all->coord.y][all->coord.x + 1] = 'P';
        all->coord.x++;
    }
    return (0);
}
