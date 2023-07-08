/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:51:26 by asabri            #+#    #+#             */
/*   Updated: 2022/11/01 10:14:37 by asabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	numofdigits(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	check_number(long *nb, int *sign, int *zero)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*sign = 1;
	}
	if (*nb == 0)
	{
		*zero = 1;
	}
}

static void	*check_str(char *str, int *count, int sign, int zero)
{
	if (zero == 1)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (sign == 1)
	{
		str[*count + 1] = '\0';
		str[0] = '-';
	}
	else
		str[*count] = '\0';
	return (str);
}

static void	*ft_set_str(char *str, int *count, int sign, long *nb)
{
	while (*nb != 0)
	{
		if (sign == 1)
		{
			str[*count] = '0' + *nb % 10;
			*nb /= 10;
			*count -= 1;
		}
		else
		{
			str[*count - 1] = '0' + *nb % 10;
			*nb /= 10;
			*count -= 1;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		count;
	int		zero;
	long	nb;

	nb = n;
	sign = 0;
	zero = 0;
	check_number(&nb, &sign, &zero);
	count = numofdigits(nb);
	str = (char *)malloc((count + 1 + sign + zero) * sizeof(char));
	if (!str)
		return (NULL);
	check_str(str, &count, sign, zero);
	return (ft_set_str(str, &count, sign, &nb));
}
