/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/09 18:16:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
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

typedef struct s_comand
{
	char			**comand;
	int				fd[2];
	struct s_comand	*next;
}	t_cmd;

typedef struct s_minishell
{
//	t_builtin_ptr	f_ptrs[7];
	t_list			*envp_list;
	t_list			*words_list;
	t_cmd 			*cmd;

	int				exit_flag;
	char			*line;
	char			*user;
}		t_mini;

t_cmd	*ft_cmd_new(void *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
int		ft_memory_num(t_list *words_list);

void	add_history(char *line);
void	ft_freelst(t_list *lst);
void	ft_change_var(t_mini *mini, char *envp);
int		ft_memory_num(t_list *words_list);
void	ft_parser(t_mini *mini);
void 	*ft_pars_quotes(t_mini *mini, char *line);
void	ft_parser1(t_mini *mini);
void	ft_parser2(t_mini *mini);
char	*ft_pars_cmd(t_mini *mini, char *line);
char	*ft_pars_words1(t_mini *mini, char *line);
char	*ft_pars_words2(t_mini *mini, char *line);
char	*ft_pars_words3(t_mini *mini, char *line);
char	*ft_pars_words4(t_mini *mini, char *line);
char	*ft_pars_words5(t_mini *mini, char *line);
char	*ft_pars_words6(t_mini *mini, char *line);
char	*ft_pars_words7(t_mini *mini, char *line);
int		ft_check_symbol(char *line);
void	SHOW1(t_cmd *cmd);
void 	SHOW(t_mini *mini);
#endif