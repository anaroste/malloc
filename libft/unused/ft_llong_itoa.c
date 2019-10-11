/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llong_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:41:13 by anaroste          #+#    #+#             */
/*   Updated: 2018/02/25 13:00:13 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int		ft_count(long long n)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*ft_excep(long long n)
{
	if (n == LONG_MIN)
	{
		return (ft_strdup("-9223372036854775808"));
	}
	else
	{
		return (ft_strdup("0"));
	}
}

char			*ft_llong_itoa(long long n)
{
	char		*str;
	int			count;
	int			neg;

	neg = 0;
	if ((n == LONG_MIN) || (n == 0))
		return (ft_excep(n));
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	count = ft_count(n) + neg;
	if ((str = (char *)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	str[count--] = '\0';
	while (n > 0)
	{
		str[count--] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[count] = '-';
	return (str);
}
