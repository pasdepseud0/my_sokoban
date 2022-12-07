/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** move 'P' the chara
*/

#include "my.h"
#include "my_sokoban.h"

int move_up(struct_t *check)
{
    if (check->map[check->coordy - 1][check->coordx] == 'X'
        && check->map[check->coordy - 2][check->coordx] != '#'
        && check->map[check->coordy - 2][check->coordx] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O') {
            check->map[check->coordy][check->coordx] = 'O';
        } else {
            check->map[check->coordy][check->coordx] = ' ';
        }
        check->map[check->coordy - 2][check->coordx] = 'X';
        check->map[check->coordy - 1][check->coordx] = 'P';
        check->coordy--;
    } else if (check->map[check->coordy - 1][check->coordx] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy - 1][check->coordx] = 'P';
        check->coordy--;
    }
    return (0);
}

int move_down(struct_t *check)
{
    if (check->map[check->coordy + 1][check->coordx] == 'X'
        && check->map[check->coordy + 2][check->coordx] != '#'
        && check->map[check->coordy + 2][check->coordx] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy + 2][check->coordx] = 'X';
        check->map[check->coordy + 1][check->coordx] = 'P';
        check->coordy++;
    } else if (check->map[check->coordy + 1][check->coordx] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy + 1][check->coordx] = 'P';
        check->coordy++;
    }
    return (0);
}

int move_left(struct_t *check)
{
    if (check->map[check->coordy][check->coordx - 1] == 'X'
        && check->map[check->coordy][check->coordx - 2] != '#'
        && check->map[check->coordy][check->coordx - 2] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy][check->coordx - 1] = 'P';
        check->map[check->coordy][check->coordx - 2] = 'X';
        check->coordx--;
    } else if (check->map[check->coordy][check->coordx - 1] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy][check->coordx - 1] = 'P';
        check->coordx--;
    }
    return (0);
}

int move_right(struct_t *check)
{
    if (check->map[check->coordy][check->coordx + 1] == 'X'
        && check->map[check->coordy][check->coordx + 2] != '#'
        && check->map[check->coordy][check->coordx + 2] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy][check->coordx + 1] = 'P';
        check->map[check->coordy][check->coordx + 2] = 'X';
        check->coordx++;
    } else if (check->map[check->coordy][check->coordx + 1] != 'X') {
        if (check->save[check->coordy][check->coordx] == 'O')
            check->map[check->coordy][check->coordx] = 'O';
        else
            check->map[check->coordy][check->coordx] = ' ';
        check->map[check->coordy][check->coordx + 1] = 'P';
        check->coordx++;
    }
    return (0);
}
