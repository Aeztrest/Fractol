/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:16:55 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 05:17:48 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*p;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		p = t->next;
		ft_lstdelone(t, del);
		t = p;
	}
	*lst = NULL;
}
