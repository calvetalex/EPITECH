/*
** EPITECH PROJECT, 2019
** NWP_myftp_2019
** File description:
** str_to_word_array
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **str_to_word_array(char *str, char *tok)
{
    char **tab = malloc(sizeof(*tab));
    char *token = strtok(str, tok);

    if (!str || !tab || !token)
        return (NULL);
    for (int i = 0; ; i++) {
        tab[i] = strdup(token);
        tab = realloc(tab, (sizeof(*tab) * ((i + 1) + 1)));
        if (!(token = strtok(NULL, tok))) {
            tab[i + 1] = token;
            break;
        }
    }
    free(token);
    return (tab);
}

void free_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}