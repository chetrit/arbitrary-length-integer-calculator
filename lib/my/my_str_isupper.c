/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** tells if your str contains only upper alphabetical characters or not
*/

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i != len; i += 1) {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
    }
    return (1);
}
