/*
** EPITECH PROJECT, 2021
** Remastered 'My' Library
** File description:
** Converters header file
*/

#pragma once

#include <stdint-gcc.h>
#include "my_strings.h"

char *my_itoa_base(int64_t nbr, char const *base_array);
char *my_itoa(int64_t nbr);

int64_t my_atoi_base(char const *str, char const *base_array);
int64_t my_atoi(char const *str);
