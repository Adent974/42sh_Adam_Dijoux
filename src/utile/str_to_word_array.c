/*
** EPITECH PROJECT, 2024
** my str to word array
** File description:
** transform a string into a string array
*/
#include <stdlib.h>
#include <stddef.h>
#include "../../includes/shell.h"

int check_separator(char s, char *sep)
{
    int i = 0;

    while (sep[i] != '\0') {
        if (s == sep[i])
            return 1;
        i++;
    }
    return 0;
}

void skip(char const *str, int *i, char *sep, int statut)
{
    if (check_separator(str[*i], sep) == -1 && statut) {
        while (check_separator(str[*i], sep))
            (*i)++;
        (*i)--;
    }
    if (!statut) {
        while (check_separator(str[*i], sep) && str[*i]) {
            (*i)++;
        }
    }
}

int nb_space(char const *str, char *sep)
{
    int i = 0;
    int space = 1;

    while (str[i] != '\0') {
        skip(str, &i, sep, 1);
        space += 1;
        i++;
    }
    return space;
}

int word_len(char *str, int i, char *sep)
{
    int len = 0;

    while (!check_separator(str[i], sep) && str[i]) {
        len++;
        i++;
    }
    return len;
}

char **string_array(char *str, char *sep)
{
    int space = nb_space(str, sep) + 2;
    int i = 0;
    char **tab = my_malloc(sizeof(char *) * space + 1);
    int y = 0;

    for (int x = 0; str[i] != '\0'; x = 0) {
        skip(str, &i, sep, 0);
        tab[y] = my_malloc(sizeof(char) * (word_len(str, i, sep) + 1));
        while (!check_separator(str[i], sep) && str[i] != '\0') {
            tab[y][x] = str[i];
            i++;
            x++;
        }
        tab[y][x] = '\0';
        y++;
        skip(str, &i, sep, 0);
    }
    tab[y] = NULL;
    return tab;
}
