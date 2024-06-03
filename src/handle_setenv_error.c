/*
** EPITECH PROJECT, 2024
** handle setenv error
** File description:
** handle_setenv_error
*/
#include "../includes/strlib.h"
#include "../includes/ast.h"
#include <signal.h>
#include <unistd.h>

error_t error_setenv[] = {
    {-1, "Too many arguments.\n", 21, SIGUSR1},
    {-2, "Variable name must begin with a letter.\n", 41, SIGUSR1},
    {-3, "Variable name must contain alphanumeric characters.\n", 53, SIGUSR1},
    {0, NULL, 0, 0}
};

int valid_char(char letter)
{
    int lowcase = IS_LOWER(letter);
    int upcase = IS_UPPER(letter);
    int num = IS_NUM(letter);

    if (lowcase == 1)
        return 1;
    if (upcase == 1)
        return 1;
    if (num == 1)
        return 1;
    return 0;
}

int set_env_error(char **args)
{
    int lowcase = 0;
    int upcase = 0;

    if (len_2d_array(args) > 3)
        return -1;
    lowcase = IS_LOWER(args[1][0]);
    upcase = IS_UPPER(args[1][0]);
    if (lowcase != 1 && upcase != 1)
        return -2;
    for (int i = 0; args[1][i] != '\0'; i++) {
        if (valid_char(args[1][i]) == 0)
            return -3;
    }
    return 0;
}

int handle_setenv_errror(char **args)
{
    int errnum = set_env_error(args);

    if (errnum == 0)
        return 0;
    for (int i = 0; error_setenv[i].errnum != 0; i++) {
        if (error_setenv[i].errnum == errnum) {
            write(2, "setenv: ", 8);
            write(2, error_setenv[i].errmsg, error_setenv[i].lenmsg);
            return -1;
        }
    }
    return 0;
}
