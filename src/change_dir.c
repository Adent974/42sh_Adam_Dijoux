/*
** EPITECH PROJECT, 2024
** change dir
** File description:
** change the current working directory
*/
#include "../includes/ast.h"
#include "../includes/memlib.h"
#include "../includes/strlib.h"
#include "../includes/ast.h"
#include <unistd.h>
#include <stdio.h>

int chdir_envar(char *new_dir, char ***env)
{
    if (chdir(new_dir) == -1) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    (*env) = update_in_env((*env), "PWD", new_dir);
    return 0;
}

int chdir_normal(char *new_dir, char ***env)
{
    char *current_dir = NULL;

    if (chdir(new_dir) == -1) {
        write(2, ": No such file or directory.\n", 29);
        return 1;
    }
    current_dir = getcwd(NULL, 0);
    (*env) = update_in_env((*env), "PWD", current_dir);
    mem_handler(current_dir, STORE);
    return 0;
}

char **change_to(char **env, char *new_dir, char *envar, int *exit)
{
    char *buffer = NULL;
    char *old_dir = getcwd(NULL, 0);

    mem_handler(old_dir, STORE);
    if (envar != NULL) {
        if (search_in_env(env, envar, &buffer, SEARCH_VALUE) < 0)
            return env;
    }
    env = update_in_env(env, "OLDPWD", old_dir);
    if (new_dir == NULL) {
        (*exit) = chdir_envar(buffer, &env);
    } else {
        (*exit) = chdir_normal(new_dir, &env);
    }
    return env;
}

int can_change(char **args, char **env)
{
    if ((env == NULL) || (env[0] == NULL))
        return 1;
    if (len_2d_array(args) == 1) {
        if (is_set(env, "HOME") == -1)
            return 1;
        return 0;
    }
    if (my_strcmp(args[1], "-") == 0) {
        if (is_set(env, "OLDPWD") == -1)
            return 1;
        return 0;
    }
    return 0;
}

int change_dir(ast_node_t *node)
{
    int exit = 0;

    if (can_change(node->cmd, node->env) == 1)
        return 0;
    if (change_dir_error(node->env, node->cmd) == -1)
        return 1;
    if (len_2d_array(node->cmd) == 1)
        node->env = change_to(node->env, NULL, "HOME", &exit);
    else if (my_strcmp(node->cmd[1], "-") == 0)
        node->env = change_to(node->env, NULL, "OLDPWD", &exit);
    else
        node->env = change_to(node->env, node->cmd[1], "PWD", &exit);
    return exit;
}
