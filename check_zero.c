/*
** EPITECH PROJECT, 2020
** check_zero.c
** File description:
** check_zero.c
*/

#include "lib/my/my.h"
#include <stdlib.h>

int check_zero(char *str)
{
    int i = 0;
    int zero = 0;
    int count = 0;

    if (str[0] == '-')
        i = 1;
    while (str[i] != '\0') {
        if (str[i] == 48 && count == 0) {
            zero++;
            count = 0;
        } else {
            count = 1;
        }
        i++;
    }
    return zero;
}

char *strlengt_equal(char *str, char zero, char *new)
{
    new = malloc(sizeof(char) * 2);
    new[0] = 48;
    new[1] = '\0';
    return new;
}

char *strlengt_not_equal(char *str, char zero, char *new, int t)
{
    int count = 0, i = 0;
    new = malloc(sizeof(char) * (my_strlen(str) - zero + 1));
    if (str[0] == '-') {
        new[t] = '-';
        i = 1, t++;
    }
    while (str[i] != '\0') {
        if (str[i] == 48 && count == 0) {
            count = 0;
        } else {
            new[t] = str[i];
            count = 1;
            t++;
        }
        i++;
    }
    new[t] = '\0';
    return new;
}

char *create_new_str(char *str)
{
    int i = 0, t = 0;
    int zero = check_zero(str);
    char *new;

    if (zero == my_strlen(str))
        new = strlengt_equal(str, zero, new);
    else
        new = strlengt_not_equal(str, zero, new, t);

    return new;
}