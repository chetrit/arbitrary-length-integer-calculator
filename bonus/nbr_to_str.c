/*
** EPITECH PROJECT, 2019
** nbr_to_str
** File description:
** convert a number into a string
*/

#include "my.h"
#include <stdlib.h>

char *nbr_to_str(int nb)
{
    int condition = 0;
    char *str = malloc(sizeof(char) * 12);

    if (nb == 0)
        return ("0");
    if (nb == -2147483648)
        return ("-2147483648");
    if (nb < 0) {
        nb = -nb;
        condition = 1;
    }
    for (int i = 0; nb != 0; nb /= 10) {
        str[i] = nb % 10 + 48;
        i += 1;
    }
    str = my_revstr(str);
    if (condition == 1)
        str = my_strcat(my_strdup("-"), str);
    return (str);
}
