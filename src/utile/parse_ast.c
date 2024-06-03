/*
** EPITECH PROJECT, 2024
** parse the ast object
** File description:
** parse_ast
*/
#include "../../includes/ast.h"
#include "../../includes/shell.h"
#include <stdio.h>

ast_node_t *parse_node_right(ast_node_t *node)
{
    if (!node->left || !node->right) {
        node->visited = true;
        return node;
    }
    if (node->right->visited == false) {
        node->right->visited = true;
        return parse_ast(node->right);
    } else if (node->left->visited == false) {
        node->left->visited = true;
        return parse_ast(node->left);
    }
    return node;
}

ast_node_t *parse_node_left(ast_node_t *node)
{
    if (!node->left || !node->right) {
        node->visited = true;
        return node;
    }
    if (node->left->visited == false) {
        node->left->visited = true;
        return parse_ast(node->left);
    } else if (node->right->visited == false) {
        node->right->visited = true;
        return parse_ast(node->right);
    }
    return node;
}

ast_node_t *parse_parents(ast_node_t *node)
{
    if (node->parents != NULL) {
        node->visited = true;
        return parse_ast(node->parents);
    }
    return node;
}

ast_node_t *parse_leaf(ast_node_t *node)
{
    node->cmd = parse_alias(node->cmd, node->env);
    if (node->cmd)
        handle_exec(node);
    if (node->parents != NULL) {
        node->parents->data = node->data;
        return parse_ast(node->parents);
    }
    return node;
}

ast_node_t *parse_ast(ast_node_t *node)
{
    handle_data_flux(node);
    if (!node->left && !node->right) {
        node = parse_leaf(node);
        if (node->parents == NULL)
            return node;
    }
    if (node->right->visited == true && node->left->visited == true)
        node = parse_parents(node);
    if (node->priority == left)
        node = parse_node_left(node);
    if (node->priority == right)
        node = parse_node_right(node);
    return node;
}
