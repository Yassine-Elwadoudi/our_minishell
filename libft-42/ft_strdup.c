/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelwadou <yelwadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 03:30:08 by asabri            #+#    #+#             */
/*   Updated: 2023/07/09 12:42:45 by yelwadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;

	if (s1 == NULL)
		return NULL;
	len = 0;
	while (s1[len])
		len++;
	p = ft_malloc((sizeof(char) * (len + 1)), 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (len >= 0)
	{
		p[len] = s1[len];
		len--;
	}
	return (p);
}
