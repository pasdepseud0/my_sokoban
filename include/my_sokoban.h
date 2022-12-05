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

    typedef struct map {
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
    }map_t;

    void copy_in_buffer(map_t *map, char *filepath);
    void check_map(map_t *map);
    int cols(map_t *map, int temp);
    void copy_in_double(map_t *map);

    void get_cols(map_t *map);
    void get_p(map_t *map);
    void check_if_p(map_t *map, int col, int row);
    void get_nbr_o(map_t *map);

    void helper(void);

    void key_event(map_t *map, int key);

    int move_up(map_t *map);
    int move_down(map_t *map);
    int move_left(map_t *map);
    int move_right(map_t *map);

    void sokoban(char *filepath);

#endif
