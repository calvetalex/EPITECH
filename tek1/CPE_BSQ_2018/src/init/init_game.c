/*
** EPITECH PROJECT, 2018
** init_game.c
** File description:
** initialisation of structure game to run bsq
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

char *get_file(char *file)
{
    char *buff = malloc(sizeof(char) * 701);
    int len = 0;
    int fd = open(file, O_RDONLY);
    char *config = NULL;

    for (int i = 1; i > 0; len += i)
        i = read(fd, buff, 700);
    close(fd);
    free(buff);
    fd = open(file, O_RDONLY);
    config = malloc(sizeof(char) * (len + 1));
    config[len] = '\0';
    read(fd, config, len);
    close(fd);
    while (*config != '\n')
        config++;
    return (++config);
}

int count_line(char **map)
{
    int len;

    for (len = 0; map[len] != NULL; len++);
    return (len);
}

int init_game(game_t *info, char *file)
{
    char *config = NULL;
    int err = 0;

    info->beg_x = 0;
    info->beg_y = 0;
    info->max_x = 0;
    info->max_y = 0;
    info->max_size = 1;
    config = get_file(file);
    info->map = str_to_word_array(config, "\n");
    err = verif_map(info);
    info->height = count_line(info->map);
    info->width = my_strlen(info->map[0]);
    if (err == SUCCESS)
        return (SUCCESS);
    else
        return (ERROR);
}