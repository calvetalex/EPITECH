/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** manual function printf
*/
#include "../include/my.h"
#include <stdarg.h>

void test_option_two(char format, va_list *ap)
{
    switch(format)
    {
    case 'x':
        disp_hexamin(va_arg(*ap, int));
        break;
    case 'X':
        disp_hexamaj(va_arg(*ap, int));
        break;
    case 'p':
        my_putstr("0x");
        disp_membase(va_arg(*ap, long unsigned int));
        break;
    case 'S':
        disp_nonprintable(va_arg(*ap, char*));
        break;
    }
}

void test_option(char format, va_list *ap)
{
    switch(format)
    {
    case 'o':
        disp_oct(va_arg(*ap, int));
        break;
    case 'u':
    case 'i':
        disp_stdarg('d', ap);
        break;
    case 'C':
        disp_stdarg('c', ap);
        break;
    case 'b':
    case '0':
        disp_binary(va_arg(*ap, long int));
        break;
    default:
        test_option_two(format, ap);
        break;
    }
}

int my_printf(char const *format, ...)
{
    va_list ap;
    int counter = 0;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else if (format[i] == '%') {
            if (format[i+1] == 'd' || format[i+1] == 's' || format[i+1] == 'c'){
                disp_stdarg(format[i + 1], &ap);
                i++;
            } else {
                test_option(format[i + 1], &ap);
                i++;
            }
        }
        counter++;
    }
    va_end(ap);
    return (0);
}
