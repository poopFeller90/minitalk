/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:17:23 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/26 18:24:36 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countlen(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_fillarr(char *index, int n)
{
	if (n <= 9)
		*index = n + 48;
	else
	{
		*index = n % 10 + 48;
		ft_fillarr(index - 1, n / 10);
	}
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_countlen(n);
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
		len++;
	}
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	ft_fillarr(arr + len - 1, n);
	if (neg)
		*arr = '-';
	*(arr + len) = '\0';
	return (arr);
}
