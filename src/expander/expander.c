/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:18:47 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/16 01:15:23 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void exit_status()
{
    pid_t pid = fork();

        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            g_global_exit = exit_status;
        }
}

void exit_expander(t_token *token)
{
    t_token *current = token;
    while (current)
    {
        if (current->type == ENV)
        {
            if (current->token[1] == '?' && current->token[2] == '\0')
            {
                free(current->token);
                char *exit_status_str = ft_itoa(g_global_exit); // Use the global variable to expand the $? variable
                current->token = exit_status_str;
                printf("%s\n", current->token);
            }
            else if (current->token[1] == '?' && current->token[2] != '\0')
            {
                char *exit_status_str = ft_itoa(g_global_exit); // Use the global variable to expand the $? variable
                char *expanded_token = ft_strjoin(exit_status_str, &current->token[2]);
                free(current->token);
                current->token = expanded_token;
                printf("%s\n", current->token);
                free(exit_status_str);
            }
        }
        current = current->next;
    }
}

// pointer to the linked list for help iterating around the tokens and keeping track
// of what tokens have been passed
void expander(t_token *token, t_env *env)
{
    t_token *current = token;
    // printf("in");
    while (current)
    {
        if (current->type == ENV)
        {
            exit_expander(token);
            char *env_name = &current->token[1];
            t_env *env_variable = find_env(env, env_name);
            if (env_variable)
            {
                free(current->token);
                current->token = ft_strdup(env_variable->val);
                printf("%s\n", current->token);
            }
        }
        current = current->next;
    }
}
