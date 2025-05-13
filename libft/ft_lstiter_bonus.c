/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:17:07 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 05:17:10 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*t;
	t_list	*p;

	if (!lst)
		return ;
	t = lst;
	while (t)
	{
		p = t->next;
		f(t->content);
		t = p;
	}
	lst = t;
}
