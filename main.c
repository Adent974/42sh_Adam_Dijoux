/*
** EPITECH PROJECT, 2024
** B-PSU-200-RUN-2-1-42sh-nicolas.samy
** File description:
** main
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "includes/ast.h"
#include "includes/shell.h"

static int end_shell(int exit_status)
{
    mem_handler(NULL, DUMP);
    return exit_status;
}

int my_shell(char **env)
{
    int status = 0;
    char **args = NULL;
    ast_node_t *ast = NULL;
    char **envcpy = my_memdup(env);
    int exit_status = 0;
    linked_list_t *variable = NULL;

    init_locale(&variable, envcpy);
    while (1) {
        args = read_input(&status);
        if (handle_error(args) > 0)
            continue;
        ast = create_ast(NULL, args, envcpy, variable);
        ast = parse_ast(ast);
        envcpy = ast->env;
        variable = ast->variable;
        exit_status = ast->data->exit_status;
    }
    return end_shell(exit_status);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    if (!*env || !env)
        return my_shell(NULL);
    else
        return my_shell(env);
}
