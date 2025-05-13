/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:16:45 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 05:17:41 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*s;

	if (!lst || !n)
		return ;
	if (*lst == NULL)
		*lst = n;
	else
	{
		s = ft_lstlast(*lst);
		s->next = n;
	}
}
