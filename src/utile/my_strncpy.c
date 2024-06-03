/*
** EPITECH PROJECT, 2024
** personnal strncpy
** File description:
** copy n byte of a string
*/

void my_strncpy(char *dest, char *src, int nbyte)
{
    if (!src || !dest || nbyte <= 0)
        return;
    for (int i = 0; i < nbyte; i++)
        dest[i] = src[i];
    dest[nbyte] = '\0';
}
