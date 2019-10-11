/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:17:39 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/10 15:56:57 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

static void		ft_print(t_block *block, char *str)
{
	ft_putstr("0x");
	ft_putstr(ft_custom_itoa_base(
		(unsigned long long)block + sizeof(t_block), 16, 'X', str));
	ft_putstr(" - 0x");
	ft_putstr(ft_custom_itoa_base(
		(unsigned long long)block + sizeof(t_block) + block->size,
			16, 'X', str));
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putendl(" octets");
}

static int		ft_print_mem(t_block *bloc, char *size)
{
	int			ret;
	char		str[64];

	ret = 0;
	ft_putstr(size);
	ft_putstr(" : 0x");
	if (bloc != NULL && bloc->free == 0)
	{
		ft_putendl(ft_custom_itoa_base((unsigned long long)bloc, 16, 'X', str));
	}
	else
		ft_putendl("0");
	while (bloc != NULL)
	{
		if (bloc->free == 0)
		{
			ft_print(bloc, str);
			ret += bloc->size;
		}
		bloc = bloc->next;
	}
	return (ret);
}

void			show_alloc_mem(void)
{
	int			total_mem;

	total_mem = ft_print_mem(g_manager.next_tiny, "TINY ");
	total_mem += ft_print_mem(g_manager.next_small, "SMALL");
	total_mem += ft_print_mem(g_manager.next_large, "LARGE");
	ft_putstr("Total : ");
	ft_putnbr(total_mem);
	ft_putendl(" octets");
}
