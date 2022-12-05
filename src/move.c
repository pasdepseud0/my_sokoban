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
    if (check->map[check->posy - 1][check->posx] == 'X'
        && check->map[check->posy - 2][check->posx] != '#'
        && check->map[check->posy - 2][check->posx] != 'X') {
        if (check->save[check->posy][check->posx] == 'O') {
            check->map[check->posy][check->posx] = 'O';
        } else {
            check->map[check->posy][check->posx] = ' ';
        }
        check->map[check->posy - 2][check->posx] = 'X';
        check->map[check->posy - 1][check->posx] = 'P';
        check->posy--;
    } else if (check->map[check->posy - 1][check->posx] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy - 1][check->posx] = 'P';
        check->posy--;
    }
    return (0);
}

int move_down(struct_t *check)
{
    if (check->map[check->posy + 1][check->posx] == 'X'
        && check->map[check->posy + 2][check->posx] != '#'
        && check->map[check->posy + 2][check->posx] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy + 2][check->posx] = 'X';
        check->map[check->posy + 1][check->posx] = 'P';
        check->posy++;
    } else if (check->map[check->posy + 1][check->posx] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy + 1][check->posx] = 'P';
        check->posy++;
    }
    return (0);
}

int move_left(struct_t *check)
{
    if (check->map[check->posy][check->posx - 1] == 'X'
        && check->map[check->posy][check->posx - 2] != '#'
        && check->map[check->posy][check->posx - 2] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy][check->posx - 1] = 'P';
        check->map[check->posy][check->posx - 2] = 'X';
        check->posx--;
    } else if (check->map[check->posy][check->posx - 1] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy][check->posx - 1] = 'P';
        check->posx--;
    }
    return (0);
}

int move_right(struct_t *check)
{
    if (check->map[check->posy][check->posx + 1] == 'X'
        && check->map[check->posy][check->posx + 2] != '#'
        && check->map[check->posy][check->posx + 2] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy][check->posx + 1] = 'P';
        check->map[check->posy][check->posx + 2] = 'X';
        check->posx++;
    } else if (check->map[check->posy][check->posx + 1] != 'X') {
        if (check->save[check->posy][check->posx] == 'O')
            check->map[check->posy][check->posx] = 'O';
        else
            check->map[check->posy][check->posx] = ' ';
        check->map[check->posy][check->posx + 1] = 'P';
        check->posx++;
    }
    return (0);
}
