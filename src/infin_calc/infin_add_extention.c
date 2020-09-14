/*
** EPITECH PROJECT, 2019
** infin_add_extention
** File description:
** My Library
*/

#include <stdlib.h>
#include "my.h"

int check_retenue_add(char *nb1, char *nb2, int i, int retenue)
{
    int n1 = nb1[i] - 48;
    int n2 = nb2[i] - 48;
    int result = n1 + n2 + retenue;

    if (result > 9)
        return (1);
    else
        return (0);
}
