/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:16:08 by asabri            #+#    #+#             */
/*   Updated: 2023/05/31 14:31:54 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env *dup_env(char **env)
{
    t_env *myenv;
    int i;
    
    i = -1;
    myenv = NULL;
    while(env[++i])
        add_var_back(&myenv, newvar(takevar(env[i])));
    return(myenv);                                                                     
}