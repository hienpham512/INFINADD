/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** print_dir
*/

#include "include/my.h"

void print_time(struct stat fileStat)
{
    char *time = ctime(&fileStat.st_mtime);

    for (int i = 4; i < my_strlen(time); i++) {
        my_putchar(time[8]), my_putchar(time[9]);
        my_putchar(' ');
        while (i < 7) {
            my_putchar(time[i]), i++;
        }
        my_putchar('.'), my_putchar(' ');
        i = 11;
        while (i > 10 && i < 16) {
            my_putchar(time[i]), i++;
        }
        my_putchar(' ');
        break;
    }
}

char *find_path(char *dir_name, char *fileName)
{
    char *result;
    char *tmp = "/";

    if (dir_name[my_strlen(dir_name) - 1] != '/') {
        tmp = my_strdup(dir_name, tmp);
        result = my_strdup(tmp, fileName);
    } else {
        result = my_strdup(dir_name, fileName);
    }
    return result;
}

void find_total(DIR *rep,
    struct stat fileStat,
    struct dirent *dir, char *dir_name)
{
    int size = 0;
    char *path;

    rep = opendir(dir_name);
    while ((dir = readdir(rep)) != NULL) {
        if ((dir->d_name)[0] == '.')
            continue;
        path = find_path(dir_name, dir->d_name);
        stat(path, &fileStat);
        size += fileStat.st_blocks;
    }
    closedir(rep);
    my_putstr("total ");
    my_put_nbr(size / 2);
    my_putchar('\n');
}

void print_info_dir(DIR *rep, struct dirent *dir, char *dir_name, int r)
{
    char *path;
    struct passwd *pw;
    struct group *gr ;
    struct stat fileStat;
    char **list_file_sorted = take_list_file_in_dir(dir_name, rep, dir, r);
    find_total(rep, fileStat, dir, dir_name);
    for (int i = 0; list_file_sorted[i] != NULL; i++){
        if (list_file_sorted[i][0] == '.')
            continue;
        path = find_path(dir_name, list_file_sorted[i]);
        stat(path, &fileStat);
        find_permission(find_path(dir_name, path), fileStat);
        find_nlink(fileStat, path);
        print_uid_gid(pw, gr, fileStat);
        print_file_size(fileStat, list_file_sorted[i]);
        print_time(fileStat);
        my_putstr(list_file_sorted[i]), my_putchar('\n');
        free(path);
    }
    free(list_file_sorted);
}