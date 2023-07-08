/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:30 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/08 13:34:57 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


static void update_env(t_env **env, const char *pwd, const char *oldpwd)
{
    if (oldpwd == NULL)
        return;
    if (pwd == NULL)
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

void cd(int args_count, char **args, t_env **env)
{
    char *old_pwd;
    char *new_pwd;
    char *home;

    old_pwd = getcwd(NULL, 0);
    if (old_pwd == NULL)
        printf("cd: error retrieving current directory: getcwd:\
            cannot access parent directories: No such file or directory\n");
    home = getenv("HOME");
    char *old = getenv("OLDPWD");
    if (args_count == 1 || args[1][0] == '~')
        chdir(home);
    if (args_count == 2 && args[1][0] == '-')
        chdir(old);
    //  returns 0 if the change is done succefully 
    // returns -1 if the change failed
    else if (args_count == 2)
    {
        if (chdir(args[1]) == -1)
        {
            perror("cd");
            return ;
        }
    }
    // perror Print a message describing the meaning of the value of errno
    else if (args_count > 2)
        ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
    new_pwd = getcwd(NULL, 0);
    // if (new_pwd == NULL)    
    //     perror("cd");
    update_env(env, new_pwd, old_pwd);
}
