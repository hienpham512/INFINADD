/*
** EPITECH PROJECT, 2018
** my putchar .c
** File description:
** my putchar
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}