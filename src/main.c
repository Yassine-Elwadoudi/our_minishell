/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:45 by asabri            #+#    #+#             */
/*   Updated: 2023/08/13 12:01:46 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_global_exit = 0;

void	built_ins(int argc, char **argv, t_env *envrm)
{

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
	(void) envrm;
	int		args_count;
	char	**args;
    int i;

	token = strtoken(line);
	expander(token, envrm);
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
    // execute_command(args[0], args); //TODO: just testing the exit status (still need to be fixed)
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
