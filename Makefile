##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	=	my_ls

SRC	=	main.c	\
		helper.c	\
		check_l_r_t.c	\
		sort_argv.c 	\
		print_dir.c 	\
		print_file.c 	\
		error_gestion.c 	\
		case_l_with_r.c 	\
		case_r.c 	\
		case_special.c 	\
		cmp_file_dir_name_on_param.c	\
		take_list_file_in_dir.c 	\
		lib/my/my_putchar.c		\
		lib/my/my_arraylen.c		\
		lib/my/my_strdup.c		\
		lib/my/my_strlen.c		\
		lib/my/my_putstr.c		\
		lib/my/my_put_nbr.c

OBJ 	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)
	rm *.o
	rm lib/my/*.o

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all