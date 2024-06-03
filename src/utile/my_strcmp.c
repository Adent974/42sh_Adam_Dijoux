/*
** EPITECH PROJECT, 2024
** personnal strcmp
** File description:
** compare two strings
*/

#include "../../includes/strlib.h"

int my_strcmp(char *s1, char *s2)
{
    int len = 0;

    if (!s1)
        return __INT_MAX__;
    if (!s2)
        return -__INT_MAX__;
    len = my_strlen(s1) - my_strlen(s2);
    if (len != 0)
        return len;
    for (int i = 0; s1[i] != '\0'; i++)
        if ((s1[i] - s2[i]) != 0)
            return s1[i] - s2[i];
    return 0;
}
