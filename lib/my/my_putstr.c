/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int c = 0; str[c] != '\0'; c++) {
        my_putchar(str[c]);
    }
    return (0);
}