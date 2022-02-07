/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:44:37 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 08:47:25 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*header;

	if (!lst)
		return (NULL);
	header = ft_lstnew(f(lst->content));
	if (!header)
		return (header);
	new = header;
	while (lst->next)
	{
		new->next = ft_lstnew(f(lst->next->content));
		if (!new->next)
		{
			ft_lstclear(&header, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (headder);
}
