/*
** EPITECH PROJECT, 2024
** personnal strcat
** File description:
** concat two strings in one
*/
#include <stddef.h>

void my_strcat(char *dest, char *s1, char *s2)
{
    int index = 0;

    if (!dest)
        return;
    if (s1 != NULL) {
        for (int i = 0; s1[i] != '\0'; i++) {
            dest[index] = s1[i];
            index++;
        }
    }
    if (s2 != NULL) {
        for (int i = 0; s2[i] != '\0'; i++) {
            dest[index] = s2[i];
            index++;
        }
    }
    dest[index] = '\0';
}
