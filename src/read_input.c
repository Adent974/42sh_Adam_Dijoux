/*
** EPITECH PROJECT, 2024
** read input
** File description:
** read the input of the user
*/
#include "../includes/ast.h"
#include "../includes/memlib.h"
#include "../includes/strlib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *clean_str(char *str, char *delim, char *rep)
{
    char *dup = NULL;
    char *tok = NULL;
    char *clean = "";

    if (!str || !delim || !rep)
        return NULL;
    dup = my_strdup(str);
    tok = strtok(dup, delim);
    while (tok != NULL) {
        clean = my_strconcat(clean, tok);
        clean = my_strconcat(clean, rep);
        tok = strtok(NULL, delim);
    }
    return clean;
}

int set_read_status(int len, char *line)
{
    if (len == 1)
        return 0;
    if (len < 0) {
        mem_handler(NULL, DUMP);
        exit(0);
    }
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return 1;
    }
    return 0;
}

char *sticky_sep(char *str, char *sep)
{
    char *line = NULL;
    int size = 0;

    if (!str || !sep)
        return NULL;
    size = my_strlen(sep);
    for (unsigned int i = 0; str[i]; i++) {
        if (my_strncmp(str + i, sep, size) == 0) {
            line = my_strappend(line, ' ');
            line = my_strconcat(line, sep);
            line = my_strconcat(line, " ");
            continue;
        }
        line = my_strappend(line, str[i]);
    }
    return line;
}

char *format_line(char *line)
{
    int len = 0;

    line = search_command_history(line);
    for (unsigned int i = 0; ope_table[i].ope; i++)
        line = sticky_sep(line, ope_table[i].ope);
    line = clean_str(line, " ", "\n");
    line = clean_str(line, "\t", "\n");
    line = clean_str(line, "\n", " ");
    len = my_strlen(line);
    line[len - 1] = '\0';
    return line;
}

static void print_prompt(void)
{
    char *cwd = NULL;
    char **buffer_tab = NULL;
    int cmp = 0;

    cwd = getcwd(cwd, 0);
    if (cwd == NULL) {
        printf("$> ");
    } else if (my_strocc(cwd, '/') > 1) {
        buffer_tab = string_array(cwd, "/");
        WHILE(buffer_tab[cmp])
            cmp++;
        printf("[%s]$ ", buffer_tab[cmp - 1]);
    } else
        printf("[%s]$ ", cwd);
    free(cwd);
    fflush(stdout);
}

char **read_input(int *status)
{
    char *line = NULL;
    size_t size = 0;
    int len = 0;
    char *clean_line = NULL;
    char **args = NULL;

    if (isatty(0) == 1)
        print_prompt();
    len = getline(&line, &size, stdin);
    add_to_history(line);
    (*status) = set_read_status(len, line);
    if ((*status) > 0) {
        line[len - 1] = '\0';
        clean_line = format_line(line);
        free(line);
        args = string_array(clean_line, " ");
        return args;
    }
    free(line);
    return args;
}
