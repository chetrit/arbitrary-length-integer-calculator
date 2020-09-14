/*
** EPITECH PROJECT, 2019
** infin_sub_extention
** File description:
** My Library
*/

#include <stdlib.h>
#include "my.h"

int who_is_signed(char *nb1, char *nb2)
{
    if (nb1[0] == '-')
        return (0);
    else if (nb2[0] == '-')
        return (1);
}

int who_is_bigger(char *nb1, char *nb2)
{
    int h = 0;
    int order = 0;

    while (nb1[h] != '\0') {
        if (nb1[h] == nb2[h])
            h++;
        else if (nb1[h] > nb2[h])
            return (0);
        if (nb1[h] < nb2[h])
            return (1);
    }
    return (2);
}

int check_retenue_sous(char *nb1, char *nb2, int i, int retenue)
{
    int n1 = nb1[i] - 48;
    int n2 = nb2[i] - 48;
    int result = 0;
    int order = 0;

    order = who_is_bigger(nb1, nb2);
    if (order == 0 || order == 2)
        result = n1 - (n2 + retenue);
    else if (order == 1)
        result = n2 - (n1 + retenue);
    if (result < 0)
        return (1);
    else
        return (0);
}
