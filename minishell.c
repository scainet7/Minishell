/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:04:48 by snino             #+#    #+#             */
/*   Updated: 2022/08/17 17:09:41 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_line_lst_cmd(t_mini *mini)
{
	if (mini->line && *mini->line != '\0')
		change_errno(mini);
	if (mini->error == 0 || mini->error == 3)
	{
		ft_freelst(mini->words_list);
		ft_freelst(mini->words_list_mod);
		free_tcmd(mini->cmd);
		if (mini->pids)
			free(mini->pids);
	}
	else if (mini->error == 1)
		ft_freelst(mini->words_list);
	else if (mini->error == 2)
	{
		ft_freelst(mini->words_list);
		ft_freelst(mini->words_list_mod);
	}
	mini->pids = NULL;
	mini->error = 0;
}

static void	check_var(t_list *var)
{
	if (!find_variable(var, "PWD"))
		ft_lstadd_back(&var, ft_lstnew(ft_strdup("PWD")));
	if (!find_variable(var, "OLDPWD"))
		ft_lstadd_back(&var, ft_lstnew(ft_strdup("OLDPWD")));
	if (!find_variable(var, "SHLVL"))
		ft_lstadd_back(&var, ft_lstnew(ft_strdup("SHLVL=1")));
}

static void	ft_change_var(t_mini *mini, char *envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!ft_memcmp(envp, "OLDPWD=", 7))
		envp = ft_strdup("OLDPWD");
	else if (!ft_memcmp(envp, "SHLVL=", 6))
		envp = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(envp + 6) + 1), 3);
	else if (!ft_memcmp(envp, "PATH=", 5) \
			&& !ft_strnstr(envp, pwd, ft_strlen(envp)))
	{
		envp = ft_strjoin(envp, ":");
		envp = ft_strjoin_free(envp, getcwd(NULL, 1024), 6);
	}
	else
		envp = ft_strdup(envp);
	ft_lstadd_back(&mini->envp_list, ft_lstnew(envp));
	free(pwd);
}

static void	ft_init(t_mini *mini, char **envp)
{
	int	i;

	i = 0;
	mini->exit_flag = 1;
	mini->envp_list = ft_lstnew(ft_strdup(envp[i]));
	while (envp[++i])
		ft_change_var(mini, envp[i]);
	check_var(mini->envp_list);
	if (!find_variable(mini->envp_list, "?"))
	{
		ft_lstadd_back(&mini->envp_list, ft_lstnew(ft_strdup("?=0")));
		ft_lstlast(mini->envp_list)->flag = -1;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void)argc;
	(void)argv;
	ft_init(&mini, envp);
	while (mini.exit_flag)
	{
		rl_replace_line("", 0);
		mini.line = readline(MAG"username@minishell "END);
		if (mini.line && *mini.line)
			add_history(mini.line);
		if (!mini.line)
		{
			mini.exit_flag = 0;
			printf("%s"BLU"exit\n"END, MAG"username@minishell "END);
		}
		if (mini.line && *mini.line)
			if (!ft_lexer(&mini) && !ft_parser(&mini) && !mini.error)
				ft_move_proc(&mini);
		if (mini.line && *mini.line)
			ft_free_line_lst_cmd(&mini);
		free(mini.line);
	}
	ft_freelst(mini.envp_list);
	return (0);
}

//show(mini.envp_list, "main: ");
//show(mini.words_list, "lexer: ");
//show(mini.words_list_mod, "lexer2: ");
//show1(mini.cmd, "main: ");