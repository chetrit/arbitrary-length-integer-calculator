/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** puts every letter of your string in lowercase
*/

int my_strlen(char *str);

char *my_strlowcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i != len; i += 1) {
        if (str[i] > 64 && str[i] < 91)
            str[i] = str[i] + 32;
    }
    return (str);
}
