/*
** EPITECH PROJECT, 2024
** indetify cmd
** File description:
** indetitify the command given as inputs
*/
#include "../includes/ast.h"
#include "../includes/strlib.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "../includes/shell.h"

built_in_t built_in[] = {
    {"cd", &change_dir},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {"env", show_env},
    {"exit", &exit_builtin},
    {"set", &handle_variable},
    {"unset", &handle_variable},
    {"history", &history_command},
    {NULL, NULL},
};

bool is_exectubale(char *cmd)
{
    struct stat st;

    if (stat(cmd, &st) < 0)
        return false;
    if (S_ISDIR(st.st_mode) == 1)
        return false;
    if (access(cmd, F_OK) != 0 || access(cmd, X_OK) != 0)
        return false;
    return true;
}

int is_built_in(char *cmd)
{
    if (cmd == NULL)
        return not_found;
    for (int i = 0; built_in[i].name != NULL; i++)
        if (my_strcmp(cmd, built_in[i].name) == 0)
            return blt_in;
    return not_found;
}

int is_bin(char *cmd)
{
    struct stat file = {0};

    if (cmd == NULL)
        return not_found;
    if (stat(cmd, &file) < 0)
        return not_found;
    else if (access(cmd, F_OK) != 0 || S_ISDIR(file.st_mode) == 1)
        return not_found;
    else
        return bin;
}

int full_path(char *path_dir, char **cmd)
{
    char *binary = NULL;
    char *tmp = NULL;

    if ((path_dir == NULL) || (cmd == NULL))
        return not_found;
    tmp = my_strconcat("/", (*cmd));
    binary = my_strconcat(path_dir, tmp);
    if (is_exectubale(binary)) {
        (*cmd) = binary;
        return path;
    }
    return not_found;
}

int parse_path(char **cmd, char **env)
{
    char *path_env = NULL;
    char **path_dir = NULL;

    if (search_in_env(env, "PATH", &path_env, SEARCH_VALUE) < 0)
        return not_found;
    if (!path_env)
        return not_found;
    path_dir = string_array(path_env, ":");
    for (int i = 0; path_dir[i] != NULL; i++)
        if (full_path(path_dir[i], cmd) == path)
            return path;
    return not_found;
}
