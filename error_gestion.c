/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** error_gestion
*/

#include "include/my.h"

int error_gestion(char **array)
{
    struct stat fileStat;
    int err;

    for (int i = 0; array[i] != NULL; i++) {
        err = stat(array[i], &fileStat);
        if (err < 0) {
            return ERROR_SYNTAX;
        } else {
            if (find_file_type(fileStat, array[i]) == '?')
                return ERROR_SYNTAX;
        }
    }
    return (0);
}