/*
** EPITECH PROJECT, 2024
** handle_rc
** File description:
** handles all the function needed for the rc (alias)
*/
#include "../includes/shell.h"
#include <fcntl.h>
#include <sys/stat.h>

int get_size(char *path)
{
    struct stat st;

    stat(path, &st);
    return st.st_size;
}

char *read_rc(void)
{
    int size = get_size("src/.42shrc");
    char *buff = my_malloc(sizeof(char) * size);
    int fd = open("src/.42shrc", O_RDONLY);

    if (fd == -1) {
        return NULL;
    }
    read(fd, buff, size);
    close(fd);
    return buff;
}

char **parse_alias(char **cmd, char **env)
{
    char **alias_tab = string_array(read_rc(), "\n");
    char **sub_table = NULL;
    char **fin_table = NULL;

    (void)env;
    for (int i = 0; alias_tab[i]; i++) {
        sub_table = string_array(alias_tab[i], "=");
        fin_table = string_array(sub_table[0], " ");
        if (my_strcmp(fin_table[1], cmd[0]) == 0) {
            fin_table = string_array(sub_table[1], "\'");
            return (string_array(fin_table[0], " "));
        }
    }
    return cmd;
}
