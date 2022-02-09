/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <sumjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:44:37 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/10 06:28:48 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*header;

	if (!lst || !f)
		return (NULL);
	header = ft_lstnew(f(lst->content));
	if (!header)
		return (NULL);
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
	return (header);
}
