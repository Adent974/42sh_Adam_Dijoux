/*
** EPITECH PROJECT, 2024
** my malloc
** File description:
** malloc and stor the pointer into a garabage free
*/
#include <stdlib.h>
#include "../../includes/memlib.h"

void *my_malloc(size_t size)
{
    void *data = NULL;

    if (size <= 0)
        return data;
    data = malloc(size);
    if (data == NULL)
        return data;
    mem_handler(data, STORE);
    return data;
}
