/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 04:15:45 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 04:56:32 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	p;
	char	*str;

	p = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((i + j) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	while (s2[p])
	{
		str[i] = s2[p];
		i++;
		p++;
	}
	str[i] = '\0';
	return (str);
}
