/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:42:34 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/25 20:14:28 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	sz_little;

	i = 0;
	sz_little = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (big[i] && (i + sz_little) <= n)
	{
		if (big[i] == *little && !ft_strncmp(big + i, little, sz_little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
