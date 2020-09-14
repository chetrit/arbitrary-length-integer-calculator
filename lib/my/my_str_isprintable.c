/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** tells if your str contains only printable characters or not
*/

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int len = my_strlen(str);

    if (len == 1)
        return (1);

    for (int i = 0; i != len; i += 1) {
        if (str[i] < 32)
            return (0);
    }
    return (1);
}
