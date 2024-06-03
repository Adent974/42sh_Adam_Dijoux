/*
** EPITECH PROJECT, 2024
** search in env
** File description:
** search for an envrionment variable
*/
#include "../includes/ast.h"
#include "../includes/strlib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int get_key_index(char **env, char *key)
{
    int len = len_2d_array(env);
    int index = 0;
    char *dup = NULL;
    char *tok = NULL;

    if ((env[0] == NULL) || (key == NULL))
        return -1;
    while (env[index] != NULL) {
        dup = my_strdup(env[index]);
        tok = strtok(dup, "=");
        if (my_strcmp(key, tok) == 0) {
            break;
        }
        index += 1;
    }
    if (index == len)
        index = -1;
    return index;
}

int search_error(char **env, char *key, int key_index, int flags)
{
    if (env[0] == NULL)
        return -1;
    if (key_index < 0)
        return -1;
    if (key == NULL)
        return -1;
    if (SEARCH_ERROR(flags) == -1)
        return -1;
    return 0;
}

int search_in_env(char **env, char *key, char **buff, int flags)
{
    int key_index = 0;

    if (!env || !*env)
        return -1;
    key_index = get_key_index(env, key);
    if (search_error(env, key, key_index, flags) == -1)
        return -1;
    if (flags != SEARCH_IGN)
        (*buff) = copy_envar(env[key_index], flags);
    return key_index;
}
