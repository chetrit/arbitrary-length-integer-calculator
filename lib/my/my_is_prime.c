/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** tells wheter the number is prime or not
*/

int my_is_prime(int nb)
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
