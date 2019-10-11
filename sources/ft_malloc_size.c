/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:06:30 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 14:25:37 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

size_t			malloc_size(void *ptr)
{
	size_t		ret;

	ret = 0;
	ret = find_size(ptr, g_manager.next_large);
	if (ret == 0)
		ret = find_size(ptr, g_manager.next_small);
	if (ret == 0)
		ret = find_size(ptr, g_manager.next_tiny);
	return (ret);
}
