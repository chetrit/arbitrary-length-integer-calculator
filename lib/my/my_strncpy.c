/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n character from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n == 0) {
        dest[0] = '\0';
        return (dest);
    }
    while (i != n) {
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}
