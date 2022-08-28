# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 16:23:18 by snino             #+#    #+#              #
#    Updated: 2022/08/27 17:50:30 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a

SRCS			:=	ft_isalnum.c			ft_isprint.c		ft_memcmp.c\
			 		ft_putchar_fd.c			ft_split.c			ft_strlcat.c\
			 		ft_strncmp.c			ft_substr.c 		ft_atoi.c\
			 		ft_isalpha.c			ft_itoa.c			ft_memcpy.c\
			 		ft_putendl_fd.c			ft_strchr.c			ft_strlcpy.c\
			 		ft_strnstr.c			ft_tolower.c		ft_bzero.c\
					ft_isascii.c			ft_striteri.c		ft_memmove.c\
					ft_putnbr_fd.c			ft_strdup.c			ft_strlen.c\
					ft_strrchr.c			ft_toupper.c		ft_calloc.c\
					ft_isdigit.c			ft_memchr.c			ft_memset.c\
					ft_putstr_fd.c  		ft_strjoin.c		ft_strmapi.c\
					ft_strtrim.c			get_next_line.c		get_next_line_utils.c\
					ft_lstadd_back.c		ft_lstadd_front.c	ft_lstclear.c\
					ft_lstdelone.c			ft_lstiter.c		ft_lstlast.c\
					ft_lstmap.c				ft_lstnew.c			ft_strjoin_free.c\
					ft_strcdup.c			ft_getword_mod.c	ft_strcat.c\
					ft_freelst.c			ft_lstsize.c\

OBJ_DIR 		:=	obj

HEADER			:= 	libft.h

OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

CC				:= 	gcc

CFLAGS			:=	-Wall -Wextra -Werror

.PHONY			:	all clean fclean re bonus

all				:	$(NAME)

$(NAME)			:	$(OBJ) $(HEADER)
					ar rcs $(NAME) $?

$(OBJ_DIR)/%.o	:	%.c	$(HEADER)
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@ -I .

clean			:
					@rm -rf $(OBJ_DIR)

fclean			:	clean
					@$(RM) $(NAME)

re				:	fclean all