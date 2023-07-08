/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:28:19 by yelwadou          #+#    #+#             */
/*   Updated: 2023/07/08 13:32:27 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd()
{
	char	*current;

	current = getcwd(NULL, 0);
	if (current)
	{
		ft_putstr_fd(current, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}
