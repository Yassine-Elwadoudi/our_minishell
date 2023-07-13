/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:33:15 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/13 23:09:06 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int check_exit(char *input)
{
    size_t i;

    i = 0;
    if (input == NULL)
        return 0;
    while (input[i])
    {
        if (!ft_isdigit(input[i]))
            return 1;
        i++;
    }
    return 0;
}
void exit_built(int args_count, char **input)
{
    int non_number = 0;
    int i = 1;
    if (args_count == 1)
        exit(0);
    while (i < args_count)
    {
        if (check_exit(input[i]))
            non_number = 1;
        i++;
    }
    if (args_count == 2 && input[1] != NULL && non_number)
    {
        ft_putstr_fd("exit: ", STDERR_FILENO);
        ft_putstr_fd(input[1], STDERR_FILENO);
        ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
        exit(2);
    }
    else if (args_count > 2 && !non_number)
        ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
    else if (args_count > 2 && !check_exit(input[1]) && non_number)
    {
        ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
        exit(2);
    }
    else if (args_count > 2 && non_number)
    {
        ft_putstr_fd("exit: ", STDERR_FILENO);
        ft_putstr_fd(input[1], STDERR_FILENO);
        ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
        exit(2);
    }
    else
    {
        int exit_code = ft_atoi(input[1]);
        exit(exit_code);
    }
}
