/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main of the project
*/

#include "my.h"
#include "my_sokoban.h"

void my_sokoban(const char *path)
{
    global_t *all;

    all = NULL;
    all = malloc(sizeof(global_t));
    cp_buff(all, path);
    check_pit(all);
    get_cols(all);
    check_map(all);
    cp_double(all);
    get_character(all);
    buckle(all);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            descriptor();
            exit(0);
        }
        my_sokoban(argv[1]);
    } else {
        return (84);
    }
}
