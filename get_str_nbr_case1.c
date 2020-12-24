/*
** EPITECH PROJECT, 2020
** get_str_nbr_case1
** File description:
** get_str_nbr_case1
*/

#include "lib/my/my.h"
#include <stdlib.h>
#include <unistd.h>

int find_rest_case1(char const *s1, char const *s2
, int *tab)
{
    int i = tab[0];
    int j = tab[1];
    int rest = tab[2];

    if (j < 0 && ((s1[i] - 48) + rest) < 10)
        rest = 0;
    else if (j < 0 && ((s1[i] - 48) + rest) >= 10)
        rest = 1;

    if (j >= 0 && ((s1[i] - 48) + (s2[j] - 48) + rest) < 10)
        rest = 0;
    else if (j >= 0 && ((s1[i] - 48) + (s2[j] - 48) + rest) >= 10)
        rest = 1;

    j--;
    return rest;
}

char *last_rest(char const *s1, char const *s2, int rest)
{
    char *str;

    str = malloc(sizeof(char) * 2);
    if (my_strlen(s1) > my_strlen(s2)) {
        if (((s1[0] - 48) + rest) >= 10)
            str[0] = (((s1[0] - 48) + rest) / 10) + 48;
    } else if (my_strlen(s1) == my_strlen(s2)) {
        if (((s1[0] - 48) + (s2[0] - 48) + rest) >= 10)
            str[0] = (((s1[0] - 48) + (s2[0] - 48) + rest) / 10) + 48;
    }
    str[1] = '\0';
    return str;
}

void *new_string_nbr_case1 (char const *s1, char const *s2
, char *new_str_nbr)
{
    int t = 0;
    int rest = 0;
    int j = my_strlen(s2) - 1;
    int *tab;

    tab = malloc(sizeof(int) * 3);
    for (int i = my_strlen(s1) - 1; i >= 0; i--) {
        tab[0] = i;
        tab[1] = j;
        tab[2] = rest;
        if (j < 0)
            new_str_nbr[t] = ((((s1[i] - 48) + rest) % 10) + 48);
        else
            new_str_nbr[t] = (((s1[i] - 48) + (s2[j] - 48) + rest) % 10) + 48;
        rest = find_rest_case1(s1, s2, tab);
        t++;
        j--;
    }
    my_strcat(new_str_nbr, last_rest(s1, s2, rest));
    free(tab);
}

void *get_str_nbr_case1(char const *s1, char const *s2, char *new_str_nbr)
{
    int count1 = my_strlen(s1);
    int count2 = my_strlen(s2);
    int j = 0;

    if (((s1[0] - 48) + (s2[0] - 48) + 1) < 10) {
        new_str_nbr = malloc(sizeof(char) * count1 + 1);
    } else {
        new_str_nbr = malloc(sizeof(char) * count1 + 2);
    }
    new_string_nbr_case1(s1, s2, new_str_nbr);
    my_revstr(new_str_nbr);
    my_putstr(new_str_nbr);
    free(new_str_nbr);
}