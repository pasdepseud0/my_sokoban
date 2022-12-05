/*
** EPITECH PROJECT, 2022
** my_sokoban.h
** File description:
** struct of my_sokoban
*/

#ifndef MAP_H
    #define MAP_H

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <string.h>

    typedef struct {
        int fd;
        char *buffer;
        int size;
        int col;
        int row;
        int posx;
        int posy;
        char **map;
        char **save;
        int pit;
        int baba;
        int *check_pit;
    }struct_t;

    void check_openread(struct_t *file, char *path);
    void check_buff_map(struct_t *check);
    int check_index(struct_t *check, int index);
    void copy_on_memory(struct_t *check);

    void get_memory(struct_t *check);
    void get_baba(struct_t *check);
    void check_if_baba(struct_t *check, int col, int row);
    void get_a_pit(struct_t *check);

    void helper(void);

    void key_event(struct_t *check, int key);

    int move_up(struct_t *check);
    int move_down(struct_t *check);
    int move_left(struct_t *check);
    int move_right(struct_t *check);

    void sokoban(char *path);

#endif
