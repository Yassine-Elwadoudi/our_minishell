/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:11 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/16 14:07:35 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void env(t_env *env)
{
    if(!env)
        return ;
    while (env)
    {
        printf("%s=%s\n", env->var, env->val);
        env = env->next;
    }
    g_global_exit = 0;
}
//  TODO:need to make sure if it should be printed in stdout_fileno