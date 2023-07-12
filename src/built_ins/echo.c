/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:32:41 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/12 15:24:45 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int only_n(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != 'n')
            return (0);
        i++;
    }
    return (1);
}
// TODO: need to fix echo $? to print out the exit status
// TODO: $ should be handled in minishell and expand env var
void echo(int argc, char **argv)
{
    int i;
    int display_return;

    display_return = 1;
    i = 1;
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n'
		&& only_n(argv[1] + 2))
    {
        display_return = 0;
        i++;
    }
    while (i < argc)
    {
        ft_putstr_fd(argv[i], STDOUT_FILENO);
        if (i < argc - 1)
            ft_putstr_fd(" ", STDOUT_FILENO);
        i++;
    }
    if (display_return == 1)
        ft_putstr_fd("\n", STDOUT_FILENO);
}
