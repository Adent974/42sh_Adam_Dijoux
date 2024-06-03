/*
** EPITECH PROJECT, 2024
** change dir error
** File description:
** handle change dire error
*/
#include "../includes/ast.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include "../includes/strlib.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int is_dir(char *path)
{
    DIR *dir = opendir(path);
    char *errmsg = NULL;

    if (dir == NULL) {
        errmsg = strerror(errno);
        write(2, path, my_strlen(path));
        write(2, ": ", 2);
        write(2, errmsg, my_strlen(errmsg));
        write(2, ".\n", 2);
        closedir(dir);
        return -1;
    }
    closedir(dir);
    return 0;
}

int is_set(char **env, char *key)
{
    int index = 0;
    char *buffer = NULL;

    index = search_in_env(env, key, &buffer, SEARCH_VALUE);
    if (index < 0)
        return -1;
    if (buffer == NULL)
        return -1;
    return 0;
}

int cd_param_error(char **args)
{
    if (len_2d_array(args) > 2) {
        write(2, "Too many arguments.\n", 20);
        return -1;
    }
    return 0;
}

int change_dir_error(char **env, char **args)
{
    (void)env;
    if (cd_param_error(args) < 0)
        return -1;
    if (len_2d_array(args) > 1) {
        if (my_strcmp(args[1], "-") == 0)
            return 0;
        if (is_bin(args[1]) == -1)
            return -1;
        if (is_dir(args[1]) == -1)
            return -1;
    }
    return 0;
}
