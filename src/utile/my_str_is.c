/*
** EPITECH PROJECT, 2024
** strisalpha
** File description:
** indicate if the string contents is alpha charactere
*/
#include "../../includes/strlib.h"

bool my_str_isalpha(char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!IS_ALPHA(str[i]))
            return false;
    return true;
}

bool my_str_isalphanum(char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!IS_ALPHANUM(str[i]))
            return false;
    return true;
}

bool my_str_isnum(char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!IS_NUM(str[i]))
            return false;
    return true;
}

bool my_str_isupper(char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!IS_UPPER(str[i]))
            return false;
    return true;
}

bool my_str_islower(char *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i] != '\0'; i++)
        if (!IS_LOWER(str[i]))
            return false;
    return true;
}
