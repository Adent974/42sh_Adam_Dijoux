/*
** EPITECH PROJECT, 2024
** personnal strlen
** File description:
** return the len of a string
*/

int my_strlen(char *str)
{
    int len = 0;

    if (!str)
        return 0;
    while (str[len] != '\0')
        len++;
    return len;
}
