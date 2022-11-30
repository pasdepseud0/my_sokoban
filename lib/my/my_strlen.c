/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** count a string char
*/

int my_strlen(char const *str)
{
    int len = 0;
    for (; str[len] != '\0'; len++);
    return len;
}
