/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** my_arraylen
*/

#include "../../include/my.h"

int my_arraylen(char **array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}