/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:27:09 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 10:05:49 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

int				ft_new_page(int size_max, t_block **block, int nbr)
{
	t_block		*new_page;
	t_block		*tmp;

	new_page = mmap(NULL, (size_max + SIZE_B) * nbr + SIZE_B,
				PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (new_page == MAP_FAILED)
		return (0);
	new_page->size = (size_max + SIZE_B) * nbr;
	new_page->free = 1;
	new_page->npage = 1;
	new_page->next = NULL;
	new_page->prev = NULL;
	if (*block == NULL)
		*block = new_page;
	else
	{
		tmp = *block;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_page;
	}
	return (1);
}

void			*ft_new_block(t_block *block, int size, size_t size_max)
{
	t_block		*new_block;
	t_block		*tmp;
	int			nsize;

	tmp = block;
	while (tmp->next != NULL && (tmp->free == 0 || tmp->size < (size + SIZE_B)))
		tmp = tmp->next;
	if (tmp->next == NULL && tmp->size < (size + SIZE_B))
	{
		if (ft_new_page(size_max, &block, 100) == 0)
			return (NULL);
		while (tmp->free == 0 || tmp->size < (size + SIZE_B))
			tmp = tmp->next;
	}
	new_block = (void *)tmp + SIZE_B + size;
	nsize = size_max > SMALL_MAX ? 0 : tmp->size - (size + SIZE_B);
	new_block->size = nsize;
	new_block->free = 1;
	new_block->npage = 0;
	new_block->next = NULL;
	new_block->prev = tmp;
	tmp->size = size;
	tmp->free = 0;
	tmp->next = new_block;
	return ((void *)tmp + SIZE_B);
}

void			*malloc(size_t size)
{
	t_block		*ret;

	size = align16(size);
	if (size <= TINY_MAX)
	{
		if (g_manager.next_tiny == NULL)
			if (ft_new_page(TINY_MAX, &g_manager.next_tiny, 100) == 0)
				return (NULL);
		ret = ft_new_block(g_manager.next_tiny, size, TINY_MAX);
	}
	else if (size <= SMALL_MAX)
	{
		if (g_manager.next_small == NULL)
			if (ft_new_page(SMALL_MAX, &g_manager.next_small, 100) == 0)
				return (NULL);
		ret = ft_new_block(g_manager.next_small, size, SMALL_MAX);
	}
	else
	{
		if (g_manager.next_large == NULL)
			if (ft_new_page(size, &g_manager.next_large, 1) == 0)
				return (NULL);
		ret = ft_new_block(g_manager.next_large, size, size);
	}
	return (ret);
}
