/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** prints the number passed as parameter
*/

void my_putchar(char c);

void lame_print(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int condition = 0;

    if (nb == -2147483648) {
        condition = 1;
        lame_print();
    }
    if (nb < 0 && condition == 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10 && condition == 0) {
        my_put_nbr(nb/10);
    }
    if (condition == 0) {
        my_putchar((nb % 10) + 48);
    }
    return (0);
}
