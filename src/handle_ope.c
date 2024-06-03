/*
** EPITECH PROJECT, 2024
** handle operators
** File description:
** handle operators priority, error and type
*/
#include "../includes/ast.h"
#include "../includes/shell.h"
#include <string.h>
#include <stddef.h>
#include <stdio.h>

ope_table_t ope_table[9] = {
    {SEMI_COLON, semi_colon, left, NULL},
    {AND, and_t, left, &handle_and},
    {OR, or_t, left, &handle_or},
    {PIPE, pipe_t, left, &my_pipe},
    {SMPl_INT_REDIC, smpl_int_redic, right, &simple_left_redic},
    {DBl_INT_REDIC, dbl_int_redic, right, NULL},
    {SMPl_OUT_REDIC, smpl_out_redic, right, &simple_right_redic},
    {DBL_OUT_REDIC, dbl_out_redic, right, &double_right_redic},
    {NULL, leaf, none, NULL}
};

node_type_t parse_ope(char **cmd)
{
    node_type_t type = leaf;

    (void)type;
    if (!cmd)
        return leaf;
    for (unsigned int i = 0; ope_table[i].ope != NULL; i++)
        if (parse_cmd(cmd, ope_table[i].ope))
            return ope_table[i].type;
    return leaf;
}

bool parse_cmd(char **cmd, char *operators)
{
    if (!cmd)
        return false;
    for (unsigned int i = 0; cmd[i] != NULL; i++)
        if (strcmp(cmd[i], operators) == 0)
            return true;
    return false;
}

priority_t which_priority(node_type_t type)
{
    for (unsigned int i = 0; ope_table[i].prio != none; i++)
        if (ope_table[i].type == type)
            return ope_table[i].prio;
    return none;
}

node_type_t is_ope(char *args)
{
    if (!args)
        return node_error;
    for (unsigned int i = 0; ope_table[i].ope != NULL; i++)
        if (strcmp(args, ope_table[i].ope) == 0)
            return ope_table[i].type;
    return leaf;
}
