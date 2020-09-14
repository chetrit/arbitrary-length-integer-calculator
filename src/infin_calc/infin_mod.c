/*
** EPITECH PROJECT, 2019
** infin_mod
** File description:
** infin_mod
*/

#include "my.h"
#include "bistromatic.h"
#include <stdlib.h>

char *nbr_to_str(int nb);
char *infin_add(char *nb1, char *nb2);
char *infin_mult(char *nb1, char *nb2);
char *infin_sub(char *nb1, char *nb2);
int minus_checker(char *str);
char *add_zeros(char *divis, char *divid, char **res, char **quot);
void minus_handle(char **x, char **y);

int get_cmp(char *nb1, char *nb2)
{
    char *result = infin_sub(nb1, my_strcat("-", nb2));

    if (my_strcmp(result, "0") == 0)
        return (0);
    if (result[0] == '-')
        return (-1);
    return (1);
}

char *particular_cases_mod(char *divis, char *divid, char *result)
{
    int cmp = get_cmp(divid, divis);

    if (get_cmp(divid, divis) == -1)
        return (divid);
    if (get_cmp(divis, "0") == 0 || get_cmp(divis, "-0") == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(84);
    }
    if (my_strcmp(divis, "1") == 0)
        return (divid);
    if (cmp < 0 || get_cmp(divid, divis) == 0)
        return ("0");
    if (cmp == 0)
        return ("1");
    return (result);
}

char *calc_mod(char *divid, char *divis, char *res)
{
    char *quotient = malloc(sizeof(char) * my_strlen(divid) + 1);
    char *mod = malloc(sizeof(char) * my_strlen(divid) + 1);
    char *s_div = my_strdup(divis);
    char *s_divid = my_strdup(divid);

    divis = add_zeros(divis, divid, &res, &quotient);
    while (get_cmp(divis, s_div) != 0) {
        if (get_cmp(divis, divid) > 0 && my_strlen(divis) != 1)
            divis[my_strlen(divis) - 1] = '\0';
        while (get_cmp(divid, infin_mult(divis, infin_add(quotient, "1"))) >= 0)
            quotient = infin_add(quotient, "1");
        mod = infin_sub(divid, my_strcat("-", infin_mult(quotient, divis)));
        res = my_strcat(res, quotient);
        divid = mod;
        quotient = "0";
    }
    if (res[0] == '0')
        res += 1;
    return (divid);
}

char *infin_mod(char *divid, char *divis)
{
    char *result = malloc(sizeof(char) * (my_strlen(divis) +
                    my_strlen(divid) + 1));
    char *s_div = my_strdup(divis);
    char *s_divid = my_strdup(divid);

    result[0] = 'q';
    result[1] = '\0';
    if (divid[0] == '-' || divis[0] == '-')
        minus_handle(&divid, &divis);
    result = particular_cases_mod(divis, divid, result);
    if (my_strcmp(s_divid, "-0") == 0)
        return ("0");
    if (result[0] == 'q')
        result = calc_mod(divid, divis, result);
    if ((s_divid[0] == '-' && s_div[0] == '-') || (s_divid[0] == '-' &&
    s_div[0] != '-') && (my_strlen(result) != 1 || result[0] != '0'))
        return (my_strcat(my_strdup("-"), result));
    return (result);
}
