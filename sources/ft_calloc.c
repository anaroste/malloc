/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:36:54 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 15:42:48 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

static void		*ft_calloc(size_t nmemb, size_t size)
{
	void		*ret;

	ret = malloc(nmemb * size);
	ft_memset(ret, 0, align16(nmemb * size));
	return (ret);
}

void			*calloc(size_t nmemb, size_t size)
{
	void		*ret;

	pthread_mutex_lock(&g_mutex);
	ret = ft_calloc(nmemb, size);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
