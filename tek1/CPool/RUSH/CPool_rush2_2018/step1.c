/*
** EPITECH PROJECT, 2018
** step1.c
** File description:
** rush2
*/

int step1(char const *s1, char *s2)
{
    int compt = 0;

    while (*s1 != '\0') {
        if (*s1 == *s2 || *s1 == (*s2 + 32))
            compt ++;
        *s1 ++;
    }
    my_putchar(*s2);
    my_putchar(':');
    my_putchar(compt + 48);
}
