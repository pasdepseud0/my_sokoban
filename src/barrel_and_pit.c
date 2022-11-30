/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "my_sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

void check_if_pit(global_t *all)
{
    int row = 0;
    int i = 0;
    int col = 0;
    int columns = 0;
    int temp = 0;

    while (row != all->game->row) {
        columns = cols(all, temp);
        while (col != columns) {
            i = barrel_and_pit(all, row, col, i);
            col++;
            temp++;
        }
        temp++;
        col = 0;
        row++;
    }
}

int barrel_and_pit(global_t *all, int row, int col, int i)
{
    if (all->game->map[row][col] == 'X' && all->game->save[row][col] == 'O')
        i++;
    if (i == all->game->chara) {
        endwin();
        exit(0);
    }
    return (i);
}

void buckle(global_t *all)
{
    int key;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    while (1) {
        clear();
        for (int row = 0; row < all->game->row; row += 1)
            mvprintw(row, 0, "%s", all->game->map[row]);
        key = getch();
        if (key == -1)
            exit(84);
        zevent(all, key);
        refresh();
        check_if_pit(all);
    }
    endwin();
}
