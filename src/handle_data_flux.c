/*
** EPITECH PROJECT, 2024
** handle data flux
** File description:
** handlign data flux between ast node
*/

#include "../includes/ast.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

data_flux_t *reset_data_flux(data_flux_t *flux)
{
    if (flux->input_fd != STDIN_FILENO) {
        close(flux->input_fd);
        flux->input_fd = STDIN_FILENO;
    }
    if (flux->output_fd != STDOUT_FILENO) {
        close(flux->output_fd);
        flux->output_fd = STDOUT_FILENO;
    }
    return flux;
}

void double_right_redic(ast_node_t *node)
{
    int fd = 0;

    if (node->right->visited == true) {
        node->data = reset_data_flux(node->data);
        return;
    }
    fd = open_file(node->right->cmd[0], dbl_out_redic);
    node->right->visited = true;
    node->left->data->input_fd = node->data->input_fd;
    node->left->data->output_fd = fd;
}

void simple_right_redic(ast_node_t *node)
{
    int fd = 0;

    if (node->right->visited == true) {
        node->data = reset_data_flux(node->data);
        return;
    }
    fd = open_file(node->right->cmd[0], smpl_out_redic);
    node->right->visited = true;
    node->left->data->input_fd = node->data->input_fd;
    node->left->data->output_fd = fd;
}

void simple_left_redic(ast_node_t *node)
{
    int fd = 0;

    if (node->right->visited == true) {
        node->data = reset_data_flux(node->data);
        return;
    }
    fd = open_file(node->right->cmd[0], smpl_int_redic);
    node->right->visited = true;
    node->left->data->input_fd = fd;
    node->left->data->output_fd = node->data->output_fd;
}

void handle_data_flux(ast_node_t *node)
{
    for (unsigned int i = 1; ope_table[i].ope != NULL; i++) {
        if (node->type == ope_table[i].type)
            ope_table[i].ope_func(node);
    }
}
