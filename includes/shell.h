/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** 42sh
*/

#ifndef __SHELL_H_
    #define __SHELL_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>
    #include "ast.h"
    #include <limits.h>
    #include <signal.h>


/* Linked lists functions*/
void push_to_list(linked_list_t **list, void *data);
void print_list(linked_list_t *list, void (*print_function) (void *));
void append_to_list(linked_list_t **list, void *data);
void delete_from_list(linked_list_t **list, void *data);
void free_list(linked_list_t **list);
/*********************/

/* Local Variable*/
typedef enum local_enum_s {
    SET,
    UNSET
}local_enum_t;

typedef struct local_s {
    char *variable_name;
    char *variable_data;
} local_t;
    #define LIST_VAR linked_list_t **prev, linked_list_t **variables

void init_locale(LIST **variable, char **env);
void rm_var(char *data, linked_list_t **tmp, LIST_VAR);
int unset_variable(ast_node_t *node, linked_list_t **variables);
void sort_linked_list(linked_list_t **head_ref);
int set_variable(ast_node_t *node, linked_list_t **variables);
int handle_variable(ast_node_t *node);
int add_to_var(linked_list_t **var, local_t *new_element);
ast_node_t *replace_local_var(ast_node_t *node);
/*****************/

int exit_builtin(ast_node_t *node);
void handle_and(ast_node_t *ast);
void handle_or(ast_node_t *ast);
int handle_error(char **args);
void (*signal(int signum, void (*sighandler)(int)))(int);
void catch_segv(int value);
char **parse_alias(char **cmd, char **env);

int define_len_env(char **env);
char **unset_envar(char **env, int index, int size);
char **add_in_env(char **env, char *key, char *value);
int set_read_status(int len, char *line);
char *sticky_sep(char *str, char *sep);
char *format_line(char *line);
int copy_envar_error(char *envar, int flags);
int is_value(char *envar);



#endif /* !__SHELL_H_ */
