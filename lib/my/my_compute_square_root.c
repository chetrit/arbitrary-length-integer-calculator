/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** do a square root of your number
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb == 0) {
        return (0);
    }
    while (i * i < nb) {
        i += 1;
    }
    if ((i * i) > nb)
        return (0);
    if (i*i == nb)
    return (i);
}
