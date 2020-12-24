/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "lib/my/my.h"
#include <stdlib.h>

int cmp_two_str(char const *s1, char const *s2);

void chose_case_1_2(char const *s1, char const *s2, int c1, int c2);

void chose_case_3_4(char const *s1, char const *s2);

char *create_new_str(char *str);

int my_str_isnum_infin(char const *str)
{
    int i = 0;

    if (str[0] == '-')
        i = 1;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i += 1;
        else
            return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    int c1;
    int c2;

    if (ac != 3 || my_str_isnum_infin(av[1]) == 0
    || my_str_isnum_infin(av[2]) == 0)
        return (0);

    av[1] = create_new_str(av[1]);
    av[2] = create_new_str(av[2]);

    c1 = my_strlen(av[1]);
    c2 = my_strlen(av[2]);

    if (cmp_two_str(av[1], av[2]) == 1 || cmp_two_str(av[1], av[2]) == 2)
        chose_case_1_2(av[1], av[2], c1, c2);
    else if (cmp_two_str(av[1], av[2]) == 31 || cmp_two_str(av[1], av[2]) == 32)
        chose_case_3_4(av[1], av[2]);

    my_putstr("\n");
    return (0);
}