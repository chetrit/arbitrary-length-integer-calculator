/*
** EPITECH PROJECT, 2019
** main
** File description:
** bistro-matic main
*/

#include <unistd.h>
#include "my.h"
#include <stdlib.h>
#include "bistromatic.h"

char *infin_mult(char *nb1, char *nb2);

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0 || read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (expr[size - 1] < 32) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = '\0';
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7 || my_strcmp(ops, "()+-*/%") != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2 || (my_strcmp(b, "0123456789") != 0
        && my_strcmp(b, "01") != 0)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr("base ops\"()+-*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    if (size != my_strlen(expr)) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    my_putstr(bistro(av[1], av[2], expr, size));
    my_putchar('\n');
    return (EXIT_SUCCESS);
}
