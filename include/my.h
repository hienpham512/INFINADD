/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h for infin_add
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>

#define major(x)    ((x >> 8) & 0x7F)

#define minor(x)    (x & 0xFF)

#define ERROR_SYNTAX    84

#define FILE_NOT_FOUND    84

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
char *my_strdup(char *s1, char *s2);
char find_file_type(struct stat s, char *param);
void find_permission(char *fileName, struct stat fileStat);
void find_nlink(struct stat fileStat, char *path);
void print_uid_gid(struct passwd *pw, struct group  *gr,
struct stat fileStat);
void print_file_size(struct stat fileStat, char *dir_name);
int check_l (int ac, char **av);
int check_t (int ac, char **av);
int check_R (int ac, char **av);
int check_d (int ac, char **av);
int check_r (int ac, char **av);
int cmp_str(char *s1, char *s2);
int my_arraylen(char **array);
void print_info_dir(DIR *rep, struct dirent *dir, char *, int);
void print_time(struct stat fileStat);
char **sort_argv(int ac, char **av);
void print_info_file(struct stat fileStat,
char **array, int ac, char **av);
void find_total(DIR *rep,
struct stat fileStat,
struct dirent *dir, char *dir_name);
void *print_file_name(char *str);
char **take_list_file_in_dir(char *dir_name, DIR *rep, struct dirent *dir, int);
int count_file_dir_on_param(int ac, char **av);
int check_file_dir(char **array);
int check_option_ls(int ac, char **av);
char *find_path(char *dir_name, char *fileName);
void case_l_with_R(int ac, char **av, char **array, DIR *rep);
void case_d(int ac, char **av, char **array);
void case_R_wthout_l(int ac, char **av, char **array);
void case_l_with_R(int ac, char **av, char **array, DIR *rep);
int count_file_in_dir(char *dir_name, DIR *rep, struct dirent *dir);
void case_special(int ac, char **av, char **array);
void case_special_r(int ac, char **av);
int check_case_l_R_empty_param(int ac, char **av);
int error_gestion(char **array);
#endif