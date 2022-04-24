/*
** EPITECH PROJECT, 2021
** Remastered 'My' Library
** File description:
** Length meter file
*/

#include "my_meters.h"

size_t my_strlen(char const *string)
{
    int i = 0;

    while (string[i++] != '\0');
    return --i;
}

size_t my_uintlen_base(uint64_t number, char const *base_array)
{
    size_t base = my_strlen(base_array);
    int i = 0;

    if (base == 1) {
        if (number == 0)
            return 1;
        else
            return number;
    }
    if (base == 0)
        return 0;
    do {
        number /= (int) base;
        i++;
    } while (number != 0);
    return i;
}

size_t my_intlen_base(int64_t number, char const *base_array)
{
    return my_uintlen_base(number < 0 ? -number : number, base_array) +
    (number < 0);
}

size_t my_intlen(int64_t number)
{
    return my_intlen_base(number, "0123456789");
}
