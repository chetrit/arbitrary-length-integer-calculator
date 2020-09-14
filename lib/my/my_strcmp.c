/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares two string between them
*/

int my_strlen(char const *str);

int tests_if_equals(char const *s1, char const *s2)
{
    int size_s1 = my_strlen(s1);
    int size_s2 = my_strlen(s2);

    if (size_s1 != size_s2)
        return (0);

    for (int i = 0; s1[i] != '\0'; i += 1) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int diff;

    if (tests_if_equals(s1, s2))
        return (0);

    while (s1[i] == s2[i])
        i += 1;
    diff = s1[i] - s2[i];
    return (diff);
}
