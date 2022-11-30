/*
** EPITECH PROJECT, 2022
** my_sokoban.h
** File description:
** contain all function and all struct for this project
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

    #include <stddef.h>
    #include <stdlib.h>

    typedef struct game {
    char **map;
    char **save;
    char *buffer;
    int col;
    int row;
    int fd;
    int size;
    int chara;
    int pit;
    } game_t;

    typedef struct position {
    int *pit;
    int x;
    int y;
    } pos_t;

    typedef struct global {
    pos_t coord;
    game_t *game;
    } global_t;

    void check_if_pit(global_t *all);
    int barrel_and_pit(global_t *all, int row, int col, int i);
    void buckle(global_t *all);

    void cp_buff(global_t *all, char const *path);
    void check_map(global_t *all);
    int cols(global_t *all, int tmp);
    void cp_double(global_t *all);

    void descriptor(void);

    void get_cols(global_t *all);
    void check_if_a_chara(global_t *all, int col, int row);
    void get_character(global_t *all);
    void check_pit(global_t *all);

    int move_up(global_t *all);
    int move_down(global_t *all);
    int move_left(global_t *all);
    int move_right(global_t *all);

    void zevent(global_t *all, int key);

#endif
