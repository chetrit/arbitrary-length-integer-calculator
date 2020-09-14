/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** bistromatic
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

char *eval_expr(char *expr);
char *converter(char *base, char *operators, char *expr);
char *transform_minus(char *expr, int *i);
int return_if_plus_or_minus(char *expr);
int isnum(char const c);

char *expr_b_stuff(char *expr_b, int *i)
{
    expr_b = &expr_b[*i];
    expr_b = my_revstr(expr_b);
    for (; expr_b[0] != '*' && expr_b[0] != '%' && expr_b[0] != '/'; expr_b++);
    return (expr_b);
}

char *minus_check(char *expr)
{
    char *expr_b;
    char *expr_e = my_strdup(expr);
    char operator;
    int i = 0;

    if (return_if_plus_or_minus(expr) == 1)
        return (expr);
    expr_b = transform_minus(expr_e, &i);
    expr_e = my_strdup(expr);
    expr_b = expr_b_stuff(expr_b, &i);
    operator = expr_b++[0];
    expr_b = my_revstr(expr_b);
    expr = my_strdup(expr_b);
    for (; expr_e[0] != '*' && expr_e[0] != '%' && expr_e[0] != '/'; expr_e++);
    i = 0;
    expr_e++;
    expr_e = transform_minus(expr_e, &i);
    expr = my_strncat(expr, &operator, 1);
    expr = my_strcat(expr, &expr_e[i]);
    return (expr);
}

int error_check(char *base, char *operators, char *expr)
{
    int j = 0;
    int k = 0;

    for (int i = 0; expr[i] != '\0'; i += 1) {
        if (expr[i] == '(')
            j += 1;
        if (expr[i] == ')')
            k += 1;
    }
    if (j != k)
        return (84);
    return (0);
}

int error_check2(char *base, char *operators, char *expr)
{
    for (int i = 0; expr[i] != '\0'; i += 1) {
        if ((expr[i] == '*' || expr[i] == '%' || expr[i] == '/'
            || expr[i] == '+') && (expr[i + 1] == '*' || expr[i + 1] == '/'
                || expr[i + 1] == '%'))
            return (84);
        if (expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/'
            && expr[i] != '%' && expr[i] != '(' && expr[i] != ')'
            && isnum(expr[i]) != 1)
            return (84);
    }
    return (0);
}

char *bistro(char *base, char *operators, char *expr, unsigned int size)
{
    char *result;
    int compteur = 0;

    if (error_check(base, operators, expr) == 84 ||
        error_check2(base, operators, expr) == 84) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    for (int i = 0; expr[i] != '\0'; i += 1) {
        if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
            compteur += 1;
    }
    if (compteur == 1)
        expr = minus_check(expr);
    result = eval_expr(expr);
    return (result);
}
