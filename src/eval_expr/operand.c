/*
** EPITECH PROJECT, 2019
** operand.c
** File description:
** Function
*/

#include <stdlib.h>
#include "my.h"

char *my_output_nbr(int nb);
char *arg_before_op(char **array, int state);
char *arg_after_op(char **array, int state);
char *arg_before_sudo_op(char **array, int state);
char *arg_after_sudo_op(char **array, int state);
int goto_ptr_min(char **array, int state);
int goto_ptr_max(char **array, int state);
int goto_sudo_ptr_min(char **array, int state);
int goto_sudo_ptr_max(char **array, int state);
char *sudo_operation(char **array, int state,
                    char *first_arg, char *second_arg);
char *operation(char **array, int state, char *first_arg, char *second_arg);
int operand_scan(char **array, int state);
int sudo_operand_scan(char **array, int state);

int check_ptr_min(char **array, char *result, int i, int ptr_min)
{
    if (result[0] == '-' && array[i][ptr_min - 1] == '+')
        ptr_min--;
    else if (result[0] == '+' && array[i][ptr_min - 1] == '+')
        ptr_min--;
    return (ptr_min);
}

char **first_apply(char **array, int size, char *result, int i)
{
    char *first_arg = arg_before_sudo_op(array, i);
    char *second_arg = arg_after_sudo_op(array, i);
    int ptr_min = goto_sudo_ptr_min(array, i);
    int ptr_max = goto_sudo_ptr_max(array, i);

    result = sudo_operation(array, i, first_arg, second_arg);
    ptr_min = check_ptr_min(array, result, i, ptr_min);
    for (int j = 0; result[j] != '\0'; j++) {
        array[i][ptr_min] = result[j];
        ptr_min++;
    }
    ptr_max++;
    while (array[i - 1][ptr_max] != '\0') {
        array[i][ptr_min] = array[i - 1][ptr_max];
        ptr_min++;
        ptr_max++;
    }
    array[i][ptr_min] = '\0';
    return (array);
}

char **second_apply(char **array, int size, char *result, int i)
{
    int j = 0;
    char *first_arg = arg_before_op(array, i);
    char *second_arg = arg_after_op(array, i);
    int ptr_min = goto_ptr_min(array, i);
    int ptr_max = goto_ptr_max(array, i);

    result = operation(array, i, first_arg, second_arg);
    while (result[j] != '\0') {
        array[i][ptr_min] = result[j];
        ptr_min++;
        j++;
    }
    ptr_max++;
    while (array[i - 1][ptr_max] != '\0') {
        array[i][ptr_min] = array[i - 1][ptr_max];
        ptr_min++;
        ptr_max++;
    }
    array[i][ptr_min] = '\0';
    return (array);
}

char *operand(char *str, int size)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (size) + 1);
    char **array = malloc(sizeof(char) * 1000);

    array[0] = malloc(sizeof(char) * (size) + 1);
    my_strcpy(array[0], str);
    while (sudo_operand_scan(array, i) != 0) {
        ++i;
        array[i] = malloc(sizeof(char) * (size) + 1);
        my_strcpy(array[i], array[i - 1]);
        array = first_apply(array, size, result, i);
    }
    while (operand_scan(array, i) != 0) {
        ++i;
        array[i] = malloc(sizeof(char) * (size) + 1);
        my_strcpy(array[i], array[i - 1]);
        array = second_apply(array, size, result, i);
    }
    return (array[i]);
}
