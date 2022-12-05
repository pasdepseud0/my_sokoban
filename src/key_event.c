/*
** EPITECH PROJECT, 2022
** key_event.c
** File description:
** event of bound
*/

#include "my.h"
#include "my_sokoban.h"

void key_event(struct_t *check, int key)
{
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (key == KEY_UP && check->map[check->posy - 1][check->posx] != '#')
        move_up(check);
    if (key == KEY_DOWN && check->map[check->posy + 1][check->posx] != '#')
        move_down(check);
    if (key == KEY_LEFT && check->map[check->posy][check->posx - 1] != '#')
        move_left(check);
    if (key == KEY_RIGHT && check->map[check->posy][check->posx + 1] != '#')
        move_right(check);
}
