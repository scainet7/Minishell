/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:57:21 by snino             #+#    #+#             */
/*   Updated: 2022/08/28 15:44:38 by snino            ###   ########.fr       */
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
# define P_IN 1
# define P_OUT 0

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
	int		error;
	int		num_cmd;
	int		*pids;
	char	*line;
	char	*home;
	char	*username;
}		t_mini;
//signal
void	ft_signal(void);
void	ft_handler(int sig);
void	add_history(char *line);
void	ft_child_handler(int sig);
void	ft_username_pars(t_mini *mini);
//utils_pars_cmd
t_cmd	*ft_cmd_new(void *cmd);
t_list	*ft_search_envp(t_list *var, char *line);
int		ft_memory_num(t_list *words_list, char *symbol, int len);
void	free_tcmd(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
//lexer_lexer2_parser
int		ft_lexer(t_mini *mini);
int		ft_parser(t_mini *mini);
int		ft_check_symbol(char *line);
int		ft_check_redirect_flag(t_mini *mini, char *cmd);
int		ft_pars_error(t_mini *mini, char *file, int error);
char	*ft_pars_dollar(char *str);
char	*ft_pars_envp(t_mini *mini, char *str);
char	*ft_pars_words(t_mini *mini, char *line);
char	*ft_pars_symb(t_mini *mini, char *line, char c);
char	*ft_pars_quotes(t_mini *mini, char *line, char c);
char	*ft_check_dollar(t_mini *mini, char *str, char *buff);
void	ft_redirect(t_cmd *cmdd, int *p);
void	ft_check_flag(t_mini *mini, t_list *list);
void	ft_check_space(t_mini *mini, t_list *list);
void	ft_pars_redirect_left(t_mini *mini, t_cmd *tmp, int i);
void	ft_pars_redirect_right(t_mini *mini, t_cmd *tmp, int i);
//functions_execve_and_builtins
int		ft_proc(t_mini *mini);
int		ft_check_builtin(t_cmd *cmd);
char	**ft_exctract_envp(t_mini *mini);
void	ft_pwd(t_mini *mini, t_cmd *cmd);
void	ft_free(char **paths);
void	ft_add_pids(t_mini *mini);
void	change_errno(t_mini *mini);
void	ft_cd(t_mini *mini, t_cmd *cmd);
void	ft_env(t_mini *mini, t_cmd *cmd);
void	ft_exit(t_mini *mini, t_cmd *cmd);
void	ft_echo(t_mini *mini, t_cmd *cmd);
void	ft_unset(t_mini *mini, t_cmd *cmd);
void	ft_export(t_mini *mini, t_cmd *cmd);
void	ft_find_path(t_mini *mini, char **cmd, char **env);
void	ft_print_export(t_mini *mini, int fd);
void	ft_builtin(t_mini *mini, t_cmd *cmd, int *pipe_fd);
//show_functions
void	show(t_list *list, char *place);
void	show1(t_cmd *cmd, char *place);
#endif