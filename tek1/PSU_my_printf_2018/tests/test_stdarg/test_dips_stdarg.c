/*
** EPITECH PROJECT, 2018
** test_std_arg.c
** File description:
** test disp_stdarg()
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect(void)
{
    cr_redirect_stdout();
}

Test(dips_stdarg, just_int, .init=redirect)
{
    disp_stdarg("iiii", 12, 3, 6, 900);
    cr_assert_stdout_eq_str("12\n3\n6\n900\n");
}

Test(disp_stdarg, just_char, .init=redirect)
{
    disp_stdarg("cccc", "c", "x", "v", "y");
    cr_assert_stdout_eq_str("c\nx\nv\ny\n");
}

Test(disp_stdarg, just_string, .init=redirect)
{
    disp_stdarg("ss", "I am BATMAN!", "tpute");
    cr_assert_stdout_eq_str("I am BATMAN!\ntpute\n");
}

Test(disp_stdarg, final, .init=redirect)
{
    disp_stdarg("csiisic", "P", "tpute", 23, 666, "Hell", 88, "h");
    cr_assert_stdout_eq_str("P\ntpute\n23\n666\nHell\n88\nh\n");
}
