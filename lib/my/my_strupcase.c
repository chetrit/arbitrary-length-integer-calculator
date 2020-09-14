/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** puts every letter of your string in uppercase
*/

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i != len; i += 1) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
    }
    return (str);
}
