/*
** EPITECH PROJECT, 2022
** Remastered 'My Lib
** File description:
** String concatenation utilities
*/

#include "my_strings.h"
#include "my_meters.h"

char *my_strcat(char *dest, char const *src)
{
    size_t length = my_strlen(dest);
    size_t i = 0;

    for (; src[i] != '\0'; ++i)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return dest;
}

char *my_strncat(char *dest, char const *src, size_t n)
{
    size_t length = my_strlen(dest);
    size_t i = 0;

    for (; src[i] != '\0' && i < n; ++i)
        dest[length + i] = src[i];
    if (n - 1 != i)
        dest[length + i] = '\0';
    return dest;
}
