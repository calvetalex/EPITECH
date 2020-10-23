/*
** EPITECH PROJECT, 2018
** tes_ptintf.c
** File description:
** test function my_printf()
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "../../include/my.h"


void redirect(void)
{
    cr_redirect_stdout();
}

Test(my_printf, my_printf_nb, .init=redirect)
{
    my_printf("%d%d", 42, 88);
    cr_assert_stdout_eq_str("4288");
}

Test(my_printf, my_printf_str, .init=redirect)
{
    char str[]="Les idées ne meurent pas, Mr Creedy";

    my_printf("La phrase est : %s", str);
    cr_assert_stdout_eq_str("La phrase est : \
Les idées ne meurent pas, Mr Creedy");
}

Test(my_printf, my_printf_char, .init=redirect)
{
    char s = 's';
    char a = 'a';

    my_printf("les lettres choisies sont : %c, %c", s, a);
    cr_assert_stdout_eq_str("les lettres choisies sont : s, a");
}

Test(my_printf, my_printf_basics, .init=redirect)
{
    char str[]="Kspar c est caca";
    int nbr = 666;
    char c = 'E';

    my_printf("Un grand homme a dis %s, \
à l image de satan connu sous le nom de %d dans l %c", str, nbr, c);
    cr_assert_stdout_eq_str("Un grand homme a dis Kspar c est caca, \
à l image de satan connu sous le nom de 666 dans l E");
}

Test(my_printf, print_maj, .init=redirect)
{
    char g = 'G';

    my_printf("%C", g);
    cr_assert_stdout_eq_str("G");
}

Test(my_printf, my_print_hexa_min, .init=redirect)
{
    int exclu = 4269;

    my_printf("%x", exclu);
    cr_assert_stdout_eq_str("10ad");
}

Test(my_printf, my_print_hexa_maj, .init=redirect)
{
    int satan = 666;

    my_printf("%X", satan);
    cr_assert_stdout_eq_str("29A");
}

Test(my_printf, my_print_binary, .init=redirect)
{
    int test = 4269;

    my_printf("%b", test);
    cr_assert_stdout_eq_str("1000010101101");
}

Test(my_printf, print_oct, .init=redirect)
{
    int test = 666;

    my_printf("%o", test);
    cr_assert_stdout_eq_str("1232");
}
/*
Test(my_printf, print_memory, .init=redirect)
{
    int nb = 45;
    char *dest;

    sprintf(dest, "%p", nb);
    my_printf("%p", nb);
    cr_assert_stdout_eq_str(dest);
}
*/
Test(my_printf, disp_nonpritable, .init=redirect)
{
    char str[] = "toto";
    str[1] = 6;
    str[3] = 31;
    char dest[] = "t\\006t\\037";

    my_printf("%S", str);
    cr_assert_stdout_eq_str(dest);
}
