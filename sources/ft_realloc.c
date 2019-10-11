/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:06:32 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 11:52:22 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

void			*ft_extend(t_block *block, size_t size)
{
	t_block		*tmp;

	tmp = block->next->next;
	block->next = (void *)block + SIZE_B + size;
	block->next->free = 1;
	block->next->npage = 0;
	block->next->next = tmp;
	block->next->size = (block->size + block->next->size) - size;
	block->size = size;
	return ((void *)block + SIZE_B);
}

void			*ft_combo_mmf(void *src, size_t size)
{
	void		*dest;
	size_t		n;

	n = 0;
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
	n = find_size(src, g_manager.next_large);
	if (n == 0)
		n = find_size(src, g_manager.next_small);
	if (n == 0)
		n = find_size(src, g_manager.next_tiny);
	ft_memcpy(dest, src, n > size ? size : n);
	free(src);
	return (dest);
}

void			*ft_found_adress(void *ptr, size_t size)
{
	if (size > TINY_MAX)
		return (find_adress(ptr, size, g_manager.next_small));
	else
		return (find_adress(ptr, size, g_manager.next_tiny));
	return (NULL);
}

static int		be_or_not_to_be(void *ptr, size_t size)
{
	if (liste_check(ptr, g_manager.next_large, size, 2) == 0)
	{
		if (liste_check(ptr, g_manager.next_small, size, 2) == 0)
		{
			if (liste_check(ptr, g_manager.next_tiny, size, 2) == 0)
			{
				return (0);
			}
		}
	}
	return (1);
}

void			*realloc(void *ptr, size_t size)
{
	int		nb;

	nb = be_or_not_to_be(ptr, align16(size));
	if (ptr == NULL)
		return (malloc(size));
	if (nb == 0)
	{
		if (size == 0)
		{
			return (malloc(size));
		}
		return (NULL);
	}
	else if (nb == 2)
		return (ptr);
	if (align16(size) > SMALL_MAX)
		return (ft_combo_mmf(ptr, align16(size)));
	return (ft_found_adress(ptr, align16(size)));
}
