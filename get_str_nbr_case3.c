/*
** EPITECH PROJECT, 2020
** get_str_nbr_case3
** File description:
** get_str_nbr_case3
*/

#include "lib/my/my.h"
#include <stdlib.h>
#include <unistd.h>

char *create_new_str(char *str);

int cmp_case31(char const *s1, char const *s2);

char *last_rest_case3(char const *s1, char const *s2, int t, char *s)
{
    char *str;

    if (cmp_case31(s1, s2) == 1) {
        s[t] = '-';
        s[t + 1] = '\0';
    } else {
        s[t] = '\0';
    }

}

int find_rest_case3(char const *s1, char const *s2
, int *tab)
{
    int i = tab[0];
    int j = tab[1];
    int rest = tab[2];

    if (j < 0 && ((s1[i] - 48) - rest) >= 0)
        rest = 0;
    else if (j < 0 && ((s1[i] - 48) - rest) < 0)
        rest = 1;

    if (j >= 0 && ((s1[i] - 48) - (s2[j] - 48) - rest) >= 0)
        rest = 0;
    else if (j >= 0 && ((s1[i] - 48) - (s2[j] - 48) + rest) < 0)
            rest = 1;

    j--;
    return rest;
}

int d(char const *s1, char const *s2, int *tab)
{
    int i = tab[0];
    int j = tab[1];
    int rest = tab[2];
    int diff = 0;

    if (j >= 0) {
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

void *new_string_nbr_case3 (char const *s1, char const *s2
, char *s)
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
        if (j < 0) {
            s[t] = ((((s1[i] - 48) - rest + d(s1, s2, tab)) % 10) + 48);
        } else {
            s[t] = ((((s1[i] - 48) - (s2[j] - 48)
            - rest + d(s1, s2, tab)) % 10) + 48);
        }
        rest = find_rest_case3(s1, s2, tab);
        t++;
        j--;
    }
    last_rest_case3(s1, s2, t, s);
}

void *get_str_nbr_case3(char const *s1, char const *s2, char *new_str_nbr)
{
    int count1 = my_strlen(s1);
    int count2 = my_strlen(s2);
    char *result;
    int j = 0;

    if (((s1[1] - 48) - (s2[0] - 48) - 1) < 0) {
        new_str_nbr = malloc(sizeof(char) * count1 + 2);
    } else {
        new_str_nbr = malloc(sizeof(char) * count1 + 3);
    }
    new_string_nbr_case3(s1, s2, new_str_nbr);
    my_revstr(new_str_nbr);
    new_str_nbr = create_new_str(new_str_nbr);
    my_putstr(new_str_nbr);
    free(new_str_nbr);
}