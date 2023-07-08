/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:04:12 by asabri            #+#    #+#             */
/*   Updated: 2022/11/07 11:53:48 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	checkstr(unsigned int *end, unsigned int *start,
char const *s, char c)
{
	while (s[*start] == c && s[*start] != 0)
		*start += 1;
	*end = *start;
	while (s[*end] != c && s[*end] != 0)
		*end += 1;
}

static char	**free_(char **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static unsigned int	getnb(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	char			*r;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	p = malloc(sizeof(char *) * (getnb(s, c) + 1));
	if (!p)
		return (NULL);
	r = (char *)s;
	i = 0;
	while (i < getnb(s, c))
	{
		checkstr(&end, &start, r, c);
		p[i] = ft_substr(s, start, end - start);
		if (p[i] == NULL)
			return (free_(p));
		start = end;
		i++;
	}
	p[i] = 0;
	return (p);
}
