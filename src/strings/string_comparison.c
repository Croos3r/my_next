/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** String comparison utililities
*/

#include <stdbool.h>
#include "my_strings.h"

int my_strcmp(const char *str1, const char *str2)
{
    size_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
        i++;
    return str1[i] - str2[i];
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
        if (++i == n)
            return 0;
    return str1[i] - str2[i];
}

bool is_str_composed_of(char const *str, char const *components)
{
    for (size_t i = 0; str[i]; ++i)
        if (my_strchr(components, str[i]) == NULL)
            return false;
    return true;
}

bool is_str_alpha(char const *str)
{
    return is_str_composed_of(str,
        "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

bool is_str_numeric(char const *str)
{
    return is_str_composed_of(str, "0123456789");
}
