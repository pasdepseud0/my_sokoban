/*
** EPITECH PROJECT, 2022
** key_event.c
** File description:
** event of bound
*/

#include "my.h"
#include "my_sokoban.h"

void key_event(struct_t *map, int key)
{
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (key == KEY_UP && map->map[map->posy - 1][map->posx] != '#')
        move_up(map);
    if (key == KEY_DOWN && map->map[map->posy + 1][map->posx] != '#')
        move_down(map);
    if (key == KEY_LEFT && map->map[map->posy][map->posx - 1] != '#')
        move_left(map);
    if (key == KEY_RIGHT && map->map[map->posy][map->posx + 1] != '#')
        move_right(map);
}
