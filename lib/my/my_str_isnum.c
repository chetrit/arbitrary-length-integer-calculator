/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** tells if your str contains only numerical characters or not
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i != len; i += 1) {

        if (str[i] < 48 || str[i] > 57) {
        return (0);
        }
    }
    return (1);
}
