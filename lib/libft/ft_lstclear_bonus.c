/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:54:15 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/29 11:08:11 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cup;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		cup = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cup;
	}
	*lst = 0;
}
