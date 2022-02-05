/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:44:37 by sumjang           #+#    #+#             */
/*   Updated: 2022/02/05 21:15:26 by sumjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*h;

	new->next = NULL;
	h->next = NULL;
	while (!lst->next)
	{
		new = malloc(size of(t_list));
		if (!new)
			(*del)(new);
		new->content = (*f)(lst->content);
		h->next = new;
		h = new;
		free(new);
	}
}
