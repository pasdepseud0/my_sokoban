/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "my_sokoban.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void cp_buff(global_t *all, char const *path)
{
    char *temp = malloc(sizeof(char) * 2);
    int i = 0;
    int tmp = open(path, O_RDONLY);

    if (tmp == -1) {
        exit(84);
    }
    for (i = 0; read(tmp, temp, 1); i++) ;
    i++;
    close(tmp);
    all->game->fd = open(path, O_RDONLY);
    all->game->buffer = NULL;
    all->game->buffer = malloc((sizeof(char) * i));
    read(all->game->fd, all->game->buffer, i);
    all->game->buffer[i] = '\0';
    close(all->game->fd);
}

void check_map(global_t *all)
{
    for (int i = 0; all->game->buffer[i];) {
        if (all->game->buffer[i] == ' ' || all->game->buffer[i] == '\n' ||
            all->game->buffer[i] == '#' || all->game->buffer[i] == 'P' ||
            all->game->buffer[i] == 'O' || all->game->buffer[i] == 'X' ||
            all->game->buffer[i] == '\0') {
            i++;
        } else
            exit(84);
    }
}

int cols(global_t *all, int tmp)
{
    int i = 0;

    while (all->game->buffer[tmp] != '\n' && all->game->buffer[tmp] != '\0') {
        tmp++;
        i++;
    }
    return (i);
}

void cp_double(global_t *all)
{
    int row = 0;
    int col = 0;
    int tmp = 0;
    int columns = 0;

    all->game->map = malloc(sizeof(char *) * (all->game->row) + 1);
    all->game->save = malloc(sizeof(char *) * (all->game->row) + 1);
    for (; row < all->game->row; row++) {
        columns = cols(all, tmp);
        all->game->map[row] = malloc(sizeof(char) * columns + 1);
        all->game->save[row] = malloc(sizeof(char) * columns + 1);
        for (col = 0; col < columns; col += 1) {
            all->game->map[row][col] = all->game->buffer[tmp];
            all->game->save[row][col] = all->game->buffer[tmp];

            tmp++;
        }
        tmp++;
    }
}
