/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** My Library
*/

#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str);
int check_retenue_add(char *nb1, char *nb2, int i, int retenue);
char *organize(char *nb, int max_nb, int max);

char apply_add(char *nb1, char *nb2, int i, int retenue)
{
    int n1 = nb1[i] - 48;
    int n2 = nb2[i] - 48;
    int result = n1 + n2 + retenue;

    if (result > 9) {
        result = result - 10;
        return (result + 48);
    }
    else
        return (result + 48);
}

char *addition(char *nb1, char *nb2, int max1, int max2)
{
    int max = 0;
    int i = 0;
    int retenue = 0;
    char *result;

    if (max1 >= max2)
        max = max1 + 2;
    else if (max2 > max1)
        max = max2 + 2;

    result = malloc(sizeof(char) * max + 1);
    result[max] = '\0';
    nb1 = organize(nb1, max1 - 1, max);
    nb2 = organize(nb2, max2 - 1, max);

    for (i = max - 1; i >= 0; i--) {
        result[i] = apply_add(nb1, nb2, i, retenue);
        retenue = check_retenue_add(nb1, nb2, i, retenue);
    }
    return (result);
}

char *remove_minus(char *nb, int size)
{
    int i = 1;
    int j = 0;
    char *new_nb = malloc(sizeof(char) * (size + 1));

    for (i = 1; i < size; i++) {
        new_nb[j] = nb[i];
        j++;
    }
    new_nb[i] = '\0';
    return (new_nb);
}

char *final_add(char *result, int minus)
{
    int i = 0;
    int j = 0;

    while (result[i] == '0')
        i++;
    if (minus == 1) {
        result[j] = '-';
        j++;
    }
    while (result[i - 1] != '\0') {
        result[j] = result[i];
        i++;
        j++;
    }
    result[j] = '\0';
    return (result);
}

char *infin_add(char *nb1, char *nb2)
{
    int size1 = my_strlen(nb1);
    int size2 = my_strlen(nb2);
    char *result = malloc(sizeof(char) * (size1 + size2));
    int minus = 0;

    if (nb1[0] == '-' && nb2[0] == '-') {
        nb1 = remove_minus(nb1, size1);
        nb2 = remove_minus(nb2, size2);
        size1 = my_strlen(nb1);
        size2 = my_strlen(nb2);
        minus = 1;
    }
    result = addition(nb1, nb2, size1, size2);
    result = final_add(result, minus);
    return (result);
}
