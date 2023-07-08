/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:30:53 by asabri            #+#    #+#             */
/*   Updated: 2023/07/08 19:21:43 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*ft_lstlast(t_env *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->next == NULL)
			return (node);
		node = node ->next;
	}
	return (node);
}

void	add_var_back(t_env **lst, t_env *new)
{
	t_env	*ptr;

	ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*(lst));
		ptr->next = new;
	}
}

char **takevar(char *str)
{
    char **var;
    int i;
    int j;

    var = malloc(sizeof(char *) * 2);
    i = 0;
    j = -1;
    while (str[++j]);
    while (str[i] != '=' && str[i] != '\0')
        i++;

    var[0] = ft_substr(str,0,i);
    var[1] = ft_substr(str,i + 1,j);
    return(var);
}

t_env *newvar(char **variable)
{
    t_env *node;

    node = malloc(sizeof(t_env));
    node->var = variable[0];
    node->val = variable[1];
    node->next = NULL;
    return (node);
}

t_env *find_env(t_env *env, char *name)
{
    while (env != NULL)
    {
        if (ft_strcmp(env->var, name) == 0)
            return env;
        env = env->next;
    }
    return NULL;
}
