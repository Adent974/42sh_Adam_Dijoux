/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/ast.h"
#include "../includes/shell.h"
#include <assert.h>
int my_strlen_tab(char **tab);

Test(test1, ls)
{
    char *args[] = {"ls", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "ls");
}

Test(test2, ls)
{
    char *args[] = {"ls", "-l", "-a", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_eq(strcmp(ast->cmd[0], "ls"), 0);
    cr_assert_eq(strcmp(ast->cmd[1], "-l"), 0);
    cr_assert_eq(strcmp(ast->cmd[2], "-a"), 0);
}

Test(test17, ls)
{
    char *args[] = {"ls", "-zae", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_eq(strcmp(ast->cmd[0], "ls"), 0);
    cr_assert_eq(strcmp(ast->cmd[1], "-zae"), 0);
}

Test(test3, cd)
{
    char *args[] = {"cd", "/usr", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "cd");
    cr_assert_str_eq(ast->cmd[1], "/usr");
}

Test(test4, cd)
{
    char *args[] = {"cd", "-", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "cd");
    cr_assert_str_eq(ast->cmd[1], "-");
}

Test(test5, kk)
{
    char *args[] = {"azertyui", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "azertyui");
}

Test(test6, void)
{
    char *args[] = {"", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "");
}

Test(test7, exit)
{
    char *args[] = {"exit", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "exit");
}

Test(test8, pipe)
{
    char *args[] = {"ls", "|", "rev", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_neq(ast->type, leaf);
    cr_assert_not_null(ast->left);
    cr_assert_not_null(ast->right);
    cr_assert_str_eq(ast->left->cmd[0], "ls");
    cr_assert_str_eq(ast->right->cmd[0], "rev");
}

Test(test9, semi_colon)
{
    char *args[] = {"ls", ";", "pwd", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_neq(ast->type, leaf);
    cr_assert_not_null(ast->left);
    cr_assert_not_null(ast->right);
    cr_assert_str_eq(ast->left->cmd[0], "ls");
    cr_assert_str_eq(ast->right->cmd[0], "pwd");
}

Test(test10, unset_env)
{
    char *args[] = {"unsetenv", "OLDPWD", NULL};
    char *env[] = {"OLDPWD=/home/nsamy", NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "unsetenv");
    cr_assert_str_eq(ast->cmd[1], "OLDPWD");
}

Test(test11, malloc)
{
    void *result = my_malloc(0);
    cr_assert_null(result, "null");
}

Test(test12, many_combinations)
{
    char *args[] = {"ls", ">", "toto", "|", "rev", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_neq(ast->type, leaf);
    cr_assert_not_null(ast->left);
    cr_assert_not_null(ast->right);
    cr_assert_str_eq(ast->right->cmd[0], "rev");
    cr_assert_not_null(ast->left->left);
    cr_assert_not_null(ast->left->right);
    cr_assert_str_eq(ast->left->right->cmd[0], "toto");
    cr_assert_str_eq(ast->left->left->cmd[0], "ls");
}

Test(test13, str_to_word_array1)
{
    char *str = "hello,world;here";
    char *sep = ",;";
    char **result = string_array(str, sep);
    cr_assert_not_null(result);
    cr_assert_str_eq(result[0], "hello");
    cr_assert_str_eq(result[1], "world");
    cr_assert_str_eq(result[2], "here");
}

Test(test14, env)
{
    char *args[] = {"env", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "env");
}

void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test15, show_env_test, .init = redirect_stdout)
{
    char *cmd[] = {"env", NULL};
    char *envp[] = {"aaaa=bbbb", "HOME=/home/user", NULL};
    data_flux_t data = {.output_fd = STDOUT_FILENO};
    ast_node_t node = {.cmd = cmd, .env = envp, .data = &data};

    int result = show_env(&node);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("aaaa=bbbb\nHOME=/home/user\n");
}

Test(my_strlen, return_val)
{
    int res = my_strlen("azerty");
    cr_assert_eq(strlen("azerty"), res);
}

Test(test5, rien)
{
    char *args[] = {"\n",NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "\n");
}

Test(test15, rien)
{
    char *args[] = {"\n",NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "\n");
}

Test(test16, cd)
{
    char *args[] = {"cd", "azerty", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "cd");
    cr_assert_str_eq(ast->cmd[1], "azerty");
}

Test(test18, pwd)
{
    char *args[] = {"pwd", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "pwd");
}

Test(test19, pwd_err)
{
    char *args[] = {"pwd", "azerty", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "pwd");
    cr_assert_str_eq(ast->cmd[1], "azerty");
}

Test(test20, setenv)
{
    char *args[] = {"setenv", "a", "azerty", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "setenv");
    cr_assert_str_eq(ast->cmd[1], "a");
    cr_assert_str_eq(ast->cmd[2], "azerty");
}

Test(test21, setenv)
{
    char *args[] = {"setenv", "a", "azerty", NULL};
    char *env[] = {"a=azerty"};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "setenv");
    cr_assert_str_eq(ast->cmd[1], "a");
    cr_assert_str_eq(ast->cmd[2], "azerty");
}

Test(test22, unsetenv)
{
    char *args[] = {"unsetenv", "a", "azerty", NULL};
    char *env[] = {"a=azerty"};
    ast_node_t *ast = create_ast(NULL, args, env, NULL);

    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "unsetenv");
    cr_assert_str_eq(ast->cmd[1], "a");
    cr_assert_str_eq(ast->cmd[2], "azerty");
}

Test(test23, create_ast_NULL)
{
    char **args = NULL;
    char **env = NULL;
    ast_node_t *ast = create_ast(NULL, args, env, NULL);
    (void)ast;
}

Test(test24, len_2d_arraytest)
{
    char **env = NULL;
    int res = len_2d_array(env);
    cr_assert_eq(res, 0);
}

Test(test25, len_2d_arraytest)
{
    char *env[] = {"bonjour", "hello", "salut", NULL};
    int res = my_strlen_tab(env);
    cr_assert_eq(res, 3);
}

Test(test26, his_cmd)
{
    char *args[] = {"history", "-c", NULL};
    char **env = NULL;
    ast_node_t *ast = create_ast(NULL, args, env, NULL);
    int result = history_command(ast);
    cr_assert_not_null(ast);
    cr_assert_eq(ast->type, leaf);
    cr_assert_null(ast->left);
    cr_assert_null(ast->right);
    cr_assert_str_eq(ast->cmd[0], "history");
    cr_assert_str_eq(ast->cmd[1], "-c");
    (void)result;
}

Test(test27, add_to_history)
{
    char *line = "echo prout";
    cr_redirect_stdout();
    add_to_history(line);
}

Test(test28, unsetvar)
{
    char *env[] = {"salut=hello", "toto=titi", "tutu=titu", NULL};
    int index = 1;
    int size = sizeof(env[index]);
    unset_envar(env, index, size);
}

Test(test29, show_env_test, .init = redirect_stdout)
{
    char *cmd[] = {"env", NULL};
    char **env = NULL;
    data_flux_t data = {.output_fd = STDOUT_FILENO};
    ast_node_t node = {.cmd = cmd, .env = env, .data = &data};
    int result = show_env(&node);

    cr_assert_eq(result, 0);
}

Test(test30, show_env_test, .init = redirect_stdout)
{
    char *cmd[] = {"env", "zaea", NULL};
    char *env[] = {"Hello", "World", NULL};
    data_flux_t data = {.output_fd = STDOUT_FILENO};
    ast_node_t node = {.cmd = cmd, .env = env, .data = &data};
    int result = show_env(&node);

    cr_assert_eq(result, 1);
}

Test(test31, setenv)
{
    char *cmd[] = {"setenv", "xd", "azer", NULL};
    char *env[] = {"a=aaaa", "xd=xadv", NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);

    set_env(ast);
}

Test(test32, setenv)
{
    char *cmd[] = {"setenv", "xd", NULL};
    char *env[] = {"a=aaaa", "xd=xadv", NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);

    set_env(ast);
}

Test(test33, setenv)
{
    char *env[] = {NULL};

    define_len_env(env);
}

Test(test34, setenv)
{
    char *env[] = {"toto=tit", "tata=tutu", NULL};

    define_len_env(env);
}

Test(test35, setenv)
{
    char *env[] = {"toto=tit", "tata=tutu", NULL};
    char *key = "tuta";
    char *value = "tatu";

    add_in_env(env, key, value);
}

Test(test36, setenv)
{
    char *cmd[] = {"setenv", NULL};
    char *env[] = {"aaaa=bbbb", "cccc=dddd", NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);
    int result;

    cr_redirect_stdout();
    result = set_env(ast);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("aaaa=bbbb\ncccc=dddd\n");
}

Test(test37, setenv)
{
    char *cmd[] = {"setenv", "a", "b", "c", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);
    int result = set_env(ast);

    cr_assert_eq(result, 1);
}

Test(test38, setenv)
{
    char *cmd[] = {"setenv", "a", "b", NULL};
    char *env[] = {NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);
    int result = set_env(ast);

    cr_assert_eq(result, 0);
}

Test(test39, unsetenv)
{
    char *cmd[] = {"unsetenv", NULL};
    char *env[] = {"aaaa=bbbb", "cccc=dddd", NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);
    int result;

    cr_redirect_stdout();
    unset_env(ast);
    (void)result;
}

Test(test40, unsetenv)
{
    char *cmd[] = {"unsetenv", "aaaa", NULL};
    char *env[] = {"aaaa=bbbb", "cccc=dddd", NULL};
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);
    int result;

    cr_redirect_stdout();
    unset_env(ast);
    (void)result;
}

Test(test41, unsetenv)
{
    char *cmd[] = {"unsetenv", "aaaa", NULL};
    char **env = NULL;
    ast_node_t *ast = create_ast(NULL, cmd, env, NULL);
    int result;

    cr_redirect_stdout();
    result = unset_env(ast);
    cr_assert_eq(result, 0);
}

Test(test42, clean_str)
{
    char *input = "hello world";
    char *result = clean_str(input, " ", "");

    cr_assert_str_eq(result, "helloworld");
}

Test(test43, clean_str)
{
    char *input = NULL;
    char *result = clean_str(input, " ", "");

    cr_assert_eq(result, NULL);
}

Test(test44, set_read_status)
{
    char *line = "\n";
    int status = set_read_status(1, line);

    cr_assert_eq(status, 0);
}

Test(test45, set_read_status)
{
    char *line = "\n";
    int status = set_read_status(-1, line);

    cr_assert_eq(status, 0);
}

Test(test46, set_read_status)
{
    char *line = "echo hello\n";
    int status = set_read_status(11, line);

    cr_assert_eq(status, 1);
}

Test(test47, set_read_status)
{
    char *line = " \t\n";
    int status = set_read_status(strlen(line), line);

    cr_assert_eq(status, 0);
}

Test(test48, sticky_sep)
{
    char *input = "hello;world";
    char *result = sticky_sep(input, ";");

    cr_assert_str_eq(result, "hello ; world");
}

Test(test49, sticky_sep)
{
    char *input = NULL;
    char *result = sticky_sep(input, ";");

    cr_assert_eq(result, NULL);
}

Test(test50, formatline)
{
    char *input = " ls -la ";
    char *result = format_line(input);

    cr_assert_str_eq(result, "ls -la");
}

Test(test51, compy_envar_error)
{
    copy_envar(NULL, 1);
}

Test(test52, compy_envar_error)
{
    copy_envar("salut", -1);
}

Test(test53, compy_envar_error)
{
    copy_envar("salut", 1);
}

Test(test54, is_value)
{
    is_value(NULL);
}

Test(test55, is_value)
{
    is_value("salut =");
}

Test(test56, copy_envar)
{
    copy_envar("Salut", 2);
}

Test(test57, copy_envar)
{
    copy_envar("Salut", 3);
}

Test(test58, env_copy)
{
    char *env[] = {"toto=tata", "tutu=titi", NULL};

    env_copy(env);
}

Test(test59, env_copy)
{
    char *env[] = {NULL};

    env_copy(env);
}

Test(test60, eval_cmd)
{
    char *cmd[] = {NULL};
    eval_cmd(cmd, NULL);
}

Test(test61, eval_cmd)
{
    char *cmd[] = {"cd", NULL};
    eval_cmd(cmd, NULL);
}

Test(test62, eval_cmd)
{
    char *cmd[] = {"ls", NULL};
    eval_cmd(cmd, NULL);
}

Test(test63, parse_path)
{
    char *args[] = {"echo", "hello", NULL};
    char *env[] = {NULL};
    ast_node_t node = {.cmd = args, .env = env,
        .data = malloc(sizeof(data_flux_t))};
    cmd_t cmd_type = blt_in;

    node.data->exit_status = 0;
    handle_exec(&node);
    cr_assert_eq(node.data->exit_status, 0);
    (void)cmd_type;
}

Test(test64, is_built_in)
{
    char *cmd = NULL;
    is_built_in(cmd);
}

Test(test65, full_path)
{
    char *path = "PATH=/usr/local/bin:/usr/bin:/usr/local/sbin";
    char *cmd[] = {"ls", NULL};
    full_path(path, cmd);
}

Test(test66, parse_path)
{
    char *cmd[] = {"ls", NULL};
    char *path[] = {"PATH=/usr/local/bin:/usr/bin:/usr/local/sbin", NULL};
    parse_path(cmd, path);
}

Test(test67, parse_path)
{
    char *cmd[] = {"ls", NULL};
    char *path[] = {NULL};
    parse_path(cmd, path);
}
