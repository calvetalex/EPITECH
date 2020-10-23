/*
** EPITECH PROJECT, 2018
** convert_to_bin.c
** File description:
** change a decimal in a binary
*/

char *convert_to_bin(int nb, char *res)
{
    for (int i = 0; i < 10; i++)
        res[i] = 0;
    res[9] = '\0';
    for (int j = 10; (nb / 2) >= 0 && j > 0; j--) {
        nb = nb / 2;
        if ((nb % 2) == 0)
            res[j] = 0 + '0';
        else
            res[j] = 1 + '0';
    }
    return (res);
}
