/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compares two string between them
*/

int my_strlen_n(char const *str, int n)
{
    int i = 0;

    while (str[i] != '\0' && i != n)
        i += 1;
    return (i);
}

int tests_if_equals2(char const *s1, char const *s2, int n)
{
    int size_s1 = my_strlen_n(s1, n);
    int size_s2 = my_strlen_n(s2, n);

    if (size_s1 != size_s2)
        return (0);

    for (int i = 0; s1[i] != s1[n]; i += 1) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;
    int diff;

    if (tests_if_equals2(s1, s2, n))
        return (0);

    while (j < n) {
        while (s1[i] == s2[i])
            i += 1;
        j += 1;
    }
    diff = s1[i] - s2[i];
    return (diff);
}
