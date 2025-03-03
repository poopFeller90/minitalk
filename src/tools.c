/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:01:59 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/28 16:02:01 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	*ft_memset(void *p, int c, size_t len)
{
	while (len--)
		*(unsigned char *)(p + len) = (unsigned char)c;
	return (p);
}
