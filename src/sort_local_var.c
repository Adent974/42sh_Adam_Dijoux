/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** sort linked list for local variable for 42sh
*/

#include "../includes/shell.h"

int add_to_var(linked_list_t **var, local_t *new_element)
{
    linked_list_t *tmp_var = *var;
    local_t *tmp_local = NULL;

    while (tmp_var != NULL) {
        tmp_local = (local_t *)tmp_var->data;
        if (!my_strcmp(tmp_local->variable_name, new_element->variable_name)){
            tmp_local->variable_data = new_element->variable_data;
            return 0;
        }
        tmp_var = tmp_var->next;
    }
    push_to_list(var, new_element);
    return 0;
}

int compare_local(const void *a, const void *b)
{
    const local_t *local_a = *(const local_t **)a;
    const local_t *local_b = *(const local_t **)b;

    return strcmp(local_a->variable_name, local_b->variable_name);
}

static int len_linked_list(linked_list_t *list)
{
    int count = 0;
    linked_list_t *current = list;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void sort_linked_list(linked_list_t **head_ref)
{
    int count = len_linked_list(*head_ref);
    linked_list_t *current = *head_ref;
    local_t *array[count];

    for (int i = 0; i < count; i++) {
        array[i] = current->data;
        current = current->next;
    }
    qsort(array, count, sizeof(local_t *), compare_local);
    current = *head_ref;
    for (int i = 0; i < count; i++) {
        current->data = array[i];
        current = current->next;
    }
}
