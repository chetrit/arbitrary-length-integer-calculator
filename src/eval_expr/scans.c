/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Print an ascii
*/

#include "my.h"

int check_op(char **array, int state, int i)
{
    int j = 0;
    int size = my_strlen(array[state]);

    if (array[state][i] == '*')
        return (1);
    if (array[state][i] == '/')
        return (1);
    if (array[state][i] == '%')
        return (1);
    if (array[state][i] == '+')
        return (1);
    if (array[state][i] == '-')
        return (1);
    return (0);
}

int operand_scan(char **array, int state)
{
    int oper = 0;

    for (int i = 1; array[state][i] != '\0'; i++) {
        if (array[state][i] == '+')
            oper++;
        else if (array[state][i] == '-')
            oper++;
    }
    return (oper);
}

int sudo_operand_scan(char **array, int state)
{
    int oper = 0;

    for (int i = 1; array[state][i] != '\0'; i++) {
        if (array[state][i] == '*')
            oper++;
        if (array[state][i] == '/')
            oper++;
        if (array[state][i] == '%')
            oper++;
    }
    return (oper);
}

int bracket_scan(char **array, int state)
{
    int brack = 0;

    for (int i = 0; array[state][i] != '\0'; i++) {
        if (array[state][i] == ')')
            brack++;
    }
    return (brack);
}
