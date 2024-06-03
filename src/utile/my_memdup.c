/*
** EPITECH PROJECT, 2024
** memdup
** File description:
** duplicate a block of memory
*/
#include "../../includes/memlib.h"
#include <stdio.h>

void *my_memdup(void *mem)
{
    char **dup_mem = NULL;
    int len = 0;

    if (!mem)
        return NULL;
    len = my_memlen(mem);
    dup_mem = my_malloc(sizeof(char *) * (len + 1));
    my_memcpy(dup_mem, mem);
    dup_mem[len - 1] = NULL;
    return dup_mem;
}
