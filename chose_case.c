/*
** EPITECH PROJECT, 2020
** chose_case
** File description:
** chose_case
*/

#include "lib/my/my.h"
#include <stdlib.h>

void *get_str_nbr_case1(char const *s1, char const *s2, char *new_str_nbr);

void *get_str_nbr_case2(char const *s1, char const *s2, char *new_str_nbr);

void *get_str_nbr_case3(char const *s1, char const *s2, char *new_str_nbr);

void *get_str_nbr_case4(char const *s1, char const *s2, char *new_str_nbr);

int cmp_two_str(char const *s1, char const *s2)
{
    if (s1[0] != '-' && s2[0] != '-')
        return 1;
    if (s1[0] == '-' && s2[0] == '-')
        return 2;
    if (s1[0] == '-' && s2[0] != '-')
        return 31;
    if (s1[0] != '-' && s2[0] == '-')
        return 32;
}

int cmp_case31(char const *s1, char const *s2)
{
    int c1 = my_strlen(s1);
    int c2 = my_strlen(s2);

    if (c1 - 1 < c2) {
        return 2;
    } else if (c1 - 1 > c2) {
        return 1;
    } else {
        for (int i = 0; i < c2; i++) {
            if (s1[i + 1] > s2[i] && (i - 1 < c2))
                return 1;
            else  if (s1[i + 1] < s2[i] && (i - 1 < c2))
                return 2;
        }
        return (2);
    }
}

int cmp_case32(char const *s1, char const *s2)
{
    int c1 = my_strlen(s1);
    int c2 = my_strlen(s2);

    if (c1 < c2 - 1) {
        return 2;
    } else if (c1 > c2 - 1) {
        return 1;
    } else {
        for (int i = 0; i < c2; i++) {
            if (s1[i] > s2[i + 1] && (i < c2 - 1))
                return 1;
            else  if (s1[i] < s2[i + 1] && (i < c2 - 1))
                return 2;
        }
        return (1);
    }
}

void chose_case_1_2(char const *s1, char const *s2, int c1, int c2)
{
    char *new_str_nbr_main;

    if (cmp_two_str(s1, s2) == 1 && c1 < c2)
        get_str_nbr_case1(s2, s1, new_str_nbr_main);
    if (cmp_two_str(s1, s2) == 1 && c1 >= c2)
        get_str_nbr_case1(s1, s2, new_str_nbr_main);
    if (cmp_two_str(s1, s2) == 2 && c1 < c2)
        get_str_nbr_case2(s2, s1, new_str_nbr_main);
    if (cmp_two_str(s1, s2) == 2 && c1 >= c2)
        get_str_nbr_case2(s1, s2, new_str_nbr_main);
}

void chose_case_3_4(char const *s1, char const *s2)
{
    char *new_str_nbr_main;

    if (cmp_two_str(s1, s2) == 31 && cmp_case31(s1, s2) == 2)
        get_str_nbr_case4(s2, s1, new_str_nbr_main);
    if (cmp_two_str(s1, s2) == 31 && cmp_case31(s1, s2) == 1)
        get_str_nbr_case3(s1, s2, new_str_nbr_main);
    if (cmp_two_str(s1, s2) == 32 && cmp_case32(s1, s2) == 2)
        get_str_nbr_case3(s2, s1, new_str_nbr_main);
    if (cmp_two_str(s1, s2) == 32 && cmp_case32(s1, s2) == 1)
        get_str_nbr_case4(s1, s2, new_str_nbr_main);
}