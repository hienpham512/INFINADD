/*
** EPITECH PROJECT, 2020
** get_str_nbr_case2
** File description:
** get_str_nbr_case2
*/

#include "lib/my/my.h"
#include <stdlib.h>
#include <unistd.h>

char *last_rest_case2(char const *s1, char const *s2, int rest)
{
    char *str;
    int a = (s1[1] - 48) + (s2[1] - 48) + rest;

    str = malloc(sizeof(char) * 2);
    if (((s1[1] - 48) + rest) >= 10 && my_strlen(s1) > my_strlen(s2)) {
        str[0] = (((s1[1] - 48) + rest) / 10) + 48;
        str[1] = '-';
        str[2] = '\0';
    } else if (((s1[1] - 48) + rest) < 10 && my_strlen(s1) > my_strlen(s2)){
        str[0] = '-';
        str[1] = '\0';
    }
    if (a >= 10 && my_strlen(s1) == my_strlen(s2)) {
        str[0] = (((s1[1] - 48) + (s2[1] - 48) + rest) / 10) + 48;
        str[1] = '-';
        str[2] = '\0';
    } else if (a < 10 && my_strlen(s1) == my_strlen(s2)){
        str[0] = '-';
        str[1] = '\0';
    }
    return str;
}

int find_rest_case2(char const *s1, char const *s2
, int *tab)
{
    int i = tab[0];
    int j = tab[1];
    int rest = tab[2];

    if (j <= 0 && ((s1[i] - 48) + rest) < 10)
        rest = 0;
    else if (j <= 0 && ((s1[i] - 48) + rest) >= 10)
        rest = 1;

    if (j > 0 && ((s1[i] - 48) + (s2[j] - 48) + rest) < 10)
        rest = 0;
    else if (j > 0 && ((s1[i] - 48) + (s2[j] - 48) + rest) >= 10)
            rest = 1;

    j--;
    return rest;
}

void *new_string_nbr_case2 (char const *s1, char const *s2
, char *new_str_nbr)
{
    int t = 0;
    int rest = 0;
    int j = my_strlen(s2) - 1;
    int *tab;

    tab = malloc(sizeof(int) * 3);
    for (int i = my_strlen(s1) - 1; i > 0; i--) {
        tab[0] = i;
        tab[1] = j;
        tab[2] = rest;
        if (j <= 0)
            new_str_nbr[t] = ((((s1[i] - 48) + rest) % 10) + 48);
        else
            new_str_nbr[t] = ((((s1[i] - 48) + (s2[j] - 48) + rest) % 10) + 48);
        rest = find_rest_case2(s1, s2, tab);
        t++;
        j--;
    }
    my_strcat(new_str_nbr, last_rest_case2(s1, s2, rest));
}

void *get_str_nbr_case2(char const *s1, char const *s2, char *new_str_nbr)
{
    int count1 = my_strlen(s1);
    int count2 = my_strlen(s2);
    int j = 0;

    if (((s1[1] - 48) + (s2[1] - 48) + 1) < 10) {
        new_str_nbr = malloc(sizeof(char) * count1 + 1);
    } else {
        new_str_nbr = malloc(sizeof(char) * count1 + 2);
    }
    new_string_nbr_case2(s1, s2, new_str_nbr);
    my_revstr(new_str_nbr);
    my_putstr(new_str_nbr);
    free(new_str_nbr);
}