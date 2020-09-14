##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile of my cat
##

SRC =	src/main.c				\
	src/eval_expr/eval_expr.c		\
	src/eval_expr/arguments.c		\
	src/eval_expr/bracket.c			\
	src/eval_expr/bracket_extand.c		\
	src/eval_expr/operand.c			\
	src/eval_expr/operations.c		\
	src/eval_expr/ptr_min_max.c		\
	src/eval_expr/scans.c			\
	src/infin_calc/general_functions.c	\
	src/infin_calc/infin_add.c		\
	src/infin_calc/infin_add_extention.c	\
	src/infin_calc/infin_mult.c		\
	src/infin_calc/infin_sub.c		\
	src/bistro.c				\
	src/bistro2.c				\
	src/infin_calc/infin_div.c		\
	src/infin_calc/infin_mod.c		\
	src/infin_calc/infin_sub_extention.c

SRC_TEST =	tests/test_bistro.c		\
	src/eval_expr/eval_expr.c		\
	src/eval_expr/arguments.c		\
	src/eval_expr/bracket.c			\
	src/eval_expr/bracket_extand.c		\
	src/eval_expr/operand.c			\
	src/eval_expr/operations.c		\
	src/eval_expr/ptr_min_max.c		\
	src/eval_expr/scans.c			\
	src/infin_calc/general_functions.c	\
	src/infin_calc/infin_add.c		\
	src/infin_calc/infin_add_extention.c	\
	src/infin_calc/infin_mult.c		\
	src/infin_calc/infin_sub.c		\
	src/bistro.c				\
	src/bistro2.c				\
	src/infin_calc/infin_div.c		\
	src/infin_calc/infin_mod.c		\
	src/infin_calc/infin_sub_extention.c

OBJ	=	$(SRC:.c=.o)

OBJ_TEST =	$(SRC_TEST:.c=.o);

NAME	= calc

NAME_TEST = unit_tests

CFLAGS = -I include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L lib/my -lmy
	rm -rf src/*.o

tests_run:	$(OBJ_TEST)
	make -C lib/my/
	gcc -o $(NAME_TEST) $(SRC_TEST) $(CFLAGS) -L lib/my -lmy --coverage -lcriterion
	./unit_tests

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re
