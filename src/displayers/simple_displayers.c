/*
** EPITECH PROJECT, 2022
** Remastered 'My' Library
** File description:
** Simple displayer source file
*/

#include <unistd.h>
#include <stdarg.h>
#include "my_meters.h"
#include "my_displayers.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_putstrs(size_t nb_str, ...)
{
    va_list ap;
    char *current;

    va_start(ap, nb_str);
    for (size_t i = 0; i < nb_str; i++) {
        current = va_arg(ap, char *);
        write(1, current, my_strlen(current));
    }
    va_end(ap);
}
