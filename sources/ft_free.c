/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:04:45 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 15:56:53 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

static void		ft_defrag(t_block *block)
{
	// ft_putstr("A\n");
	if (block->next != NULL && block->next->free == 1 && block->next->npage == 0)
	{
	// ft_putstr("B\n");
		block->size += block->next->size + sizeof(t_block);
		block->next = block->next->next;
		if (block->next != NULL)
			block->next->prev = block;
	}
	// ft_putstr("C\n");
	// printf("block->prev = %p\n", block->prev);
	// if (block->prev != NULL && block->prev->free == 1 && block->npage == 0)
	// 	block = block->prev;
	// // ft_putstr("D\n");
	// if (block->next != NULL && block->next->free == 1
	// 	&& block->next->npage == 0)
	// {
	// // ft_putstr("E\n");
	// 	block->size += block->next->size + sizeof(t_block);
	// 	block->next = block->next->next;
	// 	if (block->next)
	// 		block->next->prev = block;
	// }
	// // ft_putstr("F\n");
}

int				liste_check(void *ptr, t_block *block, size_t size, int module)
{
	t_block		*tmp;

	tmp = block;
	while (tmp != NULL)
	{
		if ((void *)tmp + sizeof(t_block) == ptr)
		{
			if (module == 1)
			{
				tmp->free = 1;
				ft_defrag(tmp);
			}
			else
			{
				if (tmp->size == size)
				{
					return (2);
				}
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

size_t			align16(size_t x)
{
	if (x == 0)
		return (16);
	return ((x - 1) / 16 * 16 + 16);
}

static void		ft_free(void *ptr)
{
	if (ptr == NULL)
	{
		return ;
	}
	if (liste_check(ptr, g_manager.next_large, 0, 1) == 0)
		if (liste_check(ptr, g_manager.next_small, 0, 1) == 0)
			if (liste_check(ptr, g_manager.next_tiny, 0, 1) == 0)
			{
				return ;
			}
}

void			free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(ptr);
	pthread_mutex_unlock(&g_mutex);
}
