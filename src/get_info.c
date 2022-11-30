/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "my_sokoban.h"

void get_cols(global_t *all)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (all->game->buffer[tmp] != '\n') {
        tmp++;
    }
    all->game->col = tmp;
    while (all->game->buffer[i] != '\0') {
        if (all->game->buffer[i] == '\n')
            j++;
        i++;
    }
    if (all->game->buffer[i - 1] != '\n')
        j++;
    all->game->row = j;
}

void check_if_a_chara(global_t *all, int col, int row)
{
    if (all->game->map[row][col] == 'P') {
        all->coord.x = col;
        all->coord.y = row;
        all->game->chara++;
    }
}

void get_character(global_t *all)
{
    int row = 0;
    int col = 0;
    int columns = 0;
    int tmp = 0;

    while (row != all->game->row) {
        columns = cols(all->game, tmp);
        while (col != columns) {
            check_if_a_chara(all->game, col, row);
            col++;
            tmp++;
        }
        tmp++;
        col = 0;
        row++;
    }
    if (all->game->chara != 1)
        exit(84);
}

void check_pit(global_t *all)
{
    int index = 0;
    int j = 0;

    while (all->game->buffer[index]) {
        if (all->game->buffer[index] == 'O')
            j++;
        index++;
    }
    index = 0;
    all->game->pit = j;
}
