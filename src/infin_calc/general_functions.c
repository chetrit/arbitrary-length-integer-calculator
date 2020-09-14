/*
** EPITECH PROJECT, 2019
** general_functions
** File description:
** My Library
*/

#include <stdlib.h>
#include "my.h"

char *organize(char *nb, int max_nb, int max)
{
    char *clean_nb = malloc(sizeof(char) * max + 1);

    clean_nb[max] = '\0';
    max--;
    while (max_nb >= 0) {
        clean_nb[max] = nb[max_nb];
        max--;
        max_nb--;
    }
    while (max >= 0) {
        clean_nb[max] = '0';
        max--;
    }
    return (clean_nb);
}
