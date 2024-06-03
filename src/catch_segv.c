/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** catch segv signal
*/

#include "../includes/shell.h"

void catch_segv(int value)
{
    (void)value;
    exit(1);
}
