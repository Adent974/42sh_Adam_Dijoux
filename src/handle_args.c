/*
** EPITECH PROJECT, 2024
** handle args
** File description:
** handle arguments
*/
#include "../includes/ast.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **segments_args(char ***cmd)
{
    node_type_t type = leaf;
    char **new_cmd = NULL;

    if (!cmd)
        return NULL;
    type = parse_ope((*cmd));
    if (type == leaf)
        return (*cmd);
    for (unsigned int i = 0; is_ope(**cmd) != type; i++) {
        new_cmd = my_realloc(new_cmd, sizeof(char *) * (i + 2));
        new_cmd[i] = my_strdup(**cmd);
        new_cmd[i + 1] = NULL;
        (*cmd)++;
    }
    (*cmd)++;
    return new_cmd;
}
