/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:04:45 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 11:02:26 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

// static void     ft_defrag(t_block *block, t_block *firstone)
// {
//     if (block->prev != NULL && block->prev->free == 1)
//         block = block->prev;
//     if (block->next->next != NULL && block->next->next->free == 1)
//     {
//         block->size += block->next->size + block->next->next->size + sizeof(t_block) * 2;
//         block->next = //voila c'est de la merde
//     }
//     else
//     {
//         block->size += block->next->size + sizeof(t_block);
//     }
//     if (block->npage == 1 && (block->size == (tiny_max * 100 + sizeof(t_block) * 99) || block->size == (small_max * 100 + sizeof(t_block) * 99)))
//     {
//         munmap(block, tiny_max * 100 + sizeof(t_block) * 101);
//     }
// }

int		liste_check(void *ptr, t_block *block, size_t size, int module)
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
				// ft_defrag(tmp, block);
			}
			else
				if (tmp->size == size)
				{
					return (2);
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

void			free(void *ptr)
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
