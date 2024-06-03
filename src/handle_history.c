/*
** EPITECH PROJECT, 2024
** handle_history
** File description:
** save last commands
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "../includes/ast.h"
#include "../includes/shell.h"

int my_strlen_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

int history_command(ast_node_t *node)
{
    char *buffer = NULL;
    size_t len = 0;
    FILE *fd = NULL;

    if (my_strlen_tab(node->cmd) > 1 && strcmp(node->cmd[1], "-c") == 0)
        remove("/tmp/.42sh_history");
    fd = fopen("/tmp/.42sh_history", "r");
    if (!fd)
        return 1;
    while (getline(&buffer, &len, fd) > 0)
        printf("%s", buffer);
    free(buffer);
    fclose(fd);
    return 0;
}

static int get_nb_line(void)
{
    char *buffer = NULL;
    size_t len = 0;
    FILE *fd = fopen("/tmp/.42sh_history", "r");
    char *last_line = NULL;
    int nb = 0;

    while (getline(&buffer, &len, fd) > 0){
        last_line = my_strdup(buffer);
    }
    if (last_line)
        nb = atoi(last_line);
    fclose(fd);
    free(buffer);
    return nb;
}

static bool existing_char(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return true;
    return false;
}

void add_to_history(char *line)
{
    FILE *fd = fopen("/tmp/.42sh_history", "a+");
    time_t rawtime;
    struct tm *timeinfo;
    int nb_line = get_nb_line();

    if (existing_char(line, '!')){
        fclose(fd);
        return;
    }
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    fprintf(fd, " %d  %02d:%02d  %s", nb_line + 1, timeinfo->tm_hour,
    timeinfo->tm_min, line);
    fclose(fd);
}

char *get_history_line(int nb_line)
{
    FILE *fd = fopen("/tmp/.42sh_history", "r");
    char *line = NULL;
    char **tab = NULL;
    size_t size = 0;

    if (!fd)
        return NULL;
    if (nb_line == -1) {
        while (getline(&line, &size, fd) > 0);
        if (strlen(line) == 0)
            printf("0: Event not found.\n");
        tab = string_array(line, ":");
        return tab[1] + 3;
    }
    while (getline(&line, &size, fd) > 0)
        if (atoi(line) == nb_line) {
            tab = string_array(line, ":");
            return tab[1] + 3;
        }
    return NULL;
}

char *search_command_history(char *line)
{
    char *command = strstr(line, "!");
    char *command_found = NULL;

    if (!command)
        return line;
    if (strcmp(command, "!!") == 0) {
        return get_history_line(-1);
    }
    if (strlen(command) > 1 && command[0] == '!'){
        command_found = get_history_line(atoi(command + 1));
        if (!command_found){
            printf("%d: Event not found.\n", atoi(command + 1));
            return line;
        }
    }
    return command_found;
}
