/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** take_list_file_in_dir
*/

#include "include/my.h"

void sort_list_file(int count, char **list, int r)
{
    char *tmp;

    for (int i = 0; list[i] != NULL; i++) {
        for (int j = i + 1; list[j] != NULL; j++) {
            if (cmp_str(list[i], list[j]) == 1) {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
    if (r == 1) {
        for (int i = 0; i < count / 2; i++) {
            tmp = list[i];
            list[i] = list[count - i - 1];
            list[count - i - 1] = tmp;
        }
    }
}

int count_file_in_dir(char *dir_name, DIR *rep, struct dirent *dir)
{
    int count = 0;

    rep = opendir(dir_name);
    while ((dir = readdir(rep)) != NULL) {
        if ((dir->d_name)[0] == '.')
            count--;
        count++;
    }
    closedir(rep);
    return count;
}

char **take_list_file_in_dir(char *dir_name, DIR *rep,
struct dirent *dir, int r)
{
    int count = count_file_in_dir(dir_name, rep, dir);
    int t = 0;
    char **array = malloc(sizeof(char *) * (count + 1));
    rep = opendir(dir_name);
    while ((dir = readdir(rep)) != NULL) {
        if ((dir->d_name)[0] == '.')
            continue;
        array[t] = dir->d_name;
        t++;
    }
    array[t] = NULL;
    sort_list_file(count, array, r);
    closedir(rep);
    return array;
}