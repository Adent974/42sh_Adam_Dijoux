/*
** EPITECH PROJECT, 2024
** strduptil
** File description:
** duplicate a string until a charcater
*/
#include "../../includes/strlib.h"
#include "../../includes/memlib.h"

char *my_strduptil(char *str, char c)
{
    char *dup = NULL;
    int len = 0;

    if (!str)
        return NULL;
    len = my_strlen(str);
    dup = my_malloc(sizeof(char) * (len + 1));
    if (my_strcpytil(dup, str, c) < 0)
        return NULL;
    return dup;
}
