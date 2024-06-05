# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:06:26 by mtigunit          #+#    #+#              #
#    Updated: 2022/12/17 19:48:43 by mtigunit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CKECKER	= checker
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= Radix_algo.c instructions.c lst_funcs.c utils.c check_error.c mini_sort.c
OBJ		= Radix_algo.o instructions.o lst_funcs.o utils.o check_error.o mini_sort.o

%.o:%.c push_swap.h
	$(CC) -c $(CFLAGS) $<

all: $(NAME)

$(NAME): $(OBJ) push_swap.o
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) push_swap.o ./libft/libft.a -o $(NAME)

bonus: $(OBJ) checker.o
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) checker.o ./libft/libft.a -o $(CKECKER)

clean:
	@$(MAKE) clean -C ./libft
	rm -f $(OBJ) checker.o push_swap.o

fclean: clean
	@$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(CKECKER)

re: fclean all