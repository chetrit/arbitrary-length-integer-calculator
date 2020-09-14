/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Print an ascii
*/

#include "my.h"

int check_op(char **array, int state, int i);
int first_op(char **array, int state);
int first_sudo_op(char **array, int state);

int goto_ptr_min(char **array, int state)
{
    int j = 0;
    int size = my_strlen(array[state]);

    j = first_op(array, state);
    j--;
    while (j > 0 && check_op(array, state, j) == 0)
        j--;
    if (j == 0)
        return (0);
    else
        return (j + 1);
}

int goto_ptr_max(char **array, int state)
{
    int j = 0;
    int size = my_strlen(array[state]);

    j = first_op(array, state);
    j++;
    while (j < size && check_op(array, state, j) == 0)
        j++;
    if (j == size - 1)
        return (size - 2);
    else
        return (j - 1);
}

int goto_sudo_ptr_min(char **array, int state)
{
    int j = 0;
    int size = my_strlen(array[state]);

    j = first_sudo_op(array, state);
    j--;
    while (j > 0 && check_op(array, state, j) == 0)
        j--;
    if (j == 0)
        return (0);
    else if (array[state][j] == '-')
        return (j);
    else
        return (j + 1);
}

int goto_sudo_ptr_max(char **array, int state)
{
    int j = 0;
    int size = my_strlen(array[state]);

    j = first_sudo_op(array, state);
    j = j + 2;
    while (j < size && check_op(array, state, j) == 0)
        j++;
    if (j == size - 1)
        return (size - 2);
    else
        return (j - 1);
}
