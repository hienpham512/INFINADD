/*
** EPITECH PROJECT, 2020
** B-PSU-300-PAR-3-1-myls-thi-hien.pham
** File description:
** helper
*/

#include "include/my.h"

char find_file_type(struct stat s, char *param)
{
    stat(param, &s);

    switch (s.st_mode & S_IFMT) {
        case S_IFLNK:   return ('l') ;
        case S_IFBLK:   return ('b');
        case S_IFDIR:   return ('d') ;
        case S_IFIFO:   return ('p') ;
        case S_IFREG:   return ('-') ;
        case S_IFSOCK:  return ('s') ;
        case S_IFCHR:   return ('c') ;
        default:        return ('?') ;
    }
}

void find_permission(char *fileName, struct stat fileStat)
{
    my_putchar(find_file_type(fileStat, fileName));
    stat(fileName, &fileStat);
    my_putchar((fileStat.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((fileStat.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    my_putchar('.');
    my_putchar(' ');
}

void find_nlink(struct stat fileStat, char *path)
{
    stat(path, &fileStat);
    my_put_nbr(fileStat.st_nlink);
    my_putstr("\t");
}

void print_uid_gid(struct passwd *pw, struct group  *gr,
struct stat fileStat)
{
    pw = getpwuid(fileStat.st_uid);
    gr = getgrgid(fileStat.st_gid);
    my_putstr(pw->pw_name);
    my_putchar(' ');
    my_putstr(gr->gr_name);
    my_putchar(' ');
}

void print_file_size(struct stat fileStat, char *fileName)
{
    stat(fileName, &fileStat);
    my_putchar('\t');
    if (minor(fileStat.st_rdev) == 0 && major(fileStat.st_rdev) == 0) {
        my_put_nbr(fileStat.st_size);
    } else {
        my_put_nbr(minor(fileStat.st_rdev));
        my_putstr(", ");
        my_put_nbr(major(fileStat.st_rdev));
    }
    my_putchar('\t');
}