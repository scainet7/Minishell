/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/15 15:35:47 by snino            ###   ########.fr       */
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
	t_list	*envp_list;
	t_list	*words_list;
	t_list	*words_list_mod;
	t_cmd	*cmd;

	int		exit_flag;
	char	*line;
	int		error;
}		t_mini;

t_cmd	*ft_cmd_new(void *cmd);
void	free_tcmd(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
int		ft_memory_num(t_list *words_list, char *symbol, int len);

void	add_history(char *line);
void	ft_freelst(t_list *lst);

void	ft_lexer(t_mini *mini);
void	*ft_lex_quotes(t_mini *mini, char *line);
char	*ft_pars_words(t_mini *mini, char *line);
char	*ft_pars_quotes(t_mini *mini, char *line, char c);
char	*ft_pars_symb(t_mini *mini, char *line, char c);
char	*ft_pars_star_and(t_mini *mini, char *line);
int		ft_check_symbol(char *line);

void	ft_lexer2(t_mini *mini);
char	*ft_check_dollar(t_mini *mini, char *str, char *buff);
char	*ft_split_dollar(t_mini *mini, char *str, char *buff);
char	*ft_join_dollar(t_list *list);
char	*ft_pars_dollar(char *str);
char	*ft_pars_envp(t_mini *mini, char *str);

void	ft_parser(t_mini *mini);

void	show(t_list *list, char *place);
void	show1(t_cmd *cmd, char *place);
#endif