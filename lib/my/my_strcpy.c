/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
