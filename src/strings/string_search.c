/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** String search utilities
*/

#include <string.h>
#include "my_strings.h"
#include "my_meters.h"

char const *my_strchr(char const *str, char c)
{
    for (; *str != '\0'; str++)
        if (*str == c)
            return str;
    return NULL;
}

char const *my_strrchr(char const *str, char c)
{
    char const *result = NULL;

    for (; *str != '\0'; str++)
        if (*str == c)
            result = str;
    return result;
}

char *my_strstr(char *haystack, char const *needle)
{
    if (*needle == '\0')
        return haystack;
    for (; *haystack != '\0'; haystack++)
        if (*haystack == *needle &&
            my_strncmp(haystack, needle, my_strlen(needle)) == 0)
            return haystack;
    return NULL;
}
