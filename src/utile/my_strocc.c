/*
** EPITECH PROJECT, 2024
** strocc
** File description:
** retur the occurences of a character in a string
*/

int my_strocc(char *str, char c)
{
    int cmp = 0;

    if (!str)
        return -1;
    for (unsigned int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            cmp++;
    return cmp;
}
