/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien->pham
** File description:
** main
*/

#include "include/my.h"

int main(int ac, char **av)
{
    DIR *rep;
    struct stat fileStat;
    struct dirent *dir;
    char **array = sort_argv(ac, av);
    if (error_gestion(array) != 0)
        return ERROR_SYNTAX;
    if (check_d(ac, av) == 1) {
        case_d(ac, av, array);
        return (0);
    }
    case_special(ac, av, array);
    if (check_l(ac, av) == 1 && check_R(ac, av) == 0
    && check_case_l_R_empty_param(ac, av) != 0)
        print_info_file(fileStat, array, ac, av);
    else if (check_l(ac, av) == 0 && check_R(ac, av) == 1)
        case_R_wthout_l(ac, av, array);
    else if (check_l(ac, av) == 1 && check_R(ac, av) == 1
    && check_case_l_R_empty_param(ac, av) != 0)
        case_l_with_R(ac, av, array, rep);
    return 0;
}