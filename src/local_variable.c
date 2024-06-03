/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** local variable
*/

#include "../includes/shell.h"

void print_local_var(void *data)
{
    local_t *element = (local_t *)data;

    printf("%s", element->variable_name);
    if (element->variable_data != NULL)
        printf("\t%s\n", element->variable_data);
    else
        printf("\n");
    fflush(stdout);
}

char **split_array(char *cmd, char c)
{
    char **tab = my_malloc(sizeof(char *) * 3);
    int index = 0;

    while (cmd[index] != '\0' && cmd[index] != c)
        index++;
    if (index == 0)
        return NULL;
    tab[0] = my_strndup(cmd, index);
    index++;
    cmd += index;
    if (*cmd) {
        tab[1] = my_strdup(cmd);
    } else
        tab[1] = NULL;
    tab[2] = NULL;
    return tab;
}

static int error_case(char *name)
{
    int is_apha = IS_ALPHA(name[0]);
    char *err = "set: Variable name must contain alphanumeric characters.\n";

    if (!name)
        return 1;
    if (!my_strcmp(name, "_"))
        return 0;
    if (!is_apha) {
        write(2, "set: Variable name must begin with a letter.\n", 45);
        return 1;
    }
    if (!my_str_isalphanum(name)) {
        write(2, err, 57);
        return 1;
    }
    return 0;
}

int exec_set_variable(ast_node_t *node, int i, linked_list_t **var, char **tab)
{
    local_t *new_element = NULL;

    if (!my_strncmp(node->cmd[i], "=", 1)) {
        write(2, "set: Variable name must begin with a letter.\n", 45);
        return 1;
    }
    tab = split_array(node->cmd[i], '=');
    new_element = my_malloc(sizeof(local_t));
        new_element->variable_name = tab[0];
        new_element->variable_data = tab[1];
    if (error_case(tab[0]))
        return 1;
    return add_to_var(var, new_element);
}

int handle_variable(ast_node_t *node)
{
    if (!my_strcmp(node->cmd[0], "set")) {
        return set_variable(node, &node->variable);
    } else if (!my_strcmp(node->cmd[0], "unset")) {
        return unset_variable(node, &node->variable);
    }
    return 0;
}

int set_variable(ast_node_t *node, linked_list_t **variables)
{
    int len_tab = len_2d_array(node->cmd);
    int val = 0;
    char **tab = NULL;

    if (len_tab == 1){
        print_list(*variables, &print_local_var);
        return 0;
    }
    for (int i = 1; node->cmd[i] && val == 0; i++) {
        val = exec_set_variable(node, i, variables, tab);
        if (val != 0)
            return 84;
    }
    sort_linked_list(variables);
    return 0;
}
