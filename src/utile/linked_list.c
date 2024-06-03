/*
** EPITECH PROJECT, 2024
** list
** File description:
** list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "../../includes/shell.h"

void push_to_list(linked_list_t **list, void *data)
{
    linked_list_t *new_element = my_malloc(sizeof(linked_list_t));

    if (!new_element)
        return;
    new_element->data = data;
    new_element->next = (*list);
    (*list) = new_element;
}

void print_list(linked_list_t *list, void (*print_function) (void *))
{
    linked_list_t *save = list;

    while (save != NULL) {
        print_function(save->data);
        save = save->next;
    }
}

void append_to_list(linked_list_t **list, void *data)
{
    linked_list_t *new_element = my_malloc(sizeof(linked_list_t));
    linked_list_t *last = NULL;

    if (!new_element)
        return;
    new_element->data = data;
    new_element->next = NULL;
    if (*list == NULL) {
        *list = new_element;
        return;
    }
    last = *list;
    while (last->next != NULL)
        last = last->next;
    last->next = new_element;
}

void delete_from_list(linked_list_t **list, void *data)
{
    linked_list_t *current = *list;
    linked_list_t *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    if (prev == NULL)
        *list = current->next;
    else
        prev->next = current->next;
    free(current);
}

void free_list(linked_list_t **list)
{
    linked_list_t *current = *list;
    linked_list_t *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *list = NULL;
}
