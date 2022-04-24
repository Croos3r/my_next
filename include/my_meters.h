/*
** EPITECH PROJECT, 2021
** Remastered 'My' Library
** File description:
** Meters header file
*/

#pragma once

#include <stddef.h>
#include <stdint-gcc.h>
#include "my_strings.h"

size_t my_strlen(char const *string);

size_t my_intlen_base(int64_t number, char const *base_array);
size_t my_uintlen_base(uint64_t number, char const *base_array);
size_t my_intlen(int64_t number);
