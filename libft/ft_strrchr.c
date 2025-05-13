/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:47:51 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 19:21:57 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	i = 0;
	a = (unsigned char) c;
	while (*(s + i))
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] != a)
		{
			i--;
		}
		else
		{
			return ((char *)s + i);
		}
	}
	return (0);
}
