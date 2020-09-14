/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Function that displays characters
*/

#include <stdlib.h>
#include "my.h"

int check_op(char **array, int state, int i);
int first_sudo_op(char **array, int state);
int first_op(char **array, int state);

char *arg_before_op(char **array, int state)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(array[state]);
    char *result = malloc(sizeof(char) * (size + 1));

    j = first_op(array, state);
    j--;
    while (j > 0 && check_op(array, state, j) == 0)
        j--;
    if (array[state][j] == '-') {
        result[i] = array[state][j];
        i++;
        j++;
    } else if (j != 0)
        j++;
    for (; j < size - 1 && check_op(array, state, j) == 0; j++) {
        result[i] = array[state][j];
        i++;
    }
    return (result);
}

char *arg_after_op(char **array, int state)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(array[state]);
    char *result = malloc(sizeof(char) * (size + 1));

    j = first_op(array, state);
    if (array[state][j] == '-') {
        result[i] = array[state][j];
        i++;
    }
    j++;
    while (j < size && check_op(array, state, j) == 0) {
        result[i] = array[state][j];
        i++;
        j++;
    }
    return (result);
}

char *arg_before_sudo_op(char **array, int state)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(array[state]);
    char *result = malloc(sizeof(char) * (size + 1));

    j = first_sudo_op(array, state);
    j--;
    for (; j > 0 && check_op(array, state, j) == 0; j--);
    if (array[state][j] == '-') {
        result[i] = array[state][j];
        i++;
        j++;
    } else if (j != 0)
        j++;
    while (j < size - 1 && check_op(array, state, j) == 0) {
        result[i] = array[state][j];
        i++;
        j++;
    }
    return (result);
}

char *arg_after_sudo_op(char **array, int state)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(array[state]);
    char *result = malloc(sizeof(char) * (size + 1));

    j = first_sudo_op(array, state);
    j++;
    if (array[state][j] == '-') {
        result[i] = array[state][j];
        i++;
        j++;
    }
    while (j < size && check_op(array, state, j) == 0) {
        result[i] = array[state][j];
        i++;
        j++;
    }
    return (result);
}
