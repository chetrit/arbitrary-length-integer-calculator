/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** tells if your str contains only alphabetical characters or not
*/

int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i != len; i += 1) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
    }
    return (1);
}
