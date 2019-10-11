/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:17:16 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 14:20:18 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

void			*reallocf(void *ptr, size_t size)
{
	t_block		*ret;

	ret = realloc(ptr, size);
	if (!ret)
		free(ptr);
	return (ret);
}