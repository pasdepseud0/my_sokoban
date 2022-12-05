/*
** EPITECH PROJECT, 2022
** get_info.c
** File description:
** get info of environment of game
*/

#include "my.h"
#include "my_sokoban.h"

void get_cols(map_t *map)
{
    int i = 0;
    int temp = 0;
    int j = 0;

    while (map->buffer[temp] != '\n') {
        temp++;
    }
    map->col = temp;
    while (map->buffer[i] != '\0') {
        if (map->buffer[i] == '\n')
            j++;
        i++;
    }
    if (map->buffer[i - 1] != '\n')
        j++;
    map->row = j;
}

void get_p(map_t *map)
{
    int row = 0;
    int col = 0;
    int columns = 0;
    int temp = 0;

    while (row != map->row) {
        columns = cols(map, temp);
        while (col != columns) {
            check_if_p(map, col, row);
            col++;
            temp++;
        }
        temp++;
        col = 0;
        row++;
    }
    if (map->p != 1)
        exit(84);
}

void check_if_p(map_t *map, int col, int row)
{
    if (map->map[row][col] == 'P') {
        map->posx = col;
        map->posy = row;
        map->p++;
    }
}

void get_nbr_o(map_t *map)
{
    int i = 0;
    int j = 0;

    while (map->buffer[i]) {
        if (map->buffer[i] == 'O')
            j++;
        i++;
    }
    i = 0;
    map->o = j;
}
