/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:20:01 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/29 10:32:59 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		sz_s;
	char	*d_s;

	i = 0;
	if (!s || !f)
		return (NULL);
	sz_s = ft_strlen(s);
	d_s = (char *)malloc((sz_s + 1) * sizeof(char));
	if (!d_s)
		return (NULL);
	while (*(s + i))
	{
		*(d_s + i) = f(i, *(s + i));
		i++;
	}
	*(d_s + i) = '\0';
	return (d_s);
}
