/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:24 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/16 13:14:04 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_identifier(char *identifier)
{
    int i = 0;
    
    while (identifier[i])
    {
        if (!((identifier[i] >= 'a' && identifier[i] <= 'z') ||
              (identifier[i] >= 'A' && identifier[i] <= 'Z') ||
              identifier[i] == '_'))
        {
            printf("'%s': not a valid identifier \n", identifier);
            return (g_global_exit = 1, 1);
        }
        i++;
    }
    return (g_global_exit = 0, 0);
}


int unset(char *variable, t_env **env_list)
{
    t_env *env;
    t_env *prev;

    if (variable == NULL || variable[0] == '\0')
        return (g_global_exit = 0, 0);
    if (!check_identifier(variable))
    {
        env = *env_list;
        while (env)
        {
            if (env->next && ft_strcmp(env->next->var, variable) == 0)
            {
                prev = env->next;
                env->next = prev->next;
                free(prev->var);
                free(prev->val);
                free(prev);
                return 0;
            }
            env = env->next;
        }
        return (g_global_exit = 0, 0);
    }
    return (g_global_exit = 1, 0);
}

/*
check if a variable is readonly
declare -p MYVAR
output : -r means read only
declare -r MYVAR="myvalue"
NOTE:
a read only VAR exist only for the duration
of the shell session in which they are created and they CANNOT be unset
until the process is finished
NOTE 2:
it will not be shown in env because env shows only the vars that are passed
to the child process
*/
// TODO: -----> doesnt need to be handled
/*
handle unseting read only var after finishing execution
*/
