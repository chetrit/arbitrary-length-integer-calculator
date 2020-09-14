/*
** EPITECH PROJECT, 2019
** infin_sub
** File description:
** My Library
*/

#include <stdlib.h>
#include "my.h"

int my_strlen(char const *str);
char *organize(char *nb, int max_nb, int max);
int who_is_signed(char *nb1, char *nb2);
int who_is_bigger(char *nb1, char *nb2);
int check_retenue_sous(char *nb1, char *nb2, int i, int retenue);

char apply_sous(char *nb1, char *nb2, int i, int retenue)
{
    int n1 = nb1[i] - 48;
    int n2 = nb2[i] - 48;
    int order = 0;
    int result = 0;

    order = who_is_bigger(nb1, nb2);
    if (order == 0 || order == 2)
        result = n1 - (n2 + retenue);
    else if (order == 1)
        result = n2 - (n1 + retenue);
    if (result < 0) {
        result = result + 10;
        return (result + 48);
    }
    else
        return (result + 48);
}

char *soustraction(char *nb1, char *nb2, int max1, int max2)
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
        result[i] = apply_sous(nb1, nb2, i, retenue);
        retenue = check_retenue_sous(nb1, nb2, i, retenue);
    }
    return (result);
}

char *remove_signs(char *nb, int size)
{
    int i = 1;
    int j = 0;
    char *new_nb = malloc(sizeof(char) * (size + 1));

    if (nb[0] == '+' || nb[0] == '-') {
        for (i = 1; i < size; i++) {
            new_nb[j] = nb[i];
            j++;
        }
        new_nb[i] = '\0';
        return (new_nb);
    }
    return (nb);
}

char *final_sous(char *result, int order, int sign)
{
    int i = 0;
    int j = 0;

    for (; result[i] == '0'; i++);
    if (order == 0 && sign == 0) {
        result[j] = '-';
        j++;
    } else if (order == 1 && sign == 1) {
        result[j] = '-';
        j++;
    }
    if (order == 2) {
        result[0] = '0';
        result[1] = '\0';
        return (result);
    }
    while (result[i - 1] != '\0') {
        result[j++] = result[i++];
    }
    return (result);
}

char *infin_sub(char *nb1, char *nb2)
{
    int size1 = my_strlen(nb1);
    int size2 = my_strlen(nb2);
    char *result = malloc(sizeof(char) * (size1 + size2 + 1));
    int order = 0;
    int sign = who_is_signed(nb1, nb2);
    int max = 0;

    nb1 = remove_signs(nb1, size1);
    nb2 = remove_signs(nb2, size2);
    size1 = my_strlen(nb1);
    size2 = my_strlen(nb2);
    result = soustraction(nb1, nb2, size1, size2);
    if (size1 >= size2)
        max = size1 + 2;
    else if (size2 > size1)
        max = size2 + 2;
    nb1 = organize(nb1, size1 - 1, max);
    nb2 = organize(nb2, size2 - 1, max);
    order = who_is_bigger(nb1, nb2);
    result = final_sous(result, order, sign);
    return (result);
}
