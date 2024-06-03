/*
** EPITECH PROJECT, 2024
** personnale
** File description:
** free the elments in del it in the garbage free
*/

#include "../../includes/memlib.h"

void my_free(void *data)
{
    if (!data)
        return;
    if (mem_handler(data, IS_STORED) == 1)
        mem_handler(data, FREE);
    else
        free(data);
    return;
}
