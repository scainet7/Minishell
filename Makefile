# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <snino@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 13:17:31 by snino             #+#    #+#              #
#    Updated: 2022/08/04 18:00:14 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

CC := gcc

HEADER := minishell.h

CFLAGS := -g -lreadline -Wall -Wextra -Werror

LIB		=	libft/libft.a

SRCS :=		minishell.c		ft_free.c\

OBJ := $(SRCS:%.c=%.o)

.PHONY:		all	clean	fclean	re	libft

all :	libft $(NAME) $(NAME_BONUS)

libft:
		@$(MAKE) -C libft/

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) $(LIB) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS)  -c $< -o $@ -I .

clean:
	@$(MAKE) -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft/ fclean
	rm -rf $(NAME)

re: fclean all