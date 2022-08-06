/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/05 20:37:34 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# define BLU "\033[34m"
# define GRE "\033[32m"
# define RED "\033[31m"
# define END "\033[0m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft/libft.h"
# include <signal.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>

//typedef struct	s_minishell	t_mini;
//typedef int		(*t_builtin_ptr)(t_list *, t_mini*);
//typedef struct	s_comand
//{
//
//}	t_cmd;

typedef struct s_minishell
{
//	t_builtin_ptr	f_ptrs[7];
	t_list			*envp_list;
	t_list			*com_list;
	t_list			*words_list;
	t_list			*var;

	int 			exit_flag;
	char			*line;
	int 			flag1;
	int 			flag2;
	int 			flag3;
	int 			flag4;
} t_mini;

void	add_history(char *line);
void	ft_freelst(t_list *lst);
void	ft_change_var(t_mini *mini, char *envp);
int 	ft_lexer(t_mini *mini);
#endif