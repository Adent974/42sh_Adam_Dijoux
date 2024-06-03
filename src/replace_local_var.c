/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** replace local var
*/

#include "../includes/shell.h"

char *replace_string(ast_node_t *node, int index)
{
    LIST *tmp = node->variable;
    char *cmd = node->cmd[index];
    local_t *element = NULL;
    char return_buffer[10] = {0};

    cmd++;
    if (!my_strcmp(cmd, "?")) {
        sprintf(return_buffer, "%d", node->data->exit_status);
        return my_strdup(return_buffer);
    }
    while (tmp) {
        element = (local_t *)tmp->data;
        if (!my_strcmp(cmd, element->variable_name))
            return (cmd ? element->variable_data : "");
        tmp = tmp->next;
    }
    fprintf(stderr, "%s: Undefined variable.\n", cmd);
    return NULL;
}

ast_node_t *det_cmd_var(char *tmp, ast_node_t *node, int index)
{
    if (!tmp) {
        node->var_status = 1;
        return node;
    } else if (!node->var_status) {
        node->cmd[index] = my_strdup(tmp);
        return node;
    }
    return node;
}

ast_node_t *replace_local_var(ast_node_t *node)
{
    char *tmp = NULL;

    for (int i = 0; node->cmd[i]; i++) {
        tmp = NULL;
        if (!my_strncmp("$", node->cmd[i], 1) && my_strcmp(node->cmd[i], "$")){
            tmp = replace_string(node, i);
            node = det_cmd_var(tmp, node, i);
        }
    }
    return node;
}
