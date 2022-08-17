/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 17:25:19 by snino            ###   ########.fr       */
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

# define P_IN 1
# define P_OUT 0

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
	int		error;
	int		num_cmd;
	int		*pids;
	char	*line;

}		t_mini;

void	add_history(char *line);

t_cmd	*ft_cmd_new(void *cmd);
t_list	*find_variable(t_list *var, char *line);
int		ft_memory_num(t_list *words_list, char *symbol, int len);
void	free_tcmd(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);

int		ft_lexer(t_mini *mini);
int		ft_parser(t_mini *mini);
int		ft_check_symbol(char *line);
int		ft_check_redirect_flag(t_mini *mini, char *cmd);
int		ft_pars_error(t_mini *mini, char *file, int error);
char	*ft_pars_dollar(char *str);
char	*ft_pars_envp(t_mini *mini, char *str);
char	*ft_pars_words(t_mini *mini, char *line);
char	*ft_pars_star_and(t_mini *mini, char *line);
char	*ft_pars_symb(t_mini *mini, char *line, char c);
char	*ft_pars_quotes(t_mini *mini, char *line, char c);
char	*ft_check_dollar(t_mini *mini, char *str, char *buff);
void	ft_redirect(t_cmd *cmdd, int *p);
void	ft_pars_redirect_left(t_mini *mini, t_cmd *tmp, int i);
void	ft_pars_redirect_right(t_mini *mini, t_cmd *tmp, int i);

int		ft_proc(t_mini *mini);
char	**ft_exctract_envp(t_mini *mini);
void	ft_add_pids(t_mini *mini);
void	change_errno(t_mini *mini);

void	ft_find_path(char **cmd, char **env);
void	ft_free(char **paths);

void	show(t_list *list, char *place);
void	show1(t_cmd *cmd, char *place);
#endif