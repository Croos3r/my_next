/*
** EPITECH PROJECT, 2022
** Remastered 'My Lib
** File description:
** String duplication utilities
*/

#include "my_strings.h"
#include "my_meters.h"

char *my_strdup(char const *src)
{
    size_t len = my_strlen(src);
    char *result = malloc(sizeof(char) * (len + 1));

    if (result == NULL)
        return NULL;
    return my_strcpy(result, src);
}

char *my_strndup(char const *str, size_t n)
{
    char *result = malloc(sizeof(char) * (n + 1));

    if (result == NULL)
        return NULL;
    my_strncpy(result, str, n);
    result[n] = '\0';
    return result;
}
