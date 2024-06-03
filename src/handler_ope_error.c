/*
** EPITECH PROJECT, 2024
** B-PSU-200-RUN-2-1-42sh-nicolas.samy
** File description:
** handler_ope_error
*/

#include "../includes/shell.h"

int handle_error(char **args)
{
    if (!args || !*args)
        return 1;
    if (is_ope(args[0]) != leaf)
        return 1;
    for (unsigned int i = 0; args[i]; i++) {
        if (is_ope(args[i]) != leaf && is_ope(args[i + 1]) != leaf) {
            return 1;
        }
    }
    return 0;
}
