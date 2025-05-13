/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:05:52 by eakyurek          #+#    #+#             */
/*   Updated: 2025/04/14 03:56:43 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	ft_wrd_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_res(char const *s, char c, int j, char **res)
{
	int	i;
	int	p;
	int	start;
	int	w;

	i = 0;
	w = 0;
	start = 0;
	while (i < j)
	{
		while (s[start] == c)
			start++;
		p = start;
		while (s[p] != c && s[p])
			p++;
		res[i] = ft_substr(s, start, (p - start));
		if (!res[i])
			return (ft_free(res));
		i++;
		start = p;
		w++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		j;

	if (!s)
		return (0);
	j = ft_wrd_count(s, c);
	res = (char **)malloc((sizeof(char *)) * (j + 1));
	if (!res)
		return (0);
	res = ft_res(s, c, j, res);
	return (res);
}
