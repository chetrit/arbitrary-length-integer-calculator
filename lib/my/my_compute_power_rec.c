/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** equivalent of power fonction
*/

int my_compute_power_rec(int nb, int p)
{
    int stock = nb;

    if (p < 0) {
        return (0);
    }
    if (p == 0)
        return (1);
    if (p > 0) {
        stock = nb * my_compute_power_rec(stock, p - 1);
    }
    return (stock);
}
