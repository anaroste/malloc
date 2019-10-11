/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:34:10 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 15:21:17 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(unsigned long long nbr, int base)
{
	int		count;

	count = 0;
	while (nbr > 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

char			*ft_custom_itoa_base(unsigned long long nbr, int base,
					char c, char *str)
{
	int		count;
	char	*tab;

	count = ft_count(nbr, base);
	if (c == 'X')
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	str[count] = '\0';
	while (nbr != 0)
	{
		str[--count] = tab[(nbr % base)];
		nbr /= base;
	}
	return (str);
}
