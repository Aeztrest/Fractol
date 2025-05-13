/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:03:38 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 05:05:19 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;
	char	*str;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	length = ft_strlen(s1) - i;
	while (s1[i] && ft_strchr(set, s1[i + length - 1]) != 0)
		length--;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + i, length + 1);
	return (str);
}
