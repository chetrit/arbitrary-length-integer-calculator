/*
** EPITECH PROJECT, 2019
** number
** File description:
** converts the beginning of a string into an integer
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int isnum(char const c)
{
    if (c < 48 || c > 57)
        return (0);
    return (1);
}

int less_check(char *str)
{
    int less_nb = 0;

    for (; str[0] == '-'; less_nb += 1, str += 1);
    if (less_nb % 2 == 1)
        return (1);
    return (0);
}

char *get_ptr(char *s_str, char *ptr)
{
    ptr = s_str;
    for (; ptr[0] != '+' && ptr[0] != '-' && ptr[0] != '*' && ptr[0]
        != '%' && ptr[0] != '/' && ptr[0] != '\0'; ptr += 1);
    return (ptr);
}

char *before_calc(char *str, int *condition)
{
    for (; str[0] == ' ' || str[0] == '\t' || str[0] == '+'; str += 1);
    *condition = less_check(str);
    for (; str[0] == '-'; str += 1);
    str = my_revstr(str);
    if (isnum(str[0]) == 0) {
        str = my_revstr(str);
        return (NULL);
    }
    if (!(str))
        return (NULL);
    while (isnum(str[0]) == 0 || (my_str_isnum(str) == 0 && str[1] != '\0'))
    str += 1;
    return (str);
}

int get_operand(char *str, char **endptr)
{
    int result = 0;
    int i = 0;
    int condition = 0;
    char *s_str;

    s_str = my_strdup(str);
    for (; s_str[0] == '-' || s_str[0] == ' ' || s_str[0] == '+'; s_str += 1);
    *endptr = get_ptr(s_str, *endptr);
    str = before_calc(str, &condition);
    if (!str)
        return (0);
    for (; isnum(str[i]) && str[i] != '\0'; i += 1)
        result = (str[i] - 48) * my_compute_power_rec(10, i) + result;
    str = my_revstr(str);
    if (i == 0)
        return (0);
    if (condition == 1)
        result = -result;
    for (; isnum(str[0]) == 0; str += 1);
    return (result);
    }
