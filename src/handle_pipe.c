/*
** EPITECH PROJECT, 2024
** B-PSU-200-RUN-2-1-42sh-nicolas.samy
** File description:
** handle_pipe
*/
#include "../includes/ast.h"
#include <unistd.h>
#include <fcntl.h>

int reset_pipe_flux(ast_node_t *node)
{
    if (node->left->visited && node->right->visited) {
        node->data = reset_data_flux(node->data);
        return 1;
    }
    if (node->left->visited == true) {
        if (node->data)
        close(node->left->data->output_fd);
        node->left->data->output_fd = STDOUT_FILENO;
        return 1;
    }
    if (node->right->visited == true) {
        close(node->right->data->input_fd);
        node->right->data->input_fd = STDIN_FILENO;
        return 1;
    }
    return 0;
}

void my_pipe(ast_node_t *node)
{
    int fdpipe[2];
    int errnum = 0;

    (void)errnum;
    if (reset_pipe_flux(node) == 1)
        return;
    if (pipe(fdpipe) < 0)
        return;
    node->left->data = node->data;
    node->left->data->output_fd = fdpipe[1];
    node->right->data->input_fd = fdpipe[0];
}
