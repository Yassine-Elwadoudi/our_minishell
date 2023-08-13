/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:11 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/13 12:02:05 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void env(t_env *env)
{
    if(!env)
        return ;
    while (env)
    {
        // ft_putstr_fd(env->var, STDOUT_FILENO);
        // ft_putstr_fd("=", STDOUT_FILENO);
        // ft_putstr_fd(env->val, STDOUT_FILENO);
        // ft_putstr_fd("\n", STDOUT_FILENO);
        printf("%s=%s\n", env->var, env->val);
        env = env->next;
    }
}
//  TODO:need to make sure if it should be printed in stdout_fileno