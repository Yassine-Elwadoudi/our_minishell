/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:30 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/13 16:00:45 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	update_env(t_env **env, const char *pwd, const char *oldpwd)
{
	t_env	*pwd_var;
	t_env	*oldpwd_var;

	if (oldpwd == NULL)
		return ;
	pwd_var = find_env(*env, "PWD");
	if (pwd_var)
	{
		free(pwd_var->val);
		pwd_var->val = ft_strdup(pwd);
	}
	oldpwd_var = find_env(*env, "OLDPWD");
	if (oldpwd_var)
	{
		free(oldpwd_var->val);
		oldpwd_var->val = ft_strdup(oldpwd);
	}
}

void	check_oldpwd(t_env **env)
{
	t_env	*oldpwd;
	char	**new_old;

	oldpwd = find_env(*env, "OLDPWD");
	if (oldpwd)
	{
		free(oldpwd->val);
		oldpwd->val = ft_strdup("");
	}
	else if (!oldpwd)
	{
		new_old = malloc(sizeof(char *) * 2);
		new_old[0] = ft_strdup("OLDPWD");
		new_old[1] = ft_strdup("");
		add_var_back(env, newvar(new_old));
	}
}

// void	cd(int args_count, char **args, t_env **env)
// {
// 	char	*new_pwd;
// 	char	*home;
// 	char	*old;
// 	t_env	*prev_dir_node;

// 	home = getenv("HOME");
// 	old = getcwd(NULL, 0);
// 	(*env)->print_err = 0;
// 	(*env)->chdir_result = -1;
// 	if (args_count == 1 || (args_count == 2 && args[1][0] == '~')
// 		|| (args[1][0] == '-' && args[1][1] == '-' && args[1][2] == '\0'))
// 		(*env)->chdir_result =  chdir(home);
// 	else if (args_count == 2 && args[1][0] == '-' && args[1][1] != '\0')
// 	{
// 		printf("cd: -%c: invalid option\n", args[1][1]);
// 		(*env)->print_err = 1;
// 	}
// 	else if (args_count == 2 && args[1][0] == '-' && args[1][1] == '\0')
// 	{
// 		prev_dir_node = find_env(*env, "OLDPWD");
// 		if (prev_dir_node->val && prev_dir_node->val[0] != '\0')
// 		{
// 			(*env)->chdir_result =  chdir(prev_dir_node->val);
// 			pwd();
// 		}
// 		else
// 		{
// 			printf("cd : OLDPWD not set\n");
// 			(*env)->print_err = 1;
// 		}
// 	}
// 	else if (args_count == 2)
// 		(*env)->chdir_result =  chdir(args[1]);
// 	else if (args_count > 2)
// 	{
// 		printf("cd: too many arguments\n");
// 		(*env)->print_err = 1;
// 	}
// 	new_pwd = getcwd(NULL, 0);
// 	if (!new_pwd)
// 	{
// 		printf("cd: error retrieving current directory: getcwd:
//  cannot access parent directories: No such file or directory\n");
// 		(*env)->print_err = 1;
// 	}
// 	else if (errno != 0 && (*env)->print_err == 0 && (*env)->chdir_result == -1)
// 		perror("cd");
// 	else if ((*env)->print_err == 0)
// 		update_env(env, new_pwd, old);
// 	free(old);
// }

void	change_dir(char **args, t_env **env, int args_count)
{
	check_home(env);
	t_env *home = find_env(*env, "HOME");
	(*env)->print_err = 0;
	(*env)->chdir_result = -1;
	if (args_count == 1 || (args_count == 2 && args[1][0] == '~')
		|| (args[1][0] == '-' && args[1][1] == '-' && args[1][2] == '\0'))
		(*env)->chdir_result = chdir(home->val);
	else if (args_count == 2 && args[1][0] == '-' && args[1][1] == '\0')
		check_cd_dash(env);
	else if (args_count == 2 && args[1][0] == '-' && args[1][1] != '\0')
	{
		printf("cd: -%c: invalid option\n", args[1][1]);
		(*env)->print_err = 1;
	}
	else if (args_count == 2)
		(*env)->chdir_result = chdir(args[1]);
	else if (args_count > 2)
	{
		printf("cd: too many arguments\n");
		(*env)->print_err = 1;
	}
}

void check_home(t_env **env)
{
	t_env	*home;

	home = find_env(*env, "HOME");
	if (home)
			chdir(home->val);
	else
		printf("HOME not set\n");
}

void	check_cd_dash(t_env **env)
{
	t_env *prev_dir_node;
		prev_dir_node = find_env(*env, "OLDPWD");
		if (prev_dir_node->val && prev_dir_node->val[0] != '\0')
		{
			(*env)->chdir_result = chdir(prev_dir_node->val);
			pwd();
		}
		else
		{
			printf("cd : OLDPWD not set\n");
			(*env)->print_err = 1;
		}

}

void	cd(int args_count, char **args, t_env **env)
{
	char *new_pwd;
	char *old;

	old = getcwd(NULL, 0);
	change_dir(args, env, args_count);
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
	{
		printf("cd: error retrieving current directory: getcwd:\
 cannot access parent directories: No such file or directory\n");
	}
	else if (errno != 0 && (*env)->print_err == 0 && (*env)->chdir_result == -1)
		perror("cd");
	else if ((*env)->print_err == 0)
	update_env(env, new_pwd, old);
	free(old);
}
