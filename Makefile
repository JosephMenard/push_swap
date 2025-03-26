# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 14:18:01 by jmenard           #+#    #+#              #
#    Updated: 2024/09/25 16:27:09 by jmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDES = push_swap.h

SRC = instructions.c instruction_bis.c verifs_create.c mediane.c cost.c sort.c\
main.c mediane_bis.c put_top.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
	
all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

libft_clean:
	$(MAKE) clean -C ./libft
	
libft_fclean:
	$(MAKE) fclean -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean: libft_clean
	rm -f $(OBJ)

fclean: libft_fclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re LIBFT libft_clean libft_fclean