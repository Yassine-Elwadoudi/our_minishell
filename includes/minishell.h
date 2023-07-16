/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:04:19 by asabri            #+#    #+#             */
/*   Updated: 2023/07/16 15:14:36 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft-42/libft.h"
# include "ft_malloc.h"
# include "token.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>


// global variable
extern int g_global_exit;


typedef struct  s_tree
{
    int type;
}        t_tree;

typedef struct s_pipeline
{
    int type;
    t_tree *left;
    t_tree *right;

    
}t_pipeline;

typedef struct s_cmdline
{
    int type;
    t_token *cmd;
    t_token *redir;
}t_cmdline;

t_token *strtoken(char *str);
// t_token *newtoken(t_flgs type,char *tok,int hdoc,int expnd);
t_token *newtoken(t_flgs type, const char *tok, bool hdoc, bool expnd);
void add_token_back(t_token **lst, t_token *new);
t_token	*ft_lstlst(t_token *lst);



// built ins
typedef struct s_env
{
    char *var;
    char *val;
    char *prev;
    int exit_status;
    struct s_env *next;
    int print_err;
    int chdir_result;
}              t_env;

void pwd();
void cd(int args_count, char **args, t_env **env);
void	echo(int argc, char **argv);
void env_var(char **argv, t_env *env);
int unset(char *variable, t_env **env_list);
int export(char *variable, t_env **env);
void env(t_env *env);
void exit_built(int args_count, char **input);
t_env *find_env(t_env *env, char *name);
t_env *dup_env(char **env);
t_env *newvar(char **variable);
char **takevar(char *str);
void	add_var_back(t_env **lst, t_env *new);
t_env	*ft_lstlast(t_env *node);
void	built_ins(int argc, char **argv, t_env *envrm);
void check_oldpwd(t_env **env);
void	check_cd_dash(t_env **env);


// expander
void expander(t_token *token, t_env *env);
void execute_command(char *commands, char **args);

#endif