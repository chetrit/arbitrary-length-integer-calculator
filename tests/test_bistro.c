/*
** EPITECH PROJECT, 2019
** test_bistro
** File description:
** tests our bistromatic
*/

#include <criterion/criterion.h>
#include "my.h"

char *bistro(char *base, char *operators, char *expr, unsigned int size);

Test(bistro, bistro_basic_tests)
{
    char *str;

    str = bistro("0123456789", "()+-*/%", "2+2", 3);
    cr_assert_str_eq(str, "4");
    str = bistro("0123456789", "()+-*/%", "--+-2*--+2", 10);
    cr_assert_str_eq(str, "-4");
    str = bistro("0123456789", "()+-*/%", "2*(2+2)", 7);
    cr_assert_str_eq(str, "8");
    str = bistro("0123456789", "()+-*/%", "333%333", 7);
    cr_assert_str_eq(str, "0");
    str = bistro("0123456789", "()+-*/%", "99-31312+(-(312+2))", 3);
    cr_assert_str_eq(str, "-31527");
    str = bistro("0123456789", "()+-*/%", "0%3+1+(-0%3)+1-0/3+1+(-0/3)+1", 29);
    cr_assert_str_eq(str, "4");
}

Test(bistro, bistro_advanced_tests)
{
    char *str;

    str = bistro("0123456789", "()+-*/%", my_strcat("1234567890*0987654321+(12",
        "34567890%345678)*56789/567890+67890-4567890"), 68);
    cr_assert_str_eq(str, "1219326311121867865");
    str = bistro("0123456789", "()+-*/%", my_strcat("-(12*(13+15/5*(6/(12+14%(",
        "30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))"), 84);
    cr_assert_str_eq(str, "-744629760");
    str = bistro("0123456789", "()+-*/%", "3%33", 4);
    cr_assert_str_eq(str, "3");
    str = bistro("0123456789", "()+-*/%", my_strcat("33/44-33/33-12%22-13/13-4",
        "1%41-33*-33*-33*33/-33+32-312/-321"), 59);
    cr_assert_str_eq(str, "35955");
}
