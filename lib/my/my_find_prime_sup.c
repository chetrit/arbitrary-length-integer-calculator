/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** returns the smallest prime number greater or
** equal to the number given as parameter
*/

int my_is_prime2(int nb)
{
    if (nb == 1)
        return (0);
    if (nb <= 0)
        return (0);
    for (int i = 2; i < nb; i += 1) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    long i = nb;

    if (i > 2147483647 || i < -2147483648)
        return (0);
    while (my_is_prime2(i) != 1) {
        my_is_prime2(i);
        i += 1;
    }
    return (i);
}
