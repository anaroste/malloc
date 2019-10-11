/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_good_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:04:06 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 14:06:49 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include "../libft/libft.h"

size_t			malloc_good_size(size_t size)
{
	return (align16(size));
}
