/*
** EPITECH PROJECT, 2019
** bracket_extand.c
** File description:
** Function
*/

#include <stdlib.h>
#include "my.h"

char **final_apply_bracket(char **array, int i, int ptr_min, int ptr_max)
{
    ptr_max++;
    for (; array[i - 1][ptr_max] != '\0'; ptr_min++, ptr_max++)
        array[i][ptr_min] = array[i - 1][ptr_max];
    array[i][ptr_min] = '\0';
    return (array);
}
