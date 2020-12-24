/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int return_value;
    long int nbr = nb;

    if (nbr > 2147483647 || nbr < -2147483648)
        return 0;
    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
    }

    if (nb >= 10){
        my_put_nbr(nb / 10);
    }
    return_value = nb % 10 + 48;
    my_putchar(return_value);
}