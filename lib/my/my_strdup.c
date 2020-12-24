/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_strdup(char *s1, char *s2)
{
    char *result = malloc(sizeof(char)
    * (my_strlen(s1) + my_strlen(s2)) + 1);

    for (int i = 0; i < my_strlen(s1); i++)
        result[i] = s1[i];
    for (int i = 0; i < my_strlen(s2); i++)
        result[i + my_strlen(s1)] = s2[i];
    result[my_strlen(s1) + my_strlen(s2)] = '\0';
    return result;
}