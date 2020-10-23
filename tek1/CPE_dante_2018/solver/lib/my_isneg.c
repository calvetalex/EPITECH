/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** test sign of a number
*/

char my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('1');
    else
        my_putchar('0');
    return (0);
}
