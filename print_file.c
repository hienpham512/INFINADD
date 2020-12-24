/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** print_file
*/

#include "include/my.h"

void print_info_file(struct stat fileStat, char **array, int ac, char **av)
{
    DIR *rep;
    struct passwd *pw;
    struct group *gr;
    struct dirent *dir;
    int r = check_r(ac, av);
    for (int i = 0; array[i] != NULL; i++)
        if (find_file_type(fileStat, array[i]) != 'd') {
            stat(array[i], &fileStat), find_permission(array[i], fileStat);
            find_nlink(fileStat, array[i]), print_uid_gid(pw, gr, fileStat);
            print_file_size(fileStat, array[i]), print_time(fileStat);
            my_putstr(array[i]), my_putstr("\n");
        }
    for (int i = 0; array[i] != NULL; i++)
        if (find_file_type(fileStat, array[i]) == 'd') {
            if (i != 0) my_putstr("\n");
            if (my_arraylen(array) > 1)
                my_putstr(array[i]), my_putstr(":\n");
            print_info_dir(rep, dir, array[i], r);
        }
}