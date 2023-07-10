/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:30 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/10 23:43:44 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void update_env(t_env **env, const char *pwd, const char *oldpwd)
{
    if (oldpwd == NULL)
        return;
    t_env *pwd_var = find_env(*env, "PWD");
    if (pwd_var)
    {
        free(pwd_var->val);
        pwd_var->val = ft_strdup(pwd);
    }
    t_env *oldpwd_var = find_env(*env, "OLDPWD");
    if (oldpwd_var)
    {
        free(oldpwd_var->val);
        oldpwd_var->val = ft_strdup(oldpwd);
    }
}

void check_oldpwd(t_env **env)
{
    t_env *oldpwd = find_env(*env, "OLDPWD");
    char *old = getcwd(NULL, 0);
    char **new_old;
    if (oldpwd)
    {
        free(oldpwd->val);
        oldpwd->val = ft_strdup(old);
    }
    else if (!oldpwd)
    {
        new_old = malloc(sizeof(char *) * 2);
        new_old[0] = ft_strdup("OLDPWD");
        new_old[1] = ft_strdup("");
        add_var_back(env, newvar(new_old));
    }
    free(old);
}


void cd(int args_count, char **args, t_env **env)
{
    char *new_pwd;
    char *home;
    int chdir_result = -1;
    
    home = getenv("HOME");
    char *old = getcwd(NULL, 0);
    if (args_count == 1 || (args_count == 2 && args[1][0] == '~'))
        chdir_result = chdir(home);
    else if (args_count == 2 && args[1][0] == '-')
    {
        t_env *prev_dir_node = find_env(*env, "OLDPWD");
        if (prev_dir_node->val && prev_dir_node->val[0] != '\0')
            chdir_result = chdir(prev_dir_node->val);
        else if (!prev_dir_node->val || prev_dir_node->val[0] == '\0')
            printf("cd : OLDPWD not set\n");
    }
    else if (args_count == 2)
        chdir_result = chdir(args[1]);
    else if (args_count > 2)
        printf("cd: too many arguments\n");
    new_pwd = getcwd(NULL, 0);
    if (!new_pwd)
        printf("cd: error retrieving current directory: getcwd:\
 cannot access parent directories: No such file or directory\n");
    else if (chdir_result == -1)
        perror("cd");
    update_env(env, new_pwd, old);
    free(old);
}

