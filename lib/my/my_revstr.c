/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** return your string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char c;

    if (len == 1)
        return (str);
    for (int i = 0, j = len-1; i < j; i += 1, j -= 1) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return (str);
}
