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
        char **map;
        char **saved;
        char *buffer;
        int row;
        int col;
        int size;
        int posx;
        int posy;
        int o;
        int p;
        int *pos_o;
    }struct_t;

    void check_openread(struct_t *file, char *path);
    void check_map(struct_t *map);
    int cols(struct_t *map, int temp);
    void copy_in_double(struct_t *map);

    void get_cols(struct_t *map);
    void get_p(struct_t *map);
    void check_if_p(struct_t *map, int col, int row);
    void get_nbr_o(struct_t *map);

    void helper(void);

    void key_event(struct_t *map, int key);

    int move_up(struct_t *map);
    int move_down(struct_t *map);
    int move_left(struct_t *map);
    int move_right(struct_t *map);

    void sokoban(char *filepath);

#endif
