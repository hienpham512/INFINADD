/*
** EPITECH PROJECT, 2020
** get_str_nbr_case4
** File description:
** get_str_nbr_case4
*/

#include "lib/my/my.h"
#include <stdlib.h>
#include <unistd.h>

char *create_new_str(char *str);

int cmp_case32(char const *s1, char const *s2);

int find_rest_case4(char const *s1, char const *s2
, int *tab)
{
    int i = tab[0];
    int j = tab[1];
    int rest = tab[2];

    if (j <= 0 && ((s1[i] - 48) - rest) >= 0)
        rest = 0;
    else if (j <= 0 && ((s1[i] - 48) - rest) < 0)
        rest = 1;

    if (j > 0 && ((s1[i] - 48) - (s2[j] - 48) - rest) >= 0)
        rest = 0;
    else if (j > 0 && ((s1[i] - 48) - (s2[j] - 48) + rest) < 0)
            rest = 1;

    j--;
    return rest;
}

char *last_rest_case4(char const *s1, char const *s2, int t, char *s)
{
    char *str;

    if (cmp_case32(s1, s2) == 2) {
        s[t] = '-';
        s[t + 1] = '\0';
    } else {
        s[t] = '\0';
    }
}

int d4(char const *s1, char const *s2, int *tab)
{
    int diff = 0;
    int i = tab[0];
    int j = tab[1];
    int rest = tab[2];

    if (j > 0) {
        if ((s1[i] - 48) - (s2[j] - 48) - rest < 0)
            diff = 10;
        else
            diff = 0;
    } else {
        if ((s1[i] - 48) - rest < 0)
            diff = 10;
        else
            diff = 0;
    }
    return diff;
}

void *new_string_nbr_case4 (char const *s1, char const *s2
, char *s)
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
        if (j <= 0)
            s[t] = ((((s1[i] - 48) - rest + d4(s1, s2, tab)) % 10) + 48);
        else
            s[t] = ((((s1[i] - 48) - (s2[j] - 48)
            - rest + d4(s1, s2, tab)) % 10) + 48);

        rest = find_rest_case4(s1, s2, tab);
        t++;
        j--;
    }
    last_rest_case4(s1, s2, t, s);
    free(tab);
}

void *get_str_nbr_case4(char const *s1, char const *s2, char *new_str_nbr)
{
    int count1 = my_strlen(s1);
    int count2 = my_strlen(s2);
    int j = 0;

    if (((s1[1] - 48) - (s2[0] - 48) - 1) < 0) {
        new_str_nbr = malloc(sizeof(char) * count1);
    } else {
        new_str_nbr = malloc(sizeof(char) * count1 + 1);
    }
    new_string_nbr_case4(s1, s2, new_str_nbr);
    my_revstr(new_str_nbr);
    new_str_nbr = create_new_str(new_str_nbr);
    my_putstr(new_str_nbr);
    free(new_str_nbr);
}