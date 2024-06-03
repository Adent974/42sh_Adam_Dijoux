/*
** EPITECH PROJECT, 2024
** personal strdup
** File description:
** duplicate a string
*/
#include "../../includes/memlib.h"
#include "../../includes/strlib.h"

char *my_strdup(char *str)
{
    int len = 0;
    char *dup_str = NULL;

    if (!str)
        return NULL;
    len = my_strlen(str);
    dup_str = my_malloc(sizeof(char *) * (len + 1));
    my_strcpy(dup_str, str);
    return dup_str;
}
