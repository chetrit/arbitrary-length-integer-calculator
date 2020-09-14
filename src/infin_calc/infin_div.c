/*
** EPITECH PROJECT, 2019
** infin_div
** File description:
** infin_div
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

char *nbr_to_str(int nb);
char *infin_add(char *nb1, char *nb2);
char *infin_mult(char *nb1, char *nb2);
char *infin_sub(char *nb1, char *nb2);
int minus_checker(char *str);
int get_cmp(char *nb1, char *nb2);

char *particular_cases(char *divis, char *divid, char *result)
{
    int cmp = get_cmp(divid, divis);

    if (my_strcmp(divis, "0") == 0 || my_strcmp(divis, "-0") == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    if (my_strcmp(divis, "1") == 0)
        return (divid);
    if (cmp < 0)
        return ("0");
    if (cmp == 0)
        return ("1");
    return (result);
}

char *add_zeros(char *divis, char *divid, char **res, char **quot)
{
    *res = "\0";
    *quot = "0";
    while (my_strlen(divis) != my_strlen(divid))
        divis = my_strcat(divis, "0");
    if (my_strlen(divis) == my_strlen(divid))
        divis = my_strcat(divis, "0");
    return (divis);
}

char *calc(char *divid, char *divis, char *res)
{
    char *quot = malloc(sizeof(char) * my_strlen(divid) + 1);
    char *mod = malloc(sizeof(char) * my_strlen(divid) + 1);
    char *s_div = my_strdup(divis);
    char *s_divid = my_strdup(divid);

    divis = add_zeros(divis, divid, &res, &quot);
    while (get_cmp(divis, s_div) != 0) {
        if (get_cmp(divis, divid) > 0 && my_strlen(divis) != 1)
            divis[my_strlen(divis) - 1] = '\0';
        while (get_cmp(divid, infin_mult(divis, infin_add(quot, "1"))) >= 0)
            quot = infin_add(quot, "1");
        mod = infin_sub(divid, my_strcat("-", infin_mult(quot, divis)));
        res = my_strcat(res, quot);
        divid = mod;
        quot = "0";
    }
    if (res[0] == '0')
        res += 1;
    return (res);
}

void minus_handle(char **x, char **y)
{
    if (*x[0] == '-' && *y[0] == '-') {
        (*x)++;
        (*y)++;
        return;
    }
    if (*x[0] == '-')
        (*x)++;
    if (*y[0] == '-')
        (*y)++;
}

char *infin_div(char *divid, char *divis)
{
    char *result = malloc(sizeof(char) *
        (my_strlen(divis) + my_strlen(divid) + 1));
    char *s_div = my_strdup(divis);
    char *s_divid = my_strdup(divid);

    result[0] = 'q';
    result[1] = '\0';
    if (divid[0] == '-' || divis[0] == '-')
    minus_handle(&divid, &divis);
    result = particular_cases(divis, divid, result);
    if (my_strcmp(s_divid, "-0") == 0)
        return ("0");
    if (result[0] == 'q')
        result = calc(divid, divis, result);
    if ((s_divid[0] == '-' && s_div[0] != '-') ||
        (s_divid[0] != '-' && s_div[0] == '-'))
        return (my_strcat(my_strdup("-"), result));
    return (result);
}
