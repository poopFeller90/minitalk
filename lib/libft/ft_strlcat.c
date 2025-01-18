/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:39:59 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/25 16:22:38 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	sum_len;
	size_t	dest_len;
	size_t	src_len;
	size_t	copy_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	sum_len = dest_len + src_len;
	if (n <= ft_strlen(dest))
		return (n + src_len);
	copy_len = n - dest_len - 1;
	dest += dest_len;
	while (*src && copy_len)
	{
		*dest++ = *src++;
		copy_len--;
	}
	*dest = '\0';
	return (sum_len);
}
