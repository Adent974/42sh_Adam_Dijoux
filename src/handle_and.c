/*
** EPITECH PROJECT, 2024
** B-PSU-200-RUN-2-1-42sh-nicolas.samy
** File description:
** handle__&&_and_||
*/

#include "../includes/ast.h"
#include "../includes/strlib.h"
#include "../includes/ast.h"
#include <unistd.h>
#include <stdio.h>

void handle_and(ast_node_t *ast)
{
    if (!ast->left->visited)
        return;
    if (ast->data->exit_status != 0)
        ast->right->visited = true;
}

void handle_or(ast_node_t *ast)
{
    if (!ast->left->visited)
        return;
    if (ast->data->exit_status == 0)
        ast->right->visited = true;
}
