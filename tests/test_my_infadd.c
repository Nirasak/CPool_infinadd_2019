/*
** EPITECH PROJECT, 2019
** test_my_infadd.c
** File description:
** test infadd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "struct.h"
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(infadd, simple_add, .init = redirect_all_std)
{
    char *str = my_strdup("1");
    char *src = my_strdup("1");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("2\n");
}

Test(infadd, simple_add_two, .init = redirect_all_std)
{
    char *str = my_strdup("0");
    char *src = my_strdup("0");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("0\n");
}

Test(infadd, normal_add, .init = redirect_all_std)
{
    char *str = my_strdup("99");
    char *src = my_strdup("1");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("100\n");
}

Test(infadd, hard_add, .init = redirect_all_std)
{
    char *str = my_strdup("123456789987654321123456789");
    char *src = my_strdup("987654321123456789987654321");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("1111111111111111111111111110\n");
}

Test(infadd, simple_sub, .init = redirect_all_std)
{
    char *str = my_strdup("1");
    char *src = my_strdup("-1");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("0\n");
}

Test(infadd, simple_sub_two, .init = redirect_all_std)
{
    char *str = my_strdup("9");
    char *src = my_strdup("-15");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("-6\n");
}

Test(infadd, medium_sub, .init = redirect_all_std)
{
    char *str = my_strdup("-12345");
    char *src = my_strdup("78");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("-12267\n");
}

Test(infadd, hard_sub, .init = redirect_all_std)
{
    char *str = my_strdup("12345678764321234");
    char *src = my_strdup("-2345674212345678764321234568");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("-2345674212333333085556913334\n");
}

Test(infadd, hard_test, .init = redirect_all_std)
{
    char *str = my_strdup("-----++++--4");
    char *src = my_strdup("-+++++++---8");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("4\n");
}

Test(infadd, ez_sub, .init = redirect_all_std)
{
    char *str = my_strdup("-100");
    char *src = my_strdup("1");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("-99\n");
}

Test(infadd, weird_test, .init = redirect_all_std)
{
    char *str = my_strdup("-0");
    char *src = my_strdup("-0");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("0\n");
}

Test(infadd, last_test, .init = redirect_all_std)
{
    char *str = my_strdup("8");
    char *src = my_strdup("4");
    add_t add;

    set_struct(str, src, &add);
    infin_add(&add);
    free(add.dest);
    free(str);
    free(src);
    cr_assert_stdout_eq_str("12\n");
}
