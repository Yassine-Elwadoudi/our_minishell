/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:20 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/08 13:34:34 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: after tokenising test "string" and edit strtok
int export(char *variable, t_env **env)
{
    t_env *current;

    char *name = strtok(variable, "=");
    char *value = strtok(NULL, "=");
    if (name && value)
    {
        current = find_env(*env, name);
        if (current)
        {
            // if it exits we over write its value
            free(current->val);
            current->val = ft_strdup(value);
        } 
        // we add it if it doesnt exist
        else 
        {
            char **var = malloc(sizeof(char *) * 2);
            var[0] = ft_strdup(name);
            var[1] = ft_strdup(value);
            add_var_back(env, newvar(var));
        }
    }
    return 0;
}
