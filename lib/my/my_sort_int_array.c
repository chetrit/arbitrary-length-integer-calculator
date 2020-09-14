/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** sorts an int array
*/

#include <stddef.h>

int swap_int_array(int stock, int **array, int i)
{
    if (*array[i + 1] < *array[i]) {
        stock = *array[i];
        *array[i] = *array[i + 1];
        *array[i + 1] = stock;
    }
    return (stock);
}

void my_sort_int_array(int *array, int size)
{
    int stock = 0;

    if (array == NULL)
        return;
    for (int j = 0; j < size; j += 1) {
        for (int i = 0; i < size; i += 1)
            stock = swap_int_array(stock, &array, i);
    }
}
