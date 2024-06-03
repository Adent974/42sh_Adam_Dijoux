/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** init locale variable
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../includes/ast.h"
#include "../includes/shell.h"

void add_locale(LIST **variable, char *name, char *var)
{
    local_t *element = my_malloc(sizeof(local_t));

    element->variable_name = my_strdup(name);
    element->variable_data = my_strdup(var);
    push_to_list(variable, element);
    sort_linked_list(variable);
}

char *format_path(char *path)
{
    int path_len = my_strlen(path);
    char *path_format = my_malloc(sizeof(char) * (path_len + 3));

    for (int i = 0; path[i]; i++) {
        if (path[i] == ':')
            path[i] = ' ';
    }
    path_format[0] = '(';
    for (int i = 0; path[i]; i++)
        path_format[i + 1] = path[i];
    path_format[path_len + 1] = ')';
    path_format[path_len + 2] = '\0';
    return path_format;
}

void init_locale(LIST **variable, char **env)
{
    char buff[1000];
    char *buffer = NULL;
    char *cwd = my_strdup(getcwd(buff, 1000));

    signal(SIGSEGV, catch_segv);
    if (cwd != NULL)
        add_locale(variable, "cwd", cwd);
    (void)buffer;
    search_in_env(env, "PATH", &buffer, SEARCH_VALUE);
    if (buffer != NULL)
        add_locale(variable, "PATH", format_path(buffer));
}
