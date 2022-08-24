cmake_minimum_required(VERSION 3.21)
project(minishell_snino C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell_snino minishell.c minishell.h libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c
        libft/ft_isalpha.c libft/libft.h libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c
        libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c
        libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strlcat.c
        libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c
        libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c
        libft/get_next_line_utils.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c
        libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_strjoin_free.c ft_lexer.c ft_parser.c ft_utils_pars.c ft_utils_lexer.c ft_utils_lexer2.c libft/ft_strcdup.c libft/ft_getword_mod.c libft/ft_strcat.c ft_utils_pars_dollar.c libft/ft_freelst.c ft_utils_show.c ft_proc.c ft_utils_proc.c ft_utils_envp.c ft_path_utils.c ft_utils_redirect.c ft_builtin.c ft_utils_builtin.c ft_pwd.c ft_echo.c ft_env.c ft_cd.c ft_exit.c ft_unset.c ft_export.c ft_utils_print_export.c ft_signal.c)
