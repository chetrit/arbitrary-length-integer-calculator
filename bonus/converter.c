/*
** EPITECH PROJECT, 2019
** converter
** File description:
** convert my input str into normal format for bistromatic
*/

#include "my.h"
#include <stdlib.h>

char *infin_pow(char *nb, char *p);
char *nbr_to_str(int nb);
char *infin_add(char *nb1, char *nb2);
char *infin_mult(char *nb1, char *nb2);
int isnum(char const c);
char *to_normal_ops(char *operators);
int get_pos(char *expr, char *base);
char exprj(char *base, int *array, char *expr, int j);

int get_diff(char base, int *i)
{
    int j = base;
    int k = 0;

    if (base == '0' + *i)
        return (0);
    if (base < '0' + *i) {
        for (k = 0; j < '0' + *i; j++)
            k += 1;
        return (k);
    }
    for (k = 0; j > '0' + *i; j--)
        k += 1;
    return (-k);
}

char *to_digits(char *expr, char *base)
{
    int *array = malloc(sizeof(int) * (my_strlen(base) + 1));

    for (int i = 0; base[i] != '\0'; i++)
        array[i] = get_diff(base[i], &i);
    for (int j = 0; expr[j] != '\0'; j += 1) {
        expr[j] = exprj(base, array, expr, j);
    }
    return (expr);
}

char *to_base_10(char *nb, int base)
{
    int size = my_strlen(nb);
    char *result = malloc(sizeof(char) * my_strlen(nb) + 1);
    int j = 0;
    char nbi[2];

    result = "0";
    nbi[0] = nb[0];
    nbi[1] = '\0';
    for (int i = my_strlen(nb); i > 0; i -= 1) {
        nbi[0] = nb[i-1];
        result = infin_add(result , infin_mult(my_strdup(nbi),
        infin_pow(nbr_to_str(base), nbr_to_str(j))));
        j += 1;
    }
    return (result);
}

char *converter_base_10(char *expr, char *base)
{
    char **endptr;
    char *nb = malloc(sizeof(char) * my_strlen(expr) + 1);
    int i = 0;
    int base_nb = my_strlen(base);

    nb = "0";
    for (i = 0; isnum(expr[i]) == 0; i += 1);
    for (int j = 0; isnum(expr[i]); i += 1) {
        nb[j] = expr[i];
        j += 1;
    }
    nb = to_base_10(nb, base_nb);
    return (expr);
}

char *converter(char *base, char *operators, char *expr)
{
    expr = to_digits(expr, base);
    expr = converter_base_10(expr, base);
    operators = to_normal_ops(operators);
    return (expr);
}
