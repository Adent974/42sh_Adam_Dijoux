/*
** EPITECH PROJECT, 2024
** strcpytil
** File description:
** copy as tring until a character
*/
#include "../../includes/strlib.h"

int my_strcpytil(char *dest, char *src, char c)
{
    int i = 0;

    if (!src || !dest)
        return -1;
    if (c == '\0')
        return my_strcpy(dest, src);
    if (my_strocc(src, c) < 1)
        return -1;
    while (src[i] != c) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}
