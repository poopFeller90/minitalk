/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:42:59 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/30 15:26:10 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *start, int sz, int sign)
{
	while (*start == 48)
	{
		start++;
		sz--;
	}
	if (sz > 19)
		return (0);
	if (sz < 19)
		return (1);
	if (ft_strncmp(start, "9223372036854775807", sz) > 0 && sign)
		return (0);
	if (ft_strncmp(start, "9223372036854775808", sz) > 0 && sign == -1)
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	long long	num;
	int			sign;
	const char	*start;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign = -1;
	}
	start = nptr;
	while (*nptr >= '0' && *nptr <= '9')
		num = num * 10 + (*nptr++ - '0');
	if (!ft_check(start, nptr - start, sign))
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return ((int)(sign * num));
}
