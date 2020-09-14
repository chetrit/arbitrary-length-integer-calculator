/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Function that calculate
*/

#include <stdlib.h>
#include "my.h"

int rush_closed_bracket(char **array, int state);
int back_open_bracket(char **array, int state);
int bracket_scan(char **array, int state);
char *bracket(char const *str, int size);
char *operand(char *str, int size);

char *final_clean(char *str)
{
    int i = 0;
    int j = 1;
    int size = my_strlen(str);
    char *tmp = malloc(sizeof(char) * (size) * 1);

    for (i = 0; i < size; i++) {
        tmp[i] = str[j];
        j++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *remove_spaces(char const *str, int size)
{
    char *clean_str = malloc(sizeof(char) * (size) + 1);
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] != ' ') {
            clean_str[j] = str[i];
            j++;
        }
    }
    return (clean_str);
}

char *eval_expr(char const *str)
{
    int size = my_strlen(str);
    char *result = malloc(sizeof(char) * (size) * 2);
    int finalnb = 0;

    str = remove_spaces(str, size);
    result = bracket(str, size);
    if (result[0] == '+')
        result = final_clean(result);
    return (result);
}
