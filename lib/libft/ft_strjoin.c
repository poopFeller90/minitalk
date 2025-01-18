/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:08:26 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/29 10:27:20 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_s;
	int		sum_size;

	if (!s1 || !s2)
		return (NULL);
	sum_size = ft_strlen(s1) + ft_strlen(s2);
	ret_s = (char *)malloc((sum_size + 1) * sizeof(char));
	if (ret_s == NULL)
		return (NULL);
	while (*s1)
		*ret_s++ = *s1++;
	while (*s2)
		*ret_s++ = *s2++;
	*ret_s = '\0';
	return (ret_s - sum_size);
}
