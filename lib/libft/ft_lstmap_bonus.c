/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:31:28 by yhajbi            #+#    #+#             */
/*   Updated: 2024/10/31 13:01:24 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*p_lst;
	t_list	*p_new;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	p_lst = lst;
	p_new = ft_lstnew((f)(p_lst->content));
	head = p_new;
	p_lst = p_lst->next;
	while (p_lst)
	{
		p_new->next = ft_lstnew((f)(p_lst->content));
		if (p_new == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		p_new = p_new->next;
		p_lst = p_lst->next;
	}
	return (head);
}
