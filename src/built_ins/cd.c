/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:30 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/10 01:28:57 by yelwadou         ###   ########.fr       */
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
    
    home = getenv("HOME");
    check_oldpwd(env); // Call check_oldpwd before changing directories
    char *old = getcwd(NULL, 0);
    if (args_count == 1 || args[1][0] == '~')
        chdir(home);
    else if (args_count == 2 && args[1][0] == '-')
    {
        if (old == NULL)
            printf("old pwd not set");
        else
        {
            char *prev_dir = find_env(*env, "OLDPWD")->val; // Get the previous directory from the environment
            if (prev_dir)
                chdir(prev_dir); // Change to the previous directory
        }
    }
    else if (args_count == 2)
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
            return;
        }
    }
    else if (args_count > 2)
        ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);

    new_pwd = getcwd(NULL, 0);
    if (!new_pwd)
        printf("cd: error retrieving current directory: getcwd: cannot\
        access parent directories: No such file or directory\n");

    update_env(env, new_pwd, old);
}
