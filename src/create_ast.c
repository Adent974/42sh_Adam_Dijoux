/*
** EPITECH PROJECT, 2024
** create ast
** File description:
** create an ast
*/
#include "../includes/ast.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

data_flux_t *init_data_flux(void)
{
    data_flux_t *data = my_malloc(sizeof(data_flux_t));

    data->is_exited = false;
    data->is_segterm = false;
    data->input_fd = STDIN_FILENO;
    data->output_fd = STDOUT_FILENO;
    data->exit_status = 0;
    data->signum = 0;
    return data;
}

ast_node_t *init_node(ast_node_t *parents, char **cmd, char **env, LIST *var)
{
    ast_node_t *node = NULL;

    if (!cmd)
        return NULL;
    node = my_malloc(sizeof(ast_node_t));
    node->data = init_data_flux();
    node->parents = parents;
    node->type = parse_ope(cmd);
    node->priority = which_priority(node->type);
    node->visited = false;
    node->env = env;
    node->var_status = 0;
    node->variable = var;
    return node;
}

ast_node_t *create_ast(ast_node_t *parents, char **cmd, char **env, LIST *var)
{
    ast_node_t *node = NULL;

    if (!cmd)
        return NULL;
    node = init_node(parents, cmd, env, var);
    if (node->type != leaf) {
        node->cmd = NULL;
        node->left = create_ast(node, segments_args(&cmd), env, var);
        node->right = create_ast(node, cmd, env, var);
    } else {
        node->cmd = cmd;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
