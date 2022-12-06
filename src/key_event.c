/*
** EPITECH PROJECT, 2022
** key_event.c
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
    if (key == KEY_UP && check->map[check->posy - 1][check->posx] != '#')
        move_up(check);
    if (key == KEY_DOWN && check->map[check->posy + 1][check->posx] != '#')
        move_down(check);
    if (key == KEY_LEFT && check->map[check->posy][check->posx - 1] != '#')
        move_left(check);
    if (key == KEY_RIGHT && check->map[check->posy][check->posx + 1] != '#')
        move_right(check);
}

void helper(void)
{
    mini_printf("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map file rep");
    mini_printf("resenting the warehouse map, containing '#' for walls,\n    ");
    mini_printf("     'P' for the player, 'X' for boxes and 'O' for storage l");
    mini_printf("ocations.\n");
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            helper();
            exit(0);
        }
        sokoban(av[1]);
    } else {
        return (84);
    }
}
