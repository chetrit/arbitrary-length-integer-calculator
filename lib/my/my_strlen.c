/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** tells the lengh of your string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
