/*
** EPITECH PROJECT, 2020
** cpp_d01_2019
** File description:
** bitmat_header.c
*/

#include <unistd.h>
#include <stddef.h>
#include "bitmap.h"

static void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = 0x4D42;
    header->size = (size * size * 4) + (sizeof(bmp_info_header_t) +
        sizeof(bmp_header_t));
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;
    make_bmp_header(&header, size);
    write (fd, &header , sizeof(header));
}

static void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = sizeof(bmp_info_header_t);
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}

void write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t info;
    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}