/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings between each other
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *d_beg = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) +1));

    d_beg = my_strcpy(d_beg, dest);
    for (; d_beg[i] != '\0'; i += 1);
    while (src[j] != '\0') {
        d_beg[i] = src[j];
        i += 1;
        j += 1;
    }
    d_beg[i] = '\0';
    return (d_beg);
}
