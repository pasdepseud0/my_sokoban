/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban
*/

#include "my.h"
#include "my_sokoban.h"

static int barrel_and_pit(struct_t *check, int row, int col, int i)
{
    if (check->map[row][col] == 'X' && check->save[row][col] == 'O')
        i++;
    if (i == check->pit) {
        endwin();
        exit(0);
    }
    return (i);
}

static void check_if_pit(struct_t *check)
{
    int row = 0;
    int i = 0;
    int col = 0;
    int columns = 0;
    int temp = 0;

    while (row != check->row) {
        columns = check_index(check, temp);
        while (col != columns) {
            i = barrel_and_pit(check, row, col, i);
            col++;
            temp++;
        }
        temp++;
        col = 0;
        row++;
    }
}

static void loop(struct_t *check)
{
    int key;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    while (1) {
        clear();
        for (int row = 0; row < check->row; row += 1)
            mvprintw(row, 0, "%s", check->map[row]);
        key = getch();
        if (key == -1)
            exit(84);
        key_event(check, key);
        refresh();
        check_if_pit(check);
    }
    endwin();
}

void sokoban(char *path)
{
    struct_t *check;

    check = NULL;
    check = malloc(sizeof(struct_t));
    check_openread(check, path);
    get_a_pit(check);
    get_memory(check);
    check_buff_map(check);
    copy_on_memory(check);
    get_baba(check);
    loop(check);
}
