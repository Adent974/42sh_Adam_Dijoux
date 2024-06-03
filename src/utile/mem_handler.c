/*
** EPITECH PROJECT, 2024
** garbage free
** File description:
** stock all adrress of variable malloc and free them
*/
#include <stdlib.h>
#include "../../includes/memlib.h"
#include <stdio.h>

bool is_stored(void *data, garbage_t *grb)
{
    void *save_ptr = grb;

    while (grb != NULL) {
        if (grb->data == data) {
            grb = save_ptr;
            return true;
        }
        grb = grb->next;
    }
    grb = save_ptr;
    return false;
}

int mem_handler(void *data, int act)
{
    static garbage_t *grb = NULL;

    if (ACT_ERROR(act) == -1)
        return -1;
    if (act == PRINT && data == NULL)
        print_garbage(grb);
    if (act == FREE && data != NULL)
        if (is_stored(data, grb))
            del_in_garbage(&grb, data);
    if (act == IS_STORED && data != NULL)
        if (is_stored(data, grb))
            return 1;
    if (act == STORE && data != NULL)
        if (!is_stored(data, grb))
            store_in_grabage(&grb, data);
    if (act == DUMP && data == NULL)
            free_garbage(grb);
    return 0;
}
