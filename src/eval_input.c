/*
** EPITECH PROJECT, 2024
** eval input
** File description:
** evaluate the input
*/
#include "../includes/ast.h"
#include "../includes/strlib.h"
#include <unistd.h>
#include <sys/stat.h>

void command_not_found(char *cmd, int val)
{
    struct stat st;

    if (val == 1)
        return;
    if (stat(cmd, &st) < 0) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Command not found.\n", 21);
    } else {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Permission denied.\n", 21);
    }
}

int eval_cmd(char **cmd, char **env)
{
    if (!*cmd)
        return not_found;
    if (is_built_in((*cmd)) == blt_in)
        return blt_in;
    if (!env)
        return not_found;
    if (is_bin((*cmd)) == bin)
        return bin;
    if ((parse_path(cmd, env)) == path)
        return path;
    return not_found;
}
