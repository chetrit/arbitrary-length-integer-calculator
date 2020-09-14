/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int stock = *b;

    *b = *a;
    *a = stock;
}
