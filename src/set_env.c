/*
** EPITECH PROJECT, 2024
** set env
** File description:
** set a new environement variable
*/
#include "../includes/ast.h"
#include "../includes/strlib.h"
#include "../includes/memlib.h"
#include "../includes/ast.h"
#include <stdlib.h>

char *set_envar(char *key, char *value)
{
    char *new_key = my_strconcat(key, "=");
    char *envar = NULL;

    if (value == NULL)
        return new_key;
    else {
        envar = my_strconcat(new_key, value);
        return envar;
    }
}

int define_len_env(char **env)
{
    if (env[0] == NULL)
        return 2;
    else
        return len_2d_array(env);
}

char **add_in_env(char **env, char *key, char *value)
{
    int len = len_2d_array(env);
    char **copy = my_realloc(env, sizeof(char *) * (len + 2));

    copy[len] = set_envar(key, value);
    copy[len + 1] = NULL;
    return copy;
}

char **update_in_env(char **env, char *key, char *value)
{
    int len = len_2d_array(env);
    char *envar = set_envar(key, value);
    char **copy = my_malloc(sizeof(char *) * (len + 1));
    int index = get_key_index(env, key);

    for (int i = 0; env[i] != NULL; i++) {
        if (i == index) {
            copy[i] = envar;
            continue;
        }
        copy[i] = my_strdup(env[i]);
    }
    copy[len] = NULL;
    return copy;
}

int set_env(ast_node_t *node)
{
    if (node->cmd[1] == NULL) {
        show_env(node);
        return 0;
    }
    if (handle_setenv_errror(node->cmd) == -1)
        return 1;
    else if (search_in_env(node->env, node->cmd[1], NULL, SEARCH_IGN) > -1)
        node->env = update_in_env(node->env, node->cmd[1], node->cmd[2]);
    else
        node->env = add_in_env(node->env, node->cmd[1], node->cmd[2]);
    return 0;
}
