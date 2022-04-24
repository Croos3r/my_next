/*
** EPITECH PROJECT, 2021
** Remastered 'My' Library
** File description:
** Integer converters file
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "my_converters.h"
#include "my_meters.h"
#include "my_displayers.h"

char *my_itoa_base(int64_t number, char const *base_array)
{
    size_t base = my_strlen(base_array);
    size_t number_len = my_intlen_base(number, base_array) + 1;
    size_t index = number_len - 1;
    char *result = malloc(sizeof(char) * number_len);
    uint64_t unsigned_processable = number < 0 ? -number : number;
    bool negative = number < 0;

    if (result == NULL || base == 0)
        return NULL;
    if (negative)
        result[0] = '-';
    result[index--] = '\0';
    for (; index > negative; index--) {
        result[index] = base_array[unsigned_processable % base];
        unsigned_processable /= (int) base;
    }
    result[index] = base_array[unsigned_processable % base];
    return result;
}

char *my_itoa(int64_t number)
{
    return my_itoa_base(number, "0123456789");
}

int64_t my_atoi_base(char const *str, char const *base_array)
{
    int64_t result = 0;
    bool negative;
    char const *found;

    if (str == NULL || base_array == NULL || my_strchr(base_array, '-') != NULL)
        return 0;
    negative = str[0] == '-';
    for (size_t i = negative; str[i]; i++) {
        found = my_strchr(base_array, str[i]);
        if (found == NULL)
            return 0;
        result *= 10;
        result += found - base_array;
    }
    return negative ? -result : result;
}

int64_t my_atoi(char const *str)
{
    return my_atoi_base(str, "0123456789");
}
