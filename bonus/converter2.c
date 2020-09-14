/*
** EPITECH PROJECT, 2019
** converter2
** File description:
** just a simple converter.c extention
*/

char *to_normal_ops(char *operators)
{
    return (operators);
}

int get_pos(char *expr, char *base)
{
    for (int i = 0; base[i] != '\0'; i += 1) {
        if (expr[i] == base[i])
            return (i);
    }
}

char exprj(char *base, int *array, char *expr, int j)
{
    for (int k = 0; base[k] != '\0'; k += 1) {
        if (expr[j] == base[k])
            expr[j] += array[get_pos(expr, base)];
    }
    return (expr[j]);
}
