/*
** EPITECH PROJECT, 2018
** mystrcat
** File description:
** str_cat_
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int k = 0;

    while (src[k] != '\0') {
        dest[i] = src[k];
        i += 1;
        k += 1;
    }
    dest[i] = '\0';
    return (dest);
}