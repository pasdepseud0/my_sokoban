/*
** EPITECH PROJECT, 2022
** core.c
** File description:
** core of project
*/

#include "my.h"
#include "my_sokoban.h"

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
