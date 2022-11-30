/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_get_nbr
*/

int my_get_nbr(char const *str)
{
    int i = 0;
    int res = 0;

    for (; str[i] == '-' || str[i] == ' '; i++);
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    return res;
}
