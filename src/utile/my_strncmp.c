/*
** EPITECH PROJECT, 2024
** personal strncmp
** File description:
** compare n bytes of two strings
*/
#include "../../includes/strlib.h"

int my_strncmp(char *s1, char *s2, int nbyte)
{
    if (!s1)
        return __INT_MAX__;
    if (!s2)
        return -__INT_MAX__;
    if ((my_strlen(s1) < nbyte) || (my_strlen(s2) < nbyte))
        return my_strlen(s1) - my_strlen(s2);
    for (int i = 0; i < nbyte; i++)
        if ((s1[i] - s2[i]) != 0)
            return s1[i] - s2[i];
    return 0;
}
