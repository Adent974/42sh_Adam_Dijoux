/*
** EPITECH PROJECT, 2024
** personnal strcpy
** File description:
** copy a string
*/
#include "../../includes/strlib.h"

int my_strcpy(char *dest, char *src)
{
    int i = 0;

    if (!src || !dest)
        return -1;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}
