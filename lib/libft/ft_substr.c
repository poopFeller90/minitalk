/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:07:42 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/29 10:23:37 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t p, size_t q)
{
	if (p < q)
		return (p);
	return (q);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret_s;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ret_s = (char *)malloc(sizeof(char));
		if (!ret_s)
			return (NULL);
		ret_s[0] = '\0';
		return (ret_s);
	}
	ret_s = (char *)malloc((min(len, ft_strlen(s) - start) + 1) * sizeof(char));
	if (!ret_s)
		return (NULL);
	while (i < len && *(s + start + i))
	{
		*(ret_s + i) = *(s + start + i);
		i++;
	}
	*(ret_s + i) = '\0';
	return (ret_s);
}
