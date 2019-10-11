/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:36:10 by anaroste          #+#    #+#             */
/*   Updated: 2018/01/25 17:29:30 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(s1);
	if ((str = (char*)malloc(sizeof(*str) * (size + 1))) == NULL)
		return (NULL);
	while (++i < size)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
