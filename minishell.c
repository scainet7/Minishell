/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <snino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:04:48 by snino             #+#    #+#             */
/*   Updated: 2022/08/04 22:25:29 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_change_var(t_mini *mini, char *envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 1024);
	if (!ft_memcmp(envp, "OLDPWD=", 7))
		envp = ft_strdup("OLDPWD");
	else if (!ft_memcmp(envp, "SHLVL=", 6))
		envp = ft_strjoin_free("SHLVL=", ft_itoa(ft_atoi(envp + 6) + 1), 3);
	else if (!ft_memcmp(envp, "PATH=", 5) && \
	!ft_strnstr(envp, pwd, ft_strlen(envp)))
	{
		envp = ft_strjoin(envp, ":");
		envp = ft_strjoin_free(envp, getcwd(NULL, 1024), 6);
	}
	else
		envp = ft_strdup(envp);
	ft_lstadd_back(&mini->var, ft_lstnew(envp));
	free(pwd);
}

void ft_init(t_mini *mini, char **envp)
{
	int	i;

	i = 0;
	mini->exit = 1;
	//mini->err = 0;
	mini->var = ft_lstnew(ft_strdup(envp[i]));
	while(envp[++i])
		printf("%s\n", envp[i]);
	i = 0;
	while(envp[++i])
		ft_change_var(mini, envp[i]);
	char *str;
	i = 0;
	while (mini-> var != NULL)
	{
		str = mini->var->content;
		printf("%d ", i);
		printf("\033[31m%s\033[0m\n", str);
		mini->var = mini->var->next;
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_mini mini;

	(void)argc;
	(void)argv;
	ft_init(&mini, envp);

	while(mini.exit)
	{
		rl_replace_line("", 0);
		mini.line = readline(GRE"snino_shell$ "END);
//		printf( "%s\n", mini.line);
		if (mini.line && *mini.line)
			add_history(mini.line);
		if (!mini.line)
		{
			mini.exit = 0;
			ft_putstr_fd(GRE"snino_shell$ "END BLU"exit\n"END, 1);
		}
	}
	ft_freelst(mini.var);
	return 0;
}