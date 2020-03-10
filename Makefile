##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/infin_add.c	\
		src/set_struct.c	\
		src/my_strlen.c	\
		src/my_revstr.c	\
		src/my_putstr.c	\
		src/my_strcmp.c	\

TESTS	=	tests/test_my_infadd.c	\
		src/infin_add.c	\
		src/set_struct.c	\
		src/my_strlen.c	\
		src/my_revstr.c	\
		src/my_putstr.c	\
		src/my_strdup.c	\
		src/my_strcmp.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

CFLAGS	=	-W -Wall -I include/

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) $(TESTS) $(CFLAGS) $(UNITFLAGS) -o $(EXECTESTS)
	./$(EXECTESTS) && gcovr

clean:
	rm -f src/*~
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXECTESTS)

re:	fclean all

.PHONY:	all clean fclean re
