/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** case_option
*/

#include "include/my.h"

void case_d(int ac, char **av, char **array)
{
    struct passwd *pw;
    struct group *gr;
    struct stat fileStat;

    if (check_l(ac, av) != 0) {
        for (int i = 0; array[i] != NULL; i++) {
            stat(array[i], &fileStat), find_permission(array[i], fileStat);
            find_nlink(fileStat, array[i]), print_uid_gid(pw, gr, fileStat);
            print_file_size(fileStat, array[i]), print_time(fileStat);
            my_putstr(array[i]), my_putstr("\n");
        }
    } else {
        for (int i = 0; array[i] != NULL; i++) {
            my_putstr(array[i]);
            my_putchar('\t');
        }
        my_putchar('\n');
    }
}

char **under_case_l_with_R(char *dir_name,  int ac, char **av)
{
    char *path;
    struct passwd *pw;
    struct group *gr ;
    struct stat fileStat;
    DIR *rep;
    struct dirent *dir;
    char **array = malloc(sizeof(char *) *
    (count_file_in_dir(dir_name, rep, dir) + 1));
    int t = 0, r = check_r(ac, av);
    char **list_file_sorted = take_list_file_in_dir(dir_name, rep, dir, r);
    for (int i = 0; list_file_sorted[i] != NULL; i++){
        if (list_file_sorted[i][0] == '.')
            continue;
        path = find_path(dir_name, list_file_sorted[i]);
        array[t] = path;
        t++;
    }
    array[t] = NULL;
    free(list_file_sorted);
    return array;
}

void print_under_case_l_with_R(int ac, char **av, char **array)
{
    DIR *rep;
    struct dirent *dir;
    struct stat fileStat;
    char **n_list;
    for (int i = 0; array[i] != NULL; i++) {
        if (find_file_type(fileStat, array[i]) == 'd') {
            my_putstr(array[i]), my_putstr(":\n");
            print_info_dir(rep, dir, array[i], check_r(ac, av));
        }
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (find_file_type(fileStat, array[i]) == 'd') {
            n_list = under_case_l_with_R(array[i], ac, av);
            case_l_with_R(ac, av, n_list, rep);
        }
    }
}

void case_l_with_R(int ac, char **av, char **array, DIR *rep)
{
    struct passwd *pw;
    struct group *gr;
    struct dirent *dir;
    struct stat fileStat;
    char **n_list;
    for (int i = 0; array[i] != NULL; i++)
        if (find_file_type(fileStat, array[i]) != 'd') {
            stat(array[i], &fileStat), find_permission(array[i], fileStat);
            find_nlink(fileStat, array[i]), print_uid_gid(pw, gr, fileStat);
            print_file_size(fileStat, array[i]), print_time(fileStat);
            my_putstr(array[i]), my_putstr("\n");
        }
    for (int i = 0; array[i] != NULL; i++)
        if (find_file_type(fileStat, array[i]) == 'd') {
            my_putstr(array[i]), my_putstr(":\n");
            print_info_dir(rep, dir, array[i], check_r(ac, av));
            n_list = under_case_l_with_R(array[i], ac, av);
            print_under_case_l_with_R(ac, av, n_list);
        }
}