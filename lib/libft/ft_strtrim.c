/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:10:28 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/29 10:28:09 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iscs(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		i;
	int		j;
	int		size_s1;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1);
	size_s1 = j;
	while (ft_iscs(*(s1 + i), set))
		i++;
	j--;
	while (ft_iscs(*(s1 + j), set))
		j--;
	if (i > j)
	{
		return (ft_strdup(""));
	}
	copy = (char *)malloc((j - i + 2) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, (s1 + i), (j - i + 2));
	return (copy);
}
