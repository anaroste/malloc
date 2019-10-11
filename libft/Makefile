
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaroste <anaroste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 08:57:31 by anaroste          #+#    #+#              #
#    Updated: 2019/09/20 11:17:04 by anaroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = 						\
	ft_putnbr.c				\
	ft_memcpy.c				\
	ft_putstr.c				\
	ft_putchar.c			\
	ft_putendl.c			\
	ft_custom_itoa_base.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME).a $(OBJ)
	@ranlib $(NAME).a
	@echo "Libft compiled"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME).a

re: fclean all

.PHONY: clean fclean re all
