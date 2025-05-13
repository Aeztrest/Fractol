/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:19:55 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 05:19:57 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*p;

	if (!f || !lst)
		return (NULL);
	t = NULL;
	while (lst)
	{
		p = ft_lstnew((*f)(lst->content));
		if (!p)
		{
			ft_lstclear(&p, del);
			free(p);
			return (NULL);
		}
		ft_lstadd_back(&t, p);
		lst = lst->next;
	}
	return (t);
}
