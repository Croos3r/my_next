/*
** EPITECH PROJECT, 2022
** Remastered 'My' Lib
** File description:
** Memory management utilities
*/

#pragma once

#include <stddef.h>

void my_memset(void *pointer, int value, size_t size);
void my_memcpy(void *dest, const void *src, size_t size);

void *my_realloc(void *pointer, size_t old_size, size_t size);
void *my_calloc(size_t element_count, size_t element_size);
void *my_reallocarray(void *pointer, size_t count,
    size_t old_count, size_t size);
