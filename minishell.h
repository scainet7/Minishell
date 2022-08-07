/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/07 21:33:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

typedef struct s_minishell
{
//	t_builtin_ptr	f_ptrs[7];
	t_list			*envp_list;
	t_list			*com_list;
	t_list			*words_list;

	int				exit_flag;
	char			*line;
	char			*user;
}		t_mini;

void	add_history(char *line);
void	ft_freelst(t_list *lst);
void	ft_change_var(t_mini *mini, char *envp);
void	ft_parser(t_mini *mini);
char	*ft_pars_cmd(t_mini *mini, char *line);
char	*ft_pars_words1(t_mini *mini, char *line);
char	*ft_pars_words2(t_mini *mini, char *line);
int		ft_check_symbol(char line);
#endif