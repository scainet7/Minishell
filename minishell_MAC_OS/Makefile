# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <snino@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 17:57:38 by snino             #+#    #+#              #
#    Updated: 2022/08/27 16:58:37 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= minishell

CC 				:= gcc

HEADER 			:= minishell.h

CFLAGS 			:= -g -Wall -Wextra -Werror

FLAGS_RL		:=	-I /Users/$(USER)/.brew/opt/readline/include -lreadline

LIB				:=	libft/

OBJ_DIR			:=	obj

SRCS 			:=	minishell.c			ft_lexer.c				ft_parser.c\
					ft_utils_pars.c		ft_utils_lexer.c		ft_utils_lexer2.c\
					ft_utils_show.c		ft_utils_proc.c			ft_proc.c\
					ft_path_utils.c		ft_utils_envp.c			ft_utils_redirect.c\
					ft_builtin.c		ft_utils_builtin.c		ft_pwd.c\
					ft_echo.c			ft_env.c				ft_cd.c\
					ft_exit.c			ft_unset.c				ft_utils_print_export.c\
					ft_signal.c			ft_export.c				ft_utils_pars_dollar.c\
					ft_user_pars.c\

OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

.PHONY			:	all clean makelibft fclean re

all				:	makelibft $(NAME)

makelibft		:
					@make -C $(LIB) all

$(NAME)			:	$(HEADER) $(OBJ)
					$(CC) $(CFLAGS) $(FLAGS_RL) $(OBJ) $(LIB)libft.a -o $(NAME)

$(OBJ_DIR)/%.o	:	%.c	$(HEADER)
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@ -I .

clean			:
					@rm -rf $(OBJ_DIR)
					@make -C $(LIB) clean

fclean			:	clean
					@$(RM) $(NAME)
					@make -C $(LIB) fclean

re				:	fclean all