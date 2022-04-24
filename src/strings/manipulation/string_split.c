/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** String split utilities
*/

#include <stdio.h>
#include "my_strings.h"
#include "my_memory.h"
#include "my_displayers.h"

static size_t distance_to_next_separator(char const *str, char separator)
{
    size_t i = 0;

    while (str[i] != separator && str[i] != '\0')
        i++;
    return i;
}

char **my_strsplit(char const *str, char separator)
{
    char **result = malloc(sizeof(char *));
    size_t result_size = 0;
    size_t dist;

    while (*str != '\0') {
        if (result == NULL)
            return NULL;
        if (*str == separator) {
            str++;
            continue;
        }
        dist = distance_to_next_separator(str, separator);
        result[result_size++] = my_strndup(str, dist);
        result = my_reallocarray(result, result_size + 1, result_size,
            sizeof(char *));
        if (result == NULL)
            return NULL;
        result[result_size] = NULL;
        str += dist;
    }
    return result;
}
