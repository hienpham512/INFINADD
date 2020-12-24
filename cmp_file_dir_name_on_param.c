/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** cmp_file_dir_name_on_param
*/

#include "include/my.h"

int under_cmp_str(char *s1, char *s2, int size)
{
    for (int i = 0; i < size; i++) {
        if ((s1[i] > 96 && s1[i] < 123) && (s2[i] > 64 && s2[i] < 91)) {
            if (s1[i] - 32 > s2[i])
                return (1);
            else if (s1[i] - 32 < s2[i])
                return (2);
        } else if ((s2[i] > 96 && s2[i] < 123) && (s1[i] > 64 && s1[i] < 91)) {
            if (s1[i] + 32 > s2[i])
                return (1);
            else if (s1[i] + 32 < s2[i])
                return (2);
        } else {
            if (s1[i] > s2[i])
                return (1);
            else if (s1[i] < s2[i])
                return (2);
        }
    }
    return (0);
}

int cmp_str(char *s1, char *s2)
{
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);
    int result;

    if (l1 < l2)
        result = under_cmp_str(s1, s2, l1);
    else
        result = under_cmp_str(s1, s2, l2);
    if (l2 > l1 && result == 0)
        return 1;
    else if (l1 > l2 && result == 0)
        return 2;
    return result;
}