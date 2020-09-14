/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Function that displays characters
*/

#include "my.h"
#include <stdlib.h>

char *infin_add(char *nb1, char *nb2);
char *infin_sub(char *nb1, char *nb2);
char *infin_mult(char *nb1, char *nb2);
char *infin_div(char *nb1, char *nb2);
char *infin_mod(char *nb1, char *nb2);
int check_op(char **array, int state, int i);

int first_op(char **array, int state)
{
    int j = 0;
    int size = my_strlen(array[state]);

    for (int i = 1; i < size; i++) {
        if (array[state][i] == '+') {
            j = i;
            i = size - 1;
        }
        else if (array[state][i] == '-') {
            j = i;
            i = size - 1;
        }
    }
    return (j);
}

int first_sudo_op(char **array, int state)
{
    int j = 0;
    int size = my_strlen(array[state]);

    for (int i = 0; i < size; i++) {
        if (array[state][i] == '*') {
            j = i;
            i = size - 1;
        }
        if (array[state][i] == '/') {
            j = i;
            i = size - 1;
        }
        if (array[state][i] == '%') {
            j = i;
            i = size - 1;
        }
    }
    return (j);
}

char *operation(char **array, int state, char *first_arg, char *second_arg)
{
    char *str = malloc(sizeof(char) * 50);
    int j = first_op(array, state);
    int i = j - 1;

    while (i > 0 && check_op(array, state, i) == 0)
        i--;
    if (array[state][j] == '+' && array[state][i] != '-')
        str = infin_add(first_arg, second_arg);
    else if (array[state][j] == '-' && array[state][i] == '-')
        str = infin_add(first_arg, second_arg);
    else
        str = infin_sub(first_arg, second_arg);
    return (str);
}

char *sudo_operation(char **array, int state, char *first_arg, char *second_arg)
{
    char *str = malloc(sizeof(char) * 50);
    int j = first_sudo_op(array, state);
    int i = j - 1;

    while (i > 0 && check_op(array, state, i) == 0)
        i--;
    if (array[state][j] == '*')
        str = infin_mult(first_arg, second_arg);
    if (array[state][j] == '/')
        str = infin_div(first_arg, second_arg);
    if (array[state][j] == '%')
        str = infin_mod(first_arg, second_arg);
    if (str[0] != '-' && i != 0)
        str = my_strcat("+", str);
    return (str);
}
