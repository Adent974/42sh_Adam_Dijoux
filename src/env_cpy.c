/*
** EPITECH PROJECT, 2024
** env cpy
** File description:
** copy the environment
*/
#include "../includes/strlib.h"
#include "../includes/ast.h"
#include "../includes/memlib.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int len_2d_array(char **env)
{
    int len = 0;

    if (env == NULL)
        return 0;
    while (env[len] != NULL)
        len += 1;
    return len;
}

int copy_envar_error(char *envar, int flags)
{
    if (envar == NULL)
        return -1;
    if (SEARCH_ERROR(flags) == -1)
        return -1;
    return 0;
}

int is_value(char *envar)
{
    int len = 0;
    int i = 0;

    if (envar == NULL)
        return -1;
    len = my_strlen(envar);
    while (envar[i] != '=')
        i++;
    if (len == (i + 1))
        return -1;
    return (i + 1);
}

char *copy_envar(char *envar, int flags)
{
    char *dup = NULL;
    char *tok = NULL;
    char *copy = NULL;
    int len_key = is_value(envar);

    if (copy_envar_error(envar, flags) == -1)
        return NULL;
    if (flags == SEARCH_VALUE && len_key > 0)
        copy = my_strdup(envar + len_key);
    if (flags == SEARCH_KEY) {
        dup = my_strdup(envar);
        tok = strtok(dup, "=");
        copy = my_strdup(tok);
    }
    if (flags == SEARCH_KEY_VALUE)
        copy = my_strdup(envar);
    if (copy != NULL)
        mem_handler(copy, STORE);
    return copy;
}

char **env_copy(char **env)
{
    int len = len_2d_array(env);
    char **envcpy = {NULL};

    if ((env[0] == NULL) || (len <= 0))
        return env;
    envcpy = my_malloc(sizeof(char *) * (len + 1));
    if (envcpy == NULL)
        return env;
    for (int i = 0; env[i] != NULL; i++)
        envcpy[i] = my_strdup(env[i]);
    envcpy[len] = NULL;
    return envcpy;
}
