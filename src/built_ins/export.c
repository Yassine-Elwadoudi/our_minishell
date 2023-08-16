/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:20 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/16 12:08:25 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: after tokenising test "string" and edit strtok
static void export_update(t_env **env, char *name, char *value)
{
    t_env *current = find_env(*env, name);
    char **var;

    if (current) 
    {
        free(current->val);
        current->val = ft_strdup(value);
    }
    else
    {
        var = malloc(sizeof(char *) * 2);
        var[0] = ft_strdup(name);
        var[1] = ft_strdup(value);
        add_var_back(env, newvar(var));
    }
}

int export(char *variable, t_env **env)
{
    char **var = takevar(variable);
    if (!check_identifier(variable))
    {
        if (var)
        {
            // printf("var is : %s\n", var[0]);
            // printf("val is : %s\n", var[1]);
            export_update(env, var[0], var[1]);
            free(var[0]);
            free(var[1]);
            free(var);
        }
        return (g_global_exit = 0, 0);
    }
    return (g_global_exit = 1, 0);
}
