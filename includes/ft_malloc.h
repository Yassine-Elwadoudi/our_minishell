/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <asabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:49:58 by asabri            #+#    #+#             */
/*   Updated: 2023/07/05 21:10:59 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include<stdlib.h>
# include "minishell.h"
typedef struct s_malloc
{
	void			*data;
	struct s_malloc	*next;
}				t_malloc;

t_malloc	*newmalloc(void *data);
void		addfront(t_malloc **head, t_malloc *new);
void		listclear(t_malloc **head);
void		*ft_malloc(size_t size, int mode);
#endif
