/*
** EPITECH PROJECT, 2024
** personnal strndup
** File description:
** duplicate n byte of a str
*/
#include "../../includes/strlib.h"
#include "../../includes/memlib.h"

char *my_strndup(char *str, int nbyte)
{
    char *dup_str = NULL;

    if (!str || nbyte <= 0 || my_strlen(str) < nbyte)
        return NULL;
    dup_str = my_malloc(sizeof(char *) * (nbyte + 1));
    my_strncpy(dup_str, str, nbyte);
    return dup_str;
}
