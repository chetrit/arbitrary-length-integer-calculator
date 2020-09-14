/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** My Library
*/

#include <stdlib.h>
#include "my.h"

char *my_output_nbr(int nb)
{
    int i = 0;
    int negative;
    char *str = malloc(sizeof(char) * 50);

    if (nb < 0) {
        negative = 1;
        nb = nb * -1;
    }
    for (; nb > 9; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[i] = nb + 48;
    if (negative == 1) {
        ++i;
        str[i] = 45;
    }
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}
