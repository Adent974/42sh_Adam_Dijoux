/*
** EPITECH PROJECT, 2024
** ast
** File description:
** ast
*/

#ifndef AST_H_
    #define AST_H_
    #include "memlib.h"
    #include "strlib.h"
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdbool.h>
    #define SEMI_COLON  ";"

    #define PIPE  "|"

    #define AND "&&"

    #define OR  "||"

    #define SMPl_INT_REDIC "<"

    #define DBl_INT_REDIC "<<"

    #define SMPl_OUT_REDIC ">"

    #define DBL_OUT_REDIC ">>"

    #define SUCCESS_EXIT 0

    #define FAILURE_EXIT 84

    #define WRONG_FORMAT "Exec format error. Wrong Architecture.\n"

    #define WHILE while

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;
    #define LIST linked_list_t
typedef enum ast_priority {
    none,
    left,
    right,
} priority_t;

typedef enum ast_node_type {
    node_error,
    leaf,
    semi_colon,
    and_t,
    or_t,
    pipe_t,
    smpl_int_redic,
    dbl_int_redic,
    smpl_out_redic,
    dbl_out_redic,
    parathenses,
} node_type_t;

typedef struct data_flux_s {
    bool is_segterm;
    bool is_exited;
    int signum;
    int exit_status;
    int input_fd;
    int output_fd;
} data_flux_t;

typedef struct ast_node_s {
    node_type_t type;
    priority_t priority;
    char **cmd;
    char **env;
    linked_list_t *variable;
    bool visited;
    int var_status;
    struct data_flux_s *data;
    struct ast_node_s *parents;
    struct ast_node_s *right;
    struct ast_node_s *left;
} ast_node_t;

typedef struct ope_table_t {
    char *ope;
    node_type_t type;
    priority_t prio;
    void (*ope_func)(ast_node_t *node);
} ope_table_t;

/// @brief define the priority with the type
/// @param type the type of the operators
/// @return returns the priority of the type
priority_t which_priority(node_type_t type);

/// @brief parse_cmd to find if it contains an operators
/// @param cmd the list of args to parse
/// @return returns the type of the operators
bool parse_cmd(char **cmd, char *operators);

/// @brief check if the command is an operators
/// @param cmd the command to check
/// @return returns the type of the operators
node_type_t parse_ope(char **cmd);

/// @brief check if the args is an operators
/// @param args the arguments to test
/// @return if `args` is an operators then `is_ope` returns his type
node_type_t is_ope(char *args);

/// @brief parse the ast
/// @param node the node to parse
/// @return returns then ast
ast_node_t *parse_ast(ast_node_t *node);

/// @brief create ast with command line
/// @param parents the parents of the node (set to null for the root)
/// @param cmd the command line given by th users
/// @param env the environment
/// @return returns the new ast object
ast_node_t *create_ast(ast_node_t *parents, char **cmd, char **env, LIST *var);

/// @brief segement the command line with operators priority
/// @param cvoid handle_or(ast_node_t *ast)
/// @return return a new array of command
/// @note deaclage de pointeur
char **segments_args(char ***cmd);

/// @brief do a simple pipe
/// @param node with the two parts of the pipe
void my_pipe(ast_node_t *node);

/// @brief implementation of '>>'
/// @param node the node to do '>>'
void double_right_redic(ast_node_t *node);

/// @brief execut a command
/// @param node the node to execute the command
void handle_exec(ast_node_t *node);

/// @brief open file selon redic_type
/// @param pathname the path or the name of the file
/// @param redic_type the type of redirections
/// @return retuns the fd of the new file
int open_file(char *pathname, node_type_t redic_type);

/// @brief handle_data_flux
/// @param node blabla
void handle_data_flux(ast_node_t *node);

/// @brief reset the data_flux object
/// @param flux the orginal data_flux
/// @return returns the new data flux
data_flux_t *reset_data_flux(data_flux_t *flux);

/// @brief implementation of '>'
/// @param node the node to execute the '>'
void simple_left_redic(ast_node_t *node);

/// @brief implementation of '<'
/// @param node the node to do '<'
void simple_right_redic(ast_node_t *node);

    #define SEARCH_ERROR(search) ((search < 0) || (search > 3)) ? (-1) : (0)
    #define SEARCH_IGN 0
    #define SEARCH_KEY 1
    #define SEARCH_VALUE 2
    #define SEARCH_KEY_VALUE 3
    #define ISLOWCASE(letter) ((letter > 96) && (letter < 123)) ? (1) : (0)
    #define ISUPCASE(letter) ((letter > 64) && (letter < 91)) ? (1) : (0)

typedef struct built_in_s {
    char *name;
    int (*func)(ast_node_t *node);
} built_in_t;

typedef struct error_s {
    int errnum;
    char *errmsg;
    int lenmsg;
    int signum;
} error_t;

// make a copy of the original env
char **env_copy(char **env);

// get the indexes of an environement key
int get_key_index(char **env, char *key);

// copy an environment variable
char *copy_envar(char *envar, int flags);

// search an key in the environment
int search_in_env(char **env, char *key, char **buff, int flags);

// set an environement variable
int set_env(ast_node_t *node);

// handle setenv error
int handle_setenv_errror(char **args);

// print the environment in stdout
int show_env(ast_node_t *node);

// unset an environement variable
int unset_env(ast_node_t *node);

// handle cd error
int change_dir_error(char **env, char **args);

// change the current working directory
int change_dir(ast_node_t *node);

// update en environment variable
char **update_in_env(char **env, char *key, char *value);

// read the input of the shell
char **read_input(int *status);

// clean a string
char *clean_str(char *str, char *delim, char *rep);

// turn a string to a string array
char **string_array(char *str, char *sep);

// eval the input
int eval_cmd(char **cmd, char **env);

// check if a env var is set
int is_set(char **env, char *key);

int len_2d_array(char **env);

/// @brief indicate if the given is executable
/// @param cmd the command to test
/// @return true if the command is executable, else false
bool is_exectubale(char *cmd);

/// @brief indicate if the command given is a built_in or not
/// @param cmd the command to check if he is a buitl_in
/// @return not_found on error case, blt_in on success case (see shell.h)
int is_built_in(char *cmd);

/// @brief indicate if the command is a binary
/// @param cmd the command to check
/// @return not_found if is not a binary and bin if is a binary
int is_bin(char *cmd);

int full_path(char *path_dir, char **cmd);

int parse_path(char **cmd, char **env);

char **array_append(char **array, char *app);

void command_not_found(char *cmd, int val);

void add_to_history(char *line);

int history_command(ast_node_t *node);

char *search_command_history(char *line);

char *get_history_line(int nb_line);

typedef enum cmd_type {
    not_found = 1,
    blt_in = 2,
    path = 3,
    bin = 4,
} cmd_t;

extern built_in_t built_in[];

/// @brief the table operatorsq
extern ope_table_t ope_table[9];

#endif /* !AST_H_ */
