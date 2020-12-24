/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** sort_argv
*/

#include "include/my.h"

void *print_file_name(char *str)
{
    int find = -1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            find = i;
    if (find != -1)
        for (int i = 0; i <= find; i++)
            str = str + 1;
    my_putstr(str);
}

int count_file_dir_on_param(int ac, char **av)
{
    int count = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-')
            count++;
    }
    return count;
}

char **under_sort_argv(int ac, char **av)
{
    int t = 0;
    char **array;

    if (check_case_l_R_empty_param(ac, av) == 0) {
        array = malloc(sizeof(char * ) * 2);
        array[0] = "./";
        array[1] = NULL;
        return array;
    }
    array = malloc(sizeof(char *)
    * (count_file_dir_on_param(ac, av) + 1));
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            array[t] = av[i];
            t++;
        }
    }
    array[t] = NULL;
    return array;
}

char **sort_argv(int ac, char **av)
{
    char **array = under_sort_argv(ac, av);
    char *tmp;

    for (int i = 0; array[i] != NULL; i++)
        for (int j = i + 1; array[j] != NULL; j++)
            if (cmp_str(array[i], array[j]) == 1) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
    if (check_r(ac, av) != 0)
        for (int i = 0; i < my_arraylen(array) / 2; i++) {
            tmp = array[i];
            array[i] = array[my_arraylen(array) - 1];
            array[my_arraylen(array) - 1] = tmp;
        }
    return array;
}