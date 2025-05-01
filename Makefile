# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 17:19:01 by kguillem          #+#    #+#              #
#    Updated: 2025/05/01 22:27:20 by kguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c list.c rank.c utils.c moves.c lownumsort.c

OBJS = ${SRC:.c=.o}

%.o: %.c
		$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

NAME = push_swap.a

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

INC_DIR = .

CPPFLAGS = -I $(INC_DIR) -I ft_printf -I ft_printf/libft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@make -C ft_printf
		$(CC) $(CCFLAGS) -g $(OBJS) ft_printf/libftprintf.a ft_printf/libft/libft.a -o pushswap

clean:
		$(RM) $(OBJS)
		@make -C ft_printf clean

fclean: clean
		$(RM) pushswap
		@make -C ft_printf fclean
re: fclean all

.PHONY: all clean fclean re
