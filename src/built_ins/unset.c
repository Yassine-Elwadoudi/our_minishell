/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:24 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/16 11:08:34 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int unset(char *variable, t_env **env_list)
{
    t_env *env;
    t_env *prev;

    if (variable == NULL || variable[0] == '\0')
        return 0;
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
    return 1;
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
