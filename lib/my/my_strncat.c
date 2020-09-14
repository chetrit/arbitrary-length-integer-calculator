/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates two strings between each other
*/

int my_strlen(char const *str);

char *my_strncat(char * dest, char const *src, int nb)
{
    int i = 0;
    char *dest_beg = dest + my_strlen(dest);

    while (src[i] != '\0' && i != nb) {
        dest_beg[i] = src[i];
        i += 1;
    }

    dest_beg[i] = '\0';
    return (dest);
}
