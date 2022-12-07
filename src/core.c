/*
** EPITECH PROJECT, 2022
** core.c
** File description:
** event of bound
*/

#include "my.h"
#include "my_sokoban.h"

void key_event(struct_t *check, int key)
{
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (key == KEY_UP && check->map[check->coordy - 1][check->coordx] != '#')
        move_up(check);
    if (key == KEY_DOWN && check->map[check->coordy + 1][check->coordx] != '#')
        move_down(check);
    if (key == KEY_LEFT && check->map[check->coordy][check->coordx - 1] != '#')
        move_left(check);
    if (key == KEY_RIGHT && check->map[check->coordy][check->coordx + 1] != '#')
        move_right(check);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            exit(0);
        }
        my_sokoban(av[1]);
    } else {
        return (84);
    }
}
