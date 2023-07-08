/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:57:48 by asabri            #+#    #+#             */
/*   Updated: 2022/11/04 12:18:30 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;
	size_t	lenght;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	lenght = lendst;
	i = 0;
	if (!dst || dstsize == 0)
		return (lensrc);
	if (dstsize < lendst)
		return (lensrc + dstsize);
	while (src[i] && (dstsize - 1) > lendst + i)
		dst[lenght++] = src[i++];
	dst[lenght] = '\0';
	return (lensrc + lendst);
}
