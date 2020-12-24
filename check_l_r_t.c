/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** annalyse_argv
*/

#include "include/my.h"

int check_l (int ac, char **av)
{
    for (int i = 0; i  < ac; i++) {
        if (av[i][0] == '-')
            for (int j = 0; j < my_strlen(av[i]); j++)
                if (av[i][j] == 'l')
                    return (1);
    }
    return (0);
}

int check_t (int ac, char **av)
{
    for (int i = 0; i  < ac; i++) {
        if (av[i][0] == '-')
            for (int j = 0; j < my_strlen(av[i]); j++)
                if (av[i][j] == 't')
                    return (1);
    }
    return (0);
}

int check_R (int ac, char **av)
{
    for (int i = 0; i  < ac; i++) {
        if (av[i][0] == '-')
            for (int j = 0; j < my_strlen(av[i]); j++)
                if (av[i][j] == 'R')
                    return (1);
    }
    return (0);
}

int check_d (int ac, char **av)
{
    for (int i = 0; i  < ac; i++) {
        if (av[i][0] == '-')
            for (int j = 0; j < my_strlen(av[i]); j++)
                if (av[i][j] == 'd')
                    return (1);
    }
    return (0);
}

int check_r (int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-') {
            for (int j = 0; j < my_strlen(av[i]); j++)
                if (av[i][j] == 'r')
                    return (1);
        }
    }
    return (0);
}