/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:30:57 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/27 13:05:44 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	i = 0;
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest == p_src)
		return (dest);
	if (p_src < p_dest)
	{
		while (n)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	else if (p_src > p_dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
