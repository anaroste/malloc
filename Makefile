ifeq ($(HOSTTYPE),)
   HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

LIBFT = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror -fPIC

HEADERS =	-I ./includes/ft_malloc.h

LINK =		libft_malloc.so

SRC_NAME =	ft_malloc.c				\
			ft_realloc.c			\
			ft_calloc.c				\
			ft_realloc_bis.c		\
			ft_free.c				\
			show_alloc_mem.c		\
			ft_malloc_good_size.c	\
			ft_malloc_size.c		\
			ft_reallocf.c			\

SRC = $(addprefix sources/, $(SRC_NAME))

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C $(LIBFT)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(HEADERS)  -L./libft -lft -shared -o $(NAME)
	@/bin/rm -f $(LINK)
	@ln -fs $(NAME) $(LINK)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFT)
	@/bin/rm -f $(OBJ)
	@echo "$(NAME) objects have been deleted"

fclean : clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LINK)
	@echo "$(NAME) have been deleted"

re : fclean all

.PHONY : all clean fclean re libft