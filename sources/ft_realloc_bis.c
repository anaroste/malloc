/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:04:34 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 11:54:41 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

size_t			find_size(void *src, t_block *tmp)
{
	size_t		ret;

	ret = 0;
	while (tmp != NULL && ret == 0)
	{
		if (tmp + 1 == src)
			ret = tmp->size;
		tmp = tmp->next;
	}
	return (ret);
}

void			*find_adress(void *ptr, size_t size, t_block *tmp)
{
	while (tmp != NULL)
	{
		if ((void *)tmp + SIZE_B == ptr)
		{
			if (tmp->next->free == 1 && tmp->next->size + tmp->size >= size)
				return (ft_extend(tmp, size));
		}
		tmp = tmp->next;
	}
	return (ft_combo_mmf(ptr, size));
}
