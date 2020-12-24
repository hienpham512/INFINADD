/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** case_special
*/

#include "include/my.h"

void case_special_l(int ac, char **av)
{
    DIR *rep;
    struct dirent *dir;

    print_info_dir(rep, dir, "./", check_r(ac, av));
}

void case_special_r(int ac, char **av)
{
    DIR *rep;
    struct dirent *dir;
    char **list = take_list_file_in_dir("./", rep, dir, check_r(ac, av));
    for (int i = 0; list[i] != NULL; i++) {
        my_putstr(list[i]);
        my_putchar('\t');
    }
    my_putchar('\n');
    free(list);
}

int check_case_l_R_empty_param(int ac, char **av)
{
    int count = ac - 1;
    for (int i = 0; i < ac; i++)
        if (av[i][0] == '-')
            count--;
    return count;
}

void case_special(int ac, char **av, char **array)
{
    DIR *rep;
    if (ac == 1) {
        case_special_r(ac, av);
        return;
    }
    if (check_l(ac, av) == 0
    && check_R(ac, av) == 0
    && check_r(ac, av) == 0
    && check_t(ac, av) == 0
    && check_d(ac, av) == 0)
        case_R_wthout_l(ac, av, array);
    if (check_case_l_R_empty_param(ac, av) == 0 && check_l(ac, av) != 0
    && check_R(ac, av) != 0)
        case_l_with_R(ac, av, array, rep);
    else if (check_l(ac, av) == 1 && ac == 2 && check_R(ac, av) != 1)
        case_special_l(ac, av);
    else if (check_r(ac, av) == 1 && ac == 2 && check_R(ac, av) != 1)
        case_special_r(ac, av);
}