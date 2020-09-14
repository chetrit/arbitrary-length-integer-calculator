/*
** EPITECH PROJECT, 2019
** bistro2
** File description:
** bistromatic
*/

#include <stdlib.h>
#include "my.h"
#include "bistromatic.h"

int isnum(char const c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}

char *transform_minus(char *expr, int *i)
{
    int less_counter = 0;

    for (; expr[*i] == '-' || expr[*i] == '+'; (*i)++) {
        if (expr[*i] == '-')
            less_counter += 1;
    }
    if (less_counter % 2 == 1) {
        expr[*i-1] = '-';
        *i -= 1;
    }
    return (expr);
}

int return_if_plus_or_minus(char *expr)
{
    int compteur = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
            compteur += 1;
    }
    if (compteur == 0)
        return (1);
    return (0);
}
