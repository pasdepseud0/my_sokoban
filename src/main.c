/*
** EPITECH PROJECT, 2022
** core.c
** File description:
** core of project
*/

#include "my.h"
#include "my_sokoban.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            helper();
            exit(0);
        }
        sokoban(argv[1]);
    } else {
        return (84);
    }
}
