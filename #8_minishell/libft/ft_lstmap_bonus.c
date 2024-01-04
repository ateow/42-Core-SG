/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:39:55 by cooi              #+#    #+#             */
/*   Updated: 2023/09/10 20:54:05 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*addnode(t_list *node, void *(*f)(void *), void (*del)(void *))
{
	void	*contents;
	t_list	*nnode;

	contents = f(node->content);
	if (!contents)
		return (NULL);
	nnode = ft_lstnew(contents);
	if (!nnode)
	{
		del(contents);
		return (NULL);
	}
	return (nnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*nnode;

	if (!lst || !f || !del)
		return (NULL);
	nlist = NULL;
	while (lst != NULL)
	{
		nnode = addnode(lst, f, del);
		if (!nnode)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, nnode);
		lst = lst->next;
	}
	return (nlist);
}
