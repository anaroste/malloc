/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:22 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 12:29:32 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b2;
	size_t	i;

	b2 = b;
	i = 0;
	while (i < len)
	{
		b2[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
