/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** case_R
*/

#include "include/my.h"

void print_file_in_dir(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i][0] == '.')
            continue;
        my_putstr(array[i]);
        my_putchar('\t');
    }
}

char **take_list_file_path(char **array, char *dir_name)
{
    DIR *rep;
    struct dirent *dir;
    int t = 0;
    struct stat fileStat;
    int count = count_file_in_dir(dir_name, rep, dir);
    char **list = malloc(sizeof(char *) * (count + 1));

    rep = opendir(dir_name);

    while ((dir = readdir(rep)) != NULL) {
        if ((dir->d_name)[0] == '.')
            continue;
        if (find_file_type(fileStat, find_path(dir_name, dir->d_name)) == 'd')
            list[t] = find_path(dir_name, dir->d_name);
        t++;
    }
    closedir(rep);
    return list;
}

void  **under_case_R_wthout_l(char **array, int ac, char **av)
{
    struct stat fileStat;
    DIR *rep;
    struct dirent *dir;
    char *tmp;
    char **list;

    for (int i = 0; array[i] != NULL; i++) {
        if (find_file_type(fileStat, array[i]) == 'd') {
            if (i != 0)
                my_putstr("\n");
            my_putstr(array[i]);
            my_putstr(":\n");
            list = take_list_file_in_dir(array[i], rep, dir, check_r(ac, av));
            print_file_in_dir(list);
            my_putstr("\n");
            list = take_list_file_path(list, array[i]);
            under_case_R_wthout_l(list, ac, av);
        }
    }
}

void case_R_wthout_l(int ac, char **av, char **array)
{
    struct stat fileStat;
    struct dirent *dir;
    DIR *rep;
    char *tmp, **list;
    int i = 0;

    for (i = 0; array[i] != NULL; i++) {
        if (find_file_type(fileStat, array[i]) != 'd') {
            my_putstr(array[i]);
            my_putchar('\t');
        }
    }
    if (i != 0 && array[i] != NULL)
        my_putstr("\n");
    under_case_R_wthout_l(array, ac, av);
}