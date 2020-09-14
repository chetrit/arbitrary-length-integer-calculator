/*
** EPITECH PROJECT, 2019
** bracket.c
** File description:
** Function
*/

#include <stdlib.h>
#include "my.h"

char *operand(char *str, int size);
int bracket_scan(char **array, int state);
char **final_apply_bracket(char **array, int i, int ptr_min, int ptr_max);

int rush_closed_bracket(char **array, int state)
{
    int ptr_max;

    for (int i = 0; array[state][i] != '\0'; i++) {
        if (array[state][i] == ')') {
            return (i);
        }
    }
}

int back_open_bracket(char **array, int state, int i)
{
    int ptr_min;

    for (i = i - 1; i > -1; i--) {
        if (array[state][i] == '(') {
            return (i);
        }
    }
}

char *clean_bracket(char *str, int size, int ptr_min, int ptr_max)
{
    char *rezult = malloc(sizeof(char) * (size) + 1);
    int i = 0;

    for (ptr_min = ptr_min + 1; ptr_min < ptr_max; ptr_min++) {
        rezult[i] = str[ptr_min];
        i++;
    }
    rezult[i + 1] = '\0';
    return (rezult);
}

char **apply_bracket(char **array, int size, char *rez, int i)
{
    int ptr_max = rush_closed_bracket(array, i);
    int p_m = back_open_bracket(array, i, ptr_max);
    char *tmp = malloc(sizeof(char) * (size) + 1);
    int j = 0;

    tmp = clean_bracket(array[i - 1], size, p_m, ptr_max);
    rez = operand(tmp, size);
    if (rez[0] == '-' && array[i][p_m - 1] == '-' && array[i][p_m - 2] == '(') {
        p_m--;
        j++;
    }
    if (rez[0] == '-' && array[i][p_m - 1] == '-' && array[i][p_m - 2] != '(') {
        rez[0] = '+';
        p_m--;
    }
    for (; rez[j] != '\0'; j++, p_m++) {
        array[i][p_m] = rez[j];
    }
    array = final_apply_bracket(array, i, p_m, ptr_max);
    return (array);
}

char *bracket(char const *str, int size)
{
    int i = 0;
    int j = 0;
    char *rez = malloc(sizeof(char) * (size) + 1);
    char *tmp = malloc(sizeof(char) * (size) + 1);
    char **array = malloc(sizeof(char) * 1000);

    array[0] = malloc(sizeof(char) * (size) + 1);
    my_strcpy(array[0], str);
    while (bracket_scan(array, i) != 0) {
        ++i;
        array[i] = malloc(sizeof(char) * (size) + 1);
        my_strcpy(array[i], array[i - 1]);
        array = apply_bracket(array, size, rez, i);
    }
    rez = operand(array[i], size);
    return (rez);
}
