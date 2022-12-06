/*
** EPITECH PROJECT, 2022
** copy.c
** File description:
** check file is readable
*/

#include "my.h"
#include "my_sokoban.h"

void check_openread(struct_t *check, char *path)
{
    char *buf = malloc(sizeof(char) * 2);
    int i = 0;
    int file_descriptor = open(path, O_RDONLY);

    if (file_descriptor == -1) {
        exit(84);
    }
    for (i = 0; read(file_descriptor, buf, 1); i++) ;
    i++;
    close(file_descriptor);
    check->fd = open(path, O_RDONLY);
    check->buffer = NULL;
    check->buffer = malloc((sizeof(char) * i));
    read(check->fd, check->buffer, i);
    check->buffer[i] = '\0';
    close(check->fd);
}

void check_buff_map(struct_t *check)
{
    for (int i = 0; check->buffer[i];) {
        if (check->buffer[i] == ' ' || check->buffer[i] == '\n' ||
            check->buffer[i] == '#' || check->buffer[i] == 'P' ||
            check->buffer[i] == 'O' || check->buffer[i] == 'X' ||
            check->buffer[i] == '\0') {
            i++;
        } else
            exit(84);
    }
}

int check_index(struct_t *check, int index)
{
    int count = 0;
    for (;check->buffer[index] != '\n' && check->buffer[index] != '\0'; count++)
        index++;
    return (count);
}

void copy_on_memory(struct_t *check)
{
    int row = 0;
    int pillar = 0;
    int col = 0;
    int index = 0;

    check->map = malloc(sizeof(char *) * (check->row) + 1);
    check->save = malloc(sizeof(char *) * (check->row) + 1);
    for (; row < check->row; row++) {
        pillar = check_index(check, index);
        check->map[row] = malloc(sizeof(char) * pillar + 1);
        check->save[row] = malloc(sizeof(char) * pillar + 1);
        for (col = 0; col < pillar; col += 1) {
            check->map[row][col] = check->buffer[index];
            check->save[row][col] = check->buffer[index];
            index++;
        }
        index++;
    }
}
