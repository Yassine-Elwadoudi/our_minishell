/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:45 by asabri            #+#    #+#             */
/*   Updated: 2023/07/13 23:06:58 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	built_ins(int argc, char **argv, t_env *envrm)
{
	// check_oldpwd(&envrm);
	if (ft_strcmp(argv[0], "env") == 0)
		env(envrm);
	if (ft_strcmp(argv[0], "unset") == 0 && argc > 1)
		unset(argv[1], &envrm);
	if (ft_strcmp(argv[0], "pwd") == 0)
		pwd();
	if (ft_strcmp(argv[0], "exit") == 0)
		exit_built(argc, argv);
	if (ft_strcmp(argv[0], "echo") == 0)
		echo(argc, argv);
	if (ft_strcmp(argv[0], "export") == 0)
		export(argv[1], &envrm);
	if (ft_strcmp(argv[0], "cd") == 0)
		cd(argc, argv, &envrm);
}

void	process_line(char *line, t_env *envrm)
{
	t_token	*token;
	t_token	*tmp;
	int		args_count;
	char	**args;
    int i;

	token = strtoken(line);
	args_count = 0;
    i = 0;
	tmp = token;
	while (tmp)
	{
		args_count++;
		tmp = tmp->next;
	}
	args = malloc(sizeof(char *) * args_count);
	while (i < args_count)
	{
		args[i] = token->token;
		token = token->next;
        i++;
	}
	built_ins(args_count, args, envrm);
	free(args);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*envrm;

	(void)ac;
	(void)av;
	(void)env;
	envrm = dup_env(env);
	check_oldpwd(&envrm);
	while (1)
	{
		line = readline("\E[31;1mminishell-$  \033[0m");
		process_line(line, envrm);
		add_history(line);
	}
	return (0);
}
