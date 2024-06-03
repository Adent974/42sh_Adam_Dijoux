/*
** EPITECH PROJECT, 2024
** new_minishell
** File description:
** unset_env
*/
#include "../includes/ast.h"
#include "../includes/memlib.h"
#include "../includes/strlib.h"
#include "../includes/ast.h"
#include <unistd.h>

char **unset_envar(char **env, int index, int size)
{
    char **copy = my_malloc(sizeof(char *) * (size));
    int i = 0;
    int j = 0;

    while (env[i] != NULL) {
        if (i == index) {
            i += 1;
            continue;
        }
        copy[j] = my_strdup(env[i]);
        j += 1;
        i += 1;
    }
    copy[size - 1] = NULL;
    return copy;
}

int unset_env(ast_node_t *node)
{
    int existant = 0;
    int len_env = 0;

    if (!node->env || !*node->env)
        return 0;
    if (len_2d_array(node->cmd) == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 1;
    }
    for (int i = 1; node->cmd[i] != NULL; i++) {
        existant = get_key_index(node->env, node->cmd[i]);
        if (existant > -1) {
            len_env = len_2d_array(node->env);
            node->env = unset_envar(node->env, existant, len_env);
        }
    }
    return 0;
}
