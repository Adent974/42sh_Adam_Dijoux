/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** unset local variable
*/

#include "../includes/shell.h"

void rm_var(char *data, linked_list_t **tmp, LIST_VAR)
{
    local_t *element = (local_t *)(*tmp)->data;

    if (!my_strcmp(element->variable_name, data)) {
        if ((*prev) == NULL) {
            *variables = (*tmp)->next;
            *tmp = *variables;
        } else {
            (*prev)->next = (*tmp)->next;
            (*tmp) = (*prev)->next;
        }
    } else {
            *prev = *tmp;
            *tmp = (*tmp)->next;
    }
}

int unset_variable(ast_node_t *node, linked_list_t **variables)
{
    linked_list_t *tmp = *variables;
    linked_list_t *prev = NULL;

    if (!node->cmd[1])
        return 0;
    for (int i = 1; node->cmd[i]; i++) {
        tmp = *variables;
        prev = NULL;
        while (tmp != NULL) {
            rm_var(node->cmd[i], &tmp, &prev, variables);
        }
    }
    return 0;
}
