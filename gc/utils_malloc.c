/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:54:09 by asabri            #+#    #+#             */
/*   Updated: 2023/05/31 16:15:02 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_malloc.h"

t_malloc	*newmalloc(void *data)
{
	t_malloc	*n;

	n = malloc(sizeof(t_malloc));
	return (n->data = data, n->next = NULL, n);
}

void	addfront(t_malloc **head, t_malloc *new)
{
	if (*head)
		new->next = *head;
	*head = new;
}

void	listclear(t_malloc **head)
{
	t_malloc	*tmp;
	t_malloc	*ptr;

	if (!head)
		return ;
	tmp = *head;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr->data);
		free(ptr);
	}
	*head = NULL;
}
