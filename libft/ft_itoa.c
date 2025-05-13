/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakyurek <eakyurek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:07:40 by eakyurek          #+#    #+#             */
/*   Updated: 2024/11/05 05:08:10 by eakyurek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_str(char *c, unsigned int n, int len)
{
	while (n > 0)
	{
		c[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	char			*s;

	len = ft_len(n);
	s = (char *)malloc(len * sizeof(char) + 1);
	if (!s)
		return (0);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		num = n * -1;
		s[0] = '-';
	}
	else
		num = n;
	ft_str(s, num, len);
	return (s);
}
