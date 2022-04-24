/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** String copy utilities
*/

#include "my_strings.h"

char *my_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, size_t n)
{
    size_t i = 0;

    for (; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    if (n - 1 != i)
        dest[i] = '\0';
    return dest;
}
