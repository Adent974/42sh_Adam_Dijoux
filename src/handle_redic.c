/*
** EPITECH PROJECT, 2024
** handle redic
** File description:
** handle redirection input output in command line
*/
#include "../includes/ast.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int open_mode(char *pathname, int exist, node_type_t redic_type)
{
    if (redic_type == dbl_out_redic) {
        if (exist < 0)
            return open(pathname, O_CREAT | O_RDWR | O_APPEND, 00644);
        return open(pathname, O_RDWR | O_APPEND);
    }
    if (redic_type == smpl_out_redic) {
        if (exist < 0)
            return open(pathname, O_CREAT | O_TRUNC | O_RDWR, 00644);
        return open(pathname, O_TRUNC | O_RDWR);
    }
    if (redic_type == smpl_int_redic)
        return open(pathname, O_RDWR);
    return -1;
}

int open_file(char *pathname, node_type_t redic_type)
{
    int fd = 0;
    struct stat st;
    int exist = stat(pathname, &st);

    if (exist < 0 && redic_type == smpl_int_redic)
        return -1;
    fd = open_mode(pathname, exist, redic_type);
    if (fd < 0)
        return -1;
    return fd;
}
