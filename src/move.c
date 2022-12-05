/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move a character 'P'
*/

#include "my.h"
#include "my_sokoban.h"

int move_up(map_t *map)
{
    if (map->map[map->posy - 1][map->posx] == 'X'
        && map->map[map->posy - 2][map->posx] != '#'
        && map->map[map->posy - 2][map->posx] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O') {
            map->map[map->posy][map->posx] = 'O';
        } else {
            map->map[map->posy][map->posx] = ' ';
        }
        map->map[map->posy - 2][map->posx] = 'X';
        map->map[map->posy - 1][map->posx] = 'P';
        map->posy--;
    } else if (map->map[map->posy - 1][map->posx] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy - 1][map->posx] = 'P';
        map->posy--;
    }
    return (0);
}

int move_down(map_t *map)
{
    if (map->map[map->posy + 1][map->posx] == 'X'
        && map->map[map->posy + 2][map->posx] != '#'
        && map->map[map->posy + 2][map->posx] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy + 2][map->posx] = 'X';
        map->map[map->posy + 1][map->posx] = 'P';
        map->posy++;
    } else if (map->map[map->posy + 1][map->posx] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy + 1][map->posx] = 'P';
        map->posy++;
    }
    return (0);
}

int move_left(map_t *map)
{
    if (map->map[map->posy][map->posx - 1] == 'X'
        && map->map[map->posy][map->posx - 2] != '#'
        && map->map[map->posy][map->posx - 2] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy][map->posx - 1] = 'P';
        map->map[map->posy][map->posx - 2] = 'X';
        map->posx--;
    } else if (map->map[map->posy][map->posx - 1] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy][map->posx - 1] = 'P';
        map->posx--;
    }
    return (0);
}

int move_right(map_t *map)
{
    if (map->map[map->posy][map->posx + 1] == 'X'
        && map->map[map->posy][map->posx + 2] != '#'
        && map->map[map->posy][map->posx + 2] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy][map->posx + 1] = 'P';
        map->map[map->posy][map->posx + 2] = 'X';
        map->posx++;
    } else if (map->map[map->posy][map->posx + 1] != 'X') {
        if (map->saved[map->posy][map->posx] == 'O')
            map->map[map->posy][map->posx] = 'O';
        else
            map->map[map->posy][map->posx] = ' ';
        map->map[map->posy][map->posx + 1] = 'P';
        map->posx++;
    }
    return (0);
}
