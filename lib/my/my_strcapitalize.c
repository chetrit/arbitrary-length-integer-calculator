/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

int my_strlen(char *str);

char *my_strlowcase(char *str);

char str_char_upcase(char c)
{
    if (c > 96 && c < 123)
        c = c - 32;
    return (c);
}

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);

    my_strlowcase(str);

    if (str[0] > 96 && str[0] < 123)
        str[0] = str[0] - 32;
    for (int i = 0; i <= len; i += 1) {
        if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
            str[i + 1] = str_char_upcase(str[i+1]);
    }
    return (str);
}
