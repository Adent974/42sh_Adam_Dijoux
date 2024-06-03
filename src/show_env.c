/*
** EPITECH PROJECT, 2024
** show env
** File description:
** print the environment
*/
#include "../includes/ast.h"
#include "../includes/strlib.h"
#include "../includes/ast.h"
#include <unistd.h>
#include <stdio.h>

int show_env(ast_node_t *node)
{
    if (!node->env || !*node->env)
        return 0;
    if (len_2d_array(node->cmd) != 1) {
        write(2, "env: \'", 6);
        write(2, node->cmd[1], my_strlen(node->cmd[1]));
        write(2, "\': No such file or directory\n", 29);
        return 1;
    }
    for (int i = 0; node->env[i] != NULL; i++)
        dprintf(node->data->output_fd, "%s\n", node->env[i]);
    return 0;
}
