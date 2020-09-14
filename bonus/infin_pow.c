/*
** EPITECH PROJECT, 2019
** infin_pow
** File description:
** computes arbitrary lengh power
*/

char *infin_mult(char *nb1, char *nb2);
char *nbr_to_str(int nb);
char *my_strdup(char const *src);
int my_getnbr(char const *str);

char *infin_pow(char *nb, char *p)
{
    char *stock = my_strdup(nb);
    int pow = my_getnbr(p);

    if (pow == 0)
        return ("1");
    pow -= 1;
    while (pow > 0) {
        nb = infin_mult(stock, nb);
        pow -= 1;
    }
    return (nb);
}
