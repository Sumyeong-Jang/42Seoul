/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:44:37 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/07 08:26:17 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*header;

	if (!f || !del)
		return (NULL);
	header = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (header)
			{
				new = header->next;
				(*del)(header->content);
				free(header);
				header = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&header, new);
		lst = lst->next;
	}
	return (header);
}
