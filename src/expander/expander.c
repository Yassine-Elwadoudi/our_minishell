/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:18:47 by yelwadou          #+#    #+#             */
/*   Updated: 2023/08/16 16:06:46 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// waits for the process to finish to get the last exit status 
// TODO: edit this after the execution is done THIS IS JUST A TEST
//  THIS IS ONLY FOR THE EXIT STATUS TO CHECK IF THE EXPANDER IS WORKING AS IT SHOULD
void execute_command(char *command, char **args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Child process
        execvp(command, args);
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
            {
                printf("The command '%s' failed with exit status %d\n", command, exit_status);
                g_global_exit = exit_status;
            }
        }
    }
}

void exit_expander(t_token *token)
{
    t_token *current = token;
    while (current)
    {
        if (current->type == ENV)
        {
            // if its $? only
            if (current->token[1] == '?' && current->token[2] == '\0')
            {
                free(current->token);
                char *exit_status_str = ft_itoa(g_global_exit);
                current->token = exit_status_str;
                printf("%s\n", current->token);
            }
            // if its followed by other chars before the space
            else if (current->token[1] == '?' && current->token[2] != '\0')
            {
                char *exit_status_str = ft_itoa(g_global_exit);
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
            exit_expander(token); // check if $? or just a env variable needs to be expanded
            char *env_name = &current->token[1];
            t_env *env_variable = find_env(env, env_name); // if not found do nothing
            if (env_variable && current->token[2] == '\0')
            {
                free(current->token);
                current->token = ft_strdup(env_variable->val);
                // printf("%s\n", current->token);
            }
        }
        current = current->next;
    }
}


