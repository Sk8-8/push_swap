# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 17:19:01 by kguillem          #+#    #+#              #
#    Updated: 2025/05/03 19:12:06 by kguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c list.c rank.c utils.c moves.c lownumsort.c

OBJS = ${SRC:.c=.o}

%.o: %.c
		$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

NAME = push_swap

CC = gcc

CCFLAGS =  -ggdb -Wall -Werror -Wextra

INC_DIR = .

CPPFLAGS = -I $(INC_DIR) -I ft_printf -I ft_printf/libft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@make -C ft_printf
		$(CC) $(CCFLAGS) -g $(OBJS) ft_printf/libftprintf.a ft_printf/libft/libft.a -o push_swap

clean:
		$(RM) $(OBJS)
		@make -C ft_printf clean

fclean: clean
		$(RM) push_swap
		@make -C ft_printf fclean
re: fclean all

.PHONY: all clean fclean re
