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

CFLAGS 			:= -g #-Wall -Wextra -Werror

LIBFT_A			:=	libft.a

LIBF_DIR		:=	libft/

LIBFT			:=	$(addprefix $(LIBF_DIR), $(LIBFT_A))

FLAGS_RL		:=	-I /Users/$(USER)/.brew/opt/readline/include -lreadline

SRCS 			:=	ft_cd.c\
					ft_env.c\
					ft_pwd.c\
					ft_echo.c\
					ft_exit.c\
					ft_proc.c\
					ft_unset.c\
					ft_lexer.c\
					ft_parser.c\
					ft_signal.c\
					ft_export.c\
					minishell.c\
					ft_builtin.c\
					ft_user_pars.c\
					ft_utils_pars.c\
					ft_utils_show.c\
					ft_utils_proc.c\
					ft_utils_envp.c\
					ft_utils_lexer.c\
					ft_path_utils.c	\
					ft_utils_lexer2.c\
					ft_utils_builtin.c\
					ft_utils_redirect.c\
					ft_utils_pars_dollar.c\
					ft_utils_print_export.c\

HEADER 			:= minishell.h

OBJ_DIR			:=	obj

OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

.PHONY			:	all clean makelibft fclean re

all				:	$(NAME)

$(NAME)			:	$(HEADER) $(OBJ)
					@make -C $(LIBF_DIR)
					$(CC) $(CFLAGS)  $(OBJ) $(LIBFT) -o $(NAME) $(FLAGS_RL)

$(OBJ_DIR)/%.o	:	%.c	$(HEADER)
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@ -I .

clean			:
					@rm -rf $(OBJ)
					@make -C $(LIBF_DIR) clean

fclean			:	clean
					@$(RM) $(NAME)
					@rm -rf obj
					@make -C $(LIBF_DIR) fclean

re				:	fclean all