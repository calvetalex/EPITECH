/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
** main function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "menger.h"
#include "bitmap.h"

static void initialize_image(size_t size, unsigned int *buffer,
    unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; i++)
        img[i] = buffer + i * size;
    return;
}

static void init_menger(menger_t *data, int size, int level)
{
    data->x = 0;
    data->y = 0;
    data->size = size;
    data->level = level;
    return;
}

static void create_bitmap_from_buffer(size_t size, unsigned int *buffer,
    char *file_name)
{
    int fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY , 0644) ;

    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int main (int argc, char **argv)
{
    int size = 0;
    int level = 0;
    unsigned int *buffer = NULL;
    unsigned int **img = NULL;
    menger_t data = {0};

    if (argc != 4) {
        fprintf(stderr, "menger_face file_name size level\n");
        return (84);
    }

    size = atoi(argv[2]);
    level = atoi(argv[3]);
    buffer = malloc (size * size * sizeof(*buffer));
    img = malloc(size * sizeof(*img));
    initialize_image((size_t)size, buffer, img);
    init_menger(&data, size, level);
    menger(data, img);
    create_bitmap_from_buffer(size, buffer, argv[1]);
    return (0);
}
