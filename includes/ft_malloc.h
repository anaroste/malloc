/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:48:18 by anaroste          #+#    #+#             */
/*   Updated: 2019/10/11 15:42:40 by anaroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define TINY_MAX 1024
# define SMALL_MAX 1024 * 128
# define SIZE_B sizeof(t_block)

typedef struct			s_block
{
	struct s_block		*next;
	int					npage;
	int					free;
	struct s_block		*prev;
	size_t				size;
}						t_block;

typedef struct			s_manager
{
	t_block				*next_tiny;
	t_block				*next_small;
	t_block				*next_large;
}						t_manager;

t_manager				g_manager;
static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void					*malloc(size_t size);
void					free(void *ptr);
void					show_alloc_mem();
void					*realloc(void *ptr, size_t size);
size_t					align16(size_t x);
int						liste_check(void *ptr, t_block *block, size_t size
							, int module);
size_t					find_size(void *src, t_block *tmp);
void					*find_adress(void *ptr, size_t size, t_block *tmp);
void					*ft_extend(t_block *block, size_t size);
void					*ft_combo_mmf(void *src, size_t size);
void					*calloc(size_t nmemb, size_t size);
size_t					malloc_good_size(size_t size);
size_t					malloc_size(void *ptr);
void					*reallocf(void *ptr, size_t size);

#endif
