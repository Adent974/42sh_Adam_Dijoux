/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** exit builtin
*/

#include "../includes/shell.h"

int my_str_is_num_negatif(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    if (!my_strcmp(str, "-"))
        return 0;
    i = (str[i] == '-') ? 1 : 0;
    while (str[i]) {
        if (!IS_NUM(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int exit_builtin(ast_node_t *node)
{
    int exit_status = node->data->exit_status;
    int len_tab = len_2d_array(node->cmd);
    char *error_string = "exit: Expression Syntax.\n";

    if (len_tab > 2) {
        write(2, error_string, my_strlen(error_string));
        return 84;
    }
    if (len_tab == 1) {
        mem_handler(NULL, DUMP);
        exit(exit_status);
    }
    if (!my_str_is_num_negatif(node->cmd[1]))
        write(2, error_string, my_strlen(error_string));
    else {
        exit_status = atoi(node->cmd[1]);
        mem_handler(NULL, DUMP);
        exit(exit_status);
    }
    return 84;
}
