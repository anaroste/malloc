/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:00:59 by anaroste          #+#    #+#             */
/*   Updated: 2018/03/03 17:26:21 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
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

static char		*ft_excep(int n)
{
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	else
	{
		return (ft_strdup("0"));
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		neg;

	neg = 0;
	if ((n == -2147483648) || (n == 0))
	{
		return (ft_excep(n));
	}
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
