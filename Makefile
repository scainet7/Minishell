# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <snino@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 17:57:38 by snino             #+#    #+#              #
#    Updated: 2022/08/22 20:06:27 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

CC := gcc

HEADER := minishell.h

CFLAGS := -g -lreadline -Wall -Wextra -Werror

LIB		=	libft/libft.a

SRCS :=		minishell.c			ft_lexer.c				ft_parser.c\
			ft_utils_pars.c		ft_utils_lexer.c		ft_utils_lexer2.c\
			ft_utils_show.c		ft_utils_proc.c			ft_proc.c\
			ft_path_utils.c		ft_utils_envp.c			ft_utils_redirect.c\
			ft_builtin.c		ft_utils_builtin.c		ft_pwd.c\
			ft_echo.c			ft_env.c				ft_cd.c\
			ft_exit.c			ft_unset.c				ft_export.c\
			ft_signal.c			ft_utils_print_export.c	ft_utils_pars_dollar.c\

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