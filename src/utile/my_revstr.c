/*
** EPITECH PROJECT, 2024
** personal revstr
** File description:
** reverse a string
*/
#include "../../includes/memlib.h"
#include "../../includes/strlib.h"

char *my_revstr(char *str)
{
    char *rev_str = NULL;
    int len = 0;
    int index = 0;

    if (!str)
        return NULL;
    len = my_strlen(str);
    rev_str = my_malloc(sizeof(char) * (len + 1));
    for (int i = (len - 1); i >= 0; i--) {
        rev_str[index] = str[i];
        index++;
    }
    rev_str[len] = '\0';
    return rev_str;
}
