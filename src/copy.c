/*
** EPITECH PROJECT, 2022
** copy.c
** File description:
** check file is readable
*/

#include "my.h"
#include "my_sokoban.h"

void copy_in_buffer(map_t *map, char *filepath)
{
    char *temp = malloc(sizeof(char) * 2);
    int i = 0;
    int tmp = open(filepath, O_RDONLY);

    if (tmp == -1) {
        exit(84);
    }
    for (i = 0; read(tmp, temp, 1); i++) ;
    i++;
    close(tmp);
    map->fd = open(filepath, O_RDONLY);
    map->buffer = NULL;
    map->buffer = malloc((sizeof(char) * i));
    read(map->fd, map->buffer, i);
    map->buffer[i] = '\0';
    close(map->fd);
}

void check_map(map_t *map)
{
    for (int i = 0; map->buffer[i];) {
        if (map->buffer[i] == ' ' || map->buffer[i] == '\n' ||
            map->buffer[i] == '#' || map->buffer[i] == 'P' ||
            map->buffer[i] == 'O' || map->buffer[i] == 'X' ||
            map->buffer[i] == '\0') {
            i++;
        } else
            exit(84);
    }
}

int cols(map_t *map, int temp)
{
    int i = 0;

    while (map->buffer[temp] != '\n' && map->buffer[temp] != '\0') {
        temp++;
        i++;
    }
    return (i);
}

void copy_in_double(map_t *map)
{
    int row = 0;
    int col = 0;
    int temp = 0;
    int columns = 0;

    map->map = malloc(sizeof(char *) * (map->row) + 1);
    map->saved = malloc(sizeof(char *) * (map->row) + 1);
    for (; row < map->row; row++) {
        columns = cols(map, temp);
        map->map[row] = malloc(sizeof(char) * columns + 1);
        map->saved[row] = malloc(sizeof(char) * columns + 1);
        for (col = 0; col < columns; col += 1) {
            map->map[row][col] = map->buffer[temp];
            map->saved[row][col] = map->buffer[temp];

            temp++;
        }
        temp++;
    }
}
