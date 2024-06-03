/*
** EPITECH PROJECT, 2024
** personal realloc
** File description:
** re allocated a block of memory and extended it to a new size
*/
#include "../../includes/memlib.h"
#include <stdio.h>

void *my_realloc(void *ptr, size_t size)
{
    char **new_ptr = NULL;

    if (!ptr)
        return my_malloc(size);
    if (size <= sizeof(*ptr))
        return ptr;
    new_ptr = my_malloc(size);
    my_memcpy(new_ptr, ptr);
    return new_ptr;
}
