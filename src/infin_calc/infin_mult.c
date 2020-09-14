/*
** EPITECH PROJECT, 2019
** infin_mult.c
** File description:
** multiplication infinie
*/

#include <stdlib.h>
#include "../../include/my.h"

char *infin_add(char *nb1, char *nb2);

int minus_checker(char *str)
{
    if (str[0] == '-')
        return (1);
    else
        return (0);
}

char *first_number(char *x, char y, char *final)
{
    int i;
    int ret = 0;
    int tmp = 0;

    for (i = 0; x[i] != '\0'; i++) {
        tmp = ATN(x[i]) * ATN(y) + ret;
        ret = tmp / 10;
        tmp = tmp % 10;
        final[i] = NTA(tmp);
    }
    if (ret > 0) {
        final[i] = NTA(ret);
        i += 1;
    }
    final[i] = '\0';
    return (my_revstr(final));
}

char *one_one_pos(char *x, char *y, char *final, char *result)
{
    int j = 0;
    int i = 0;
    char **result_array = malloc(sizeof(char *)
                        * (my_strlen(x) + my_strlen(y) + 2));
    result = "0";
    x = my_revstr(x);
    y = my_revstr(y);
    for (; y[i] != '\0'; i += 1) {
        final = first_number(x, y[i], final);
        for (j = 0; j < i; j += 1)
            final = my_strcat(final, "0");
        result_array[i] = my_strdup(final);
    }
    result_array[i+1] = NULL;
    for (int k = 0; k < i; k += 1)
        result = infin_add(result, result_array[k]);
    return (result);
}

char *infin_mult2(char *x, char *y)
{
    char *final = malloc(sizeof(char) * (my_strlen(x) + my_strlen(y) + 1));
    char *result = malloc(sizeof(char) * (my_strlen(x) + my_strlen(y) + 1));

    if (my_strcmp(x, "0") == 0 || my_strcmp(y, "0") == 0
    || my_strcmp(y, "-0") == 0 || my_strcmp(x, "-0") == 0)
        return ("0");
    if (minus_checker(x) == 0 && minus_checker(y) == 0)
        result = one_one_pos(x, y, final, result);
    if (minus_checker(x) == 1 && minus_checker(y) == 1)
        result = one_one_pos(&(x[1]), &(y[1]), final, result);
    if (minus_checker(x) == 1 && minus_checker(y) == 0)
        result = one_one_pos(&(x[1]), y, final, result);
    if (minus_checker(x) == 0 && minus_checker(y) == 1)
        result = one_one_pos(x, &(y[1]), final, result);
    if ((minus_checker(x) == 1 && minus_checker(y) == 0) ||
        (minus_checker(x) == 0 && minus_checker(y) == 1))
        return (my_strcat(my_strdup("-"), result));
    return (result);
}

char *infin_mult(char *nb1, char *nb2)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2) + 1));

    result = infin_mult2(my_strdup(nb1), my_strdup(nb2));
    return (result);
}
