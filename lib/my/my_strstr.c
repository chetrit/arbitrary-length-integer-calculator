/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** a copy of the string.h function str
*/

int my_strlen(char const *str);

int str_corresponds(char *str, char const *to_find)
{
    int len = my_strlen(to_find);

    if (my_strlen(str) < my_strlen(to_find))
        return (0);
    for (int i = 0; to_find[i] != '\0'; i += 1) {
        if (to_find[i] != str[i]) {
            return (0);
        }
    }
    return (1);
}

char *str_extent(int i, char *str, char const *to_find)
{
    if (str[i] == to_find[0]) {
        if (str_corresponds(&str[i], to_find) == 1)
            return (&str[i]);
    }
    return (str);
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str_extent(i, str, to_find) != str)
            return (str_extent(i, str, to_find));
        i += 1;
    }
    return (0);
}
