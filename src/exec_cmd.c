/*
** EPITECH PROJECT, 2024
** B-PSU-200-RUN-2-1-42sh-nicolas.samy
** File description:
** handle_exec
*/
#include "../includes/shell.h"
#include "../includes/ast.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exec_cmd(ast_node_t *node)
{
    if (node->data->input_fd != STDIN_FILENO) {
        dup2(node->data->input_fd, STDIN_FILENO);
        close(node->data->input_fd);
    }
    if (node->data->output_fd != STDOUT_FILENO) {
        dup2(node->data->output_fd, STDOUT_FILENO);
        close(node->data->output_fd);
    }
    if (execve(node->cmd[0], node->cmd, node->env) < 0) {
        fprintf(stderr, "%s: %s", node->cmd[0], WRONG_FORMAT);
        exit(1);
    }
    exit(0);
}

static void print_signal(ast_node_t *node, int status)
{
    if (!WCOREDUMP(status)) {
        if (node->data->signum == SIGFPE) {
            fprintf(stderr, "Floating exception\n");
        } else
            fprintf(stderr, "%s\n", strsignal(WTERMSIG(status)));
    } else {
        if (node->data->signum == SIGFPE) {
            fprintf(stderr, "Floating exception (core dumped)\n");
        } else
            fprintf(stderr, "%s (core dumped)\n", strsignal(WTERMSIG(status)));
    }
}

void fill_data_flux(ast_node_t *node, int status)
{
    if (WIFSIGNALED(status)) {
        node->data->is_segterm = true;
        node->data->is_exited = false;
        node->data->exit_status = FAILURE_EXIT;
        node->data->signum = WTERMSIG(status);
        print_signal(node, status);
    } else {
        node->data->is_exited = true;
        node->data->is_segterm = false;
        node->data->exit_status = WEXITSTATUS(status);
        node->data->signum = 0;
    }
}

ast_node_t *wait_cmd(ast_node_t *node, pid_t cpid)
{
    int status = 0;
    int input_fd = node->data->input_fd;
    int output_fd = node->data->output_fd;

    if (input_fd != STDIN_FILENO || output_fd != STDOUT_FILENO) {
        (void)cpid;
    } else
        waitpid(cpid, &status, WCONTINUED);
    fill_data_flux(node, status);
    return node;
}

int exec_blt_in(ast_node_t *node)
{
    for (unsigned int i = 0; built_in[i].name != NULL; i++) {
        if (my_strcmp(built_in[i].name, node->cmd[0]) == 0)
            return built_in[i].func(node);
    }
    return -1;
}

void handle_exec(ast_node_t *node)
{
    pid_t cpid = 0;
    cmd_t cmd_type = eval_cmd(&node->cmd[0], node->env);

    node = replace_local_var(node);
    if (node->var_status == 1 || cmd_type == not_found) {
        command_not_found(node->cmd[0], node->var_status);
        return;
    }
    if (cmd_type == blt_in) {
        node->data->exit_status = exec_blt_in(node);
        return;
    }
    cpid = fork();
    if (cpid < 0)
        return;
    else if (cpid == 0)
        exec_cmd(node);
    else
        node = wait_cmd(node, cpid);
}
