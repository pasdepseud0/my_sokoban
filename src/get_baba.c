/*
** EPITECH PROJECT, 2022
** get_info.c
** File description:
** get info of environment of game
*/

#include "my.h"
#include "my_sokoban.h"

void get_memory(struct_t *check)
{
    int index = 0;
    int memory = 0;
    int count = 0;

    for (; check->buffer[memory] != '\n'; memory++) {
    }
    check->col = memory;
    for (; check->buffer[index] != '\0'; index++) {
        if (check->buffer[index] == '\n')
            count++;
    }
    if (check->buffer[i - 1] != '\n')
        count++;
    check->row = count;
}

void check_if_baba(struct_t *check, int col, int row)
{
    if (check->map[row][col] == 'P') {
        check->coordx = col;
        check->coordy = row;
        check->baba++;
    }
}

void get_baba(struct_t *check)
{
    int row = 0;
    int col = 0;
    int columns = 0;
    int index = 0;

    while (row != check->row) {
        columns = check_index(check, index);
        while (col != columns) {
            check_if_baba(check, col, row);
            col++;
            index++;
        }
        index++;
        col = 0;
        row++;
    }
    if (check->baba != 1)
        exit(84);
}

void get_a_pit(struct_t *check)
{
    int index = 0;
    int j = 0;

    while (check->buffer[index]) {
        if (check->buffer[index] == 'O')
            j++;
        index++;
    }
    index = 0;
    check->pit = j;
}
