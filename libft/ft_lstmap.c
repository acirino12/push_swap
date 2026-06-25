/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acirino <acirino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:49:38 by acirino           #+#    #+#             */
/*   Updated: 2026/05/28 18:15:01 by acirino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	if (lst)
	{
		newlst = ft_lstnew((*f)(lst -> content));
		if (!newlst)
			return (NULL);
		lst = lst -> next;
	}
	while (lst)
	{
		node = ft_lstnew((*f)(lst -> content));
		if (!node)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst -> next;
	}
	return (newlst);
}
