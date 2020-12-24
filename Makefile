##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	lib/my/my_putchar.c		\
			lib/my/my_putstr.c		\
			lib/my/my_revstr.c		\
			lib/my/my_strlen.c		\
			lib/my/my_strcat.c		\
			lib/my/my_strdup.c		\
			lib/my/my_str_isnum.c		\
			get_str_nbr_case1.c		\
			get_str_nbr_case2.c		\
			get_str_nbr_case3.c		\
			get_str_nbr_case4.c		\
			check_zero.c		\
			chose_case.c		\
			main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		gcc -o$(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)

re: clean fclean all