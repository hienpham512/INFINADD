/*
** EPITECH PROJECT, 2018
** mystrlen
** File description:
** length of a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}